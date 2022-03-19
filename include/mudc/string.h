/* string.h */

/* Header */
#ifndef MUDC_INCLUDE_STRING_H
#define MUDC_INCLUDE_STRING_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN

/* Standard Library */
#include <stddef.h>

/* MudC */
#include "allocator.h"
#include "option.h"


typedef struct StrBuf {
  char *data;
  size_t length;
  size_t capacity;
  Allocator allocator;
} StrBuf;
OPT_TYPEDEF(OptStrBuf, StrBuf);
OPT_TYPEDEF(OptStrBufPtr, StrBuf *);

typedef struct Str {
  char *data;
  size_t length;
} Str;
OPT_TYPEDEF(OptStr, Str);
OPT_TYPEDEF(OptStrPtr, Str *);

/* StrBuf functions */

MUDC_DEF OptStrBuf strbuf_alloc(Allocator a, size_t const capacity);

#define strbuf_new(a, capacity, strlike) _Generic(strlike, \
    char *: strbuf_new_cstr(a, capacity, strlike), \
    char const *: strbuf_new_cstr(a, capacity, strlike), \
    StrBuf: strbuf_new_strbuf(a, capacity, strlike), \
    Str: strbuf_new_str(a, capacity, strlike)
MUDC_DEF OptStrBuf strbuf_new_cstr(
    Allocator a,
    size_t const capacity,
    char const *const cstr
);
MUDC_DEF OptStrBuf strbuf_new_strbuf(
    Allocator a,
    size_t const capacity,
    StrBuf strbuf
);
MUDC_DEF OptStrBuf strbuf_new_str(
    Allocator a,
    size_t const capacity,
    Str const str
);

MUDC_DEF void strbuf_free(StrBuf *strbuf);

/* Non-destructively expand the capacity by allocating new
 * capacity first, copying, then freeing old unused (or by
 * using realloc if available) */
MUDC_DEF int strbuf_expand(StrBuf *strbuf, size_t s);

/* Non-destructively trim the unused capacity by allocating
 * appropriate size first, copying, then freeing old unused
 * (or by using realloc if available) */
MUDC_DEF int strbuf_trim(StrBuf *strbuf);

MUDC_DEF void strbuf_append(StrBuf *strbuf, Str s);

/* Str functions */

#define str_new(strlike) _Generic(strlike, \
    char *: str_new_cstr(strlike), \
    char const *: str_new_cstr(strlike), \
    StrBuf: str_new_strbuf(strlike), \
    Str: str_new_str(strlike)
MUDC_DEF Str str_new_cstr(char const *const cstr);
MUDC_DEF Str str_new_strbuf(StrBuf const strbuf);
MUDC_DEF Str str_new_str(Str const str);


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_STRING_H */

/* Implementation */
#ifdef MUDC_STRING_IMPLEMENTATION

/* Standard Library */
#include <string.h>


/* StrBuf functions */

MUDC_DEF OptStrBuf strbuf_alloc(Allocator a, size_t const capacity) {
  if (!a.alloc || !a.free) return NONE;

  StrBuf result = { .capacity = capacity, .allocator = a };
  if (result.a.alloc(result.a, &result.data, capacity)) return NONE;

  return SOME(result);
}

MUDC_DEF OptStrBuf strbuf_new_cstr(
    Allocator a,
    size_t const capacity,
    char const *const cstr
) {
  if (!a.alloc || !a.free || !cstr) return NONE;
  size_t cstr_len = strlen(cstr);
  if (capacity < cstr_len) return NONE;

  StrBuf result = { .length = cstr_len, .capacity = capacity, .allocator = a };
  if (result.a.alloc(result.a, &result.data, capacity)) return NONE;
  memcpy(&result.data, cstr, cstr_len);

  return SOME(result);
}

MUDC_DEF OptStrBuf strbuf_new_strbuf(
    Allocator a,
    size_t const capacity,
    StrBuf strbuf
) {
  if (!a.alloc || !a.free || capacity < strbuf.length) return NONE;
  StrBuf result = {
    .length = strbuf.length,
    .capacity = capacity,
    .allocator = a
  };
  if (result.a.alloc(result.a, &result.data, capacity)) return NONE;
  memcpy(&result.data, &strbuf.data, &strbuf.length);

  return SOME(result);
}

MUDC_DEF OptStrBuf strbuf_new_str(
    Allocator a,
    size_t const capacity,
    Str const str
) {
  if (!a.alloc || !a.free || capacity < str.length) return NONE;
  StrBuf result = {
    .length = str.length,
    .capacity = capacity,
    .allocator = a
  };
  if (result.a.alloc(result.a, &result.data, capacity)) return NONE;
  memcpy(&result.data, &str.data, &str.length);

  return SOME(result);
}

MUDC_DEF void strbuf_free(StrBuf *strbuf) {
  strbuf->a.free(&strbuf->a, strbuf->data);
  strbuf->data = NULL;
  strbuf->length = 0;
  strbuf->capacity = 0;
}

MUDC_DEF int strbuf_expand(StrBuf *strbuf, size_t s) {
  if (!strbuf) return 1;
  Allocator a = strbuf->allocator;

  char *new_data;
  if (a.realloc && strbuf->capacity > 0) {
    if (a.realloc(a, &new_data, strbuf->data, strbuf->length + s)) return 1;
    memcpy(a->data, new_data, strbuf->length);
  }
  else {
    if (a.malloc(a, &new_data, strbuf->length + s)) return 1;
    memcpy(new_data, a->data, strbuf->length);
    a.free(a, strbuf->data);
    strbuf->data = new_data;
  }
  strbuf->capacity += s;

  return 0;
}

MUDC_DEF int strbuf_trim(StrBuf *strbuf) {
  if (!strbuf || strbuf->length == strbuf->capacity) return 1;
  Allocator a = strbuf->allocator;

  char *new_data;
  if (a.realloc) {
    if (a.realloc(a, &new_data, strbuf->data, strbuf->length)) return 1;
  }
  else {
    if (a.malloc(a, &new_data, strbuf->length)) return 1;
    memcpy(new_data, strbuf->data, strbuf->length);
    a.free(a, strbuf->data);
    strbuf->data = new_data;
  }
  strbuf->capacity = strbuf->length;

  return 0;
}

MUDC_DEF void strbuf_append(StrBuf *strbuf, StrBuf s) {
  if (!strbuf || !s.length) return;
  if (strbuf->length + s.length > strbuf->capacity) {
    // TODO: Decide if expansion should be by different default amount
    if (strbuf_expand(strbuf, s.length)) return;
    strbuf->capacity++;
  }
  memcpy(strbuf->data + strbuf->length, s.data, s.length);
  strbuf->length += s.length;
}

/* Str functions */

MUDC_DEF Str str_new_cstr(char const *const cstr) {
  return (Str) { .data = cstr, .length = cstr ? strlen(cstr) : 0 };
}

MUDC_DEF Str str_new_strbuf(StrBuf const strbuf) {
  return (Str) { .data = strbuf.data, .length = strbuf.length };
}

MUDC_DEF Str str_new_str(Str const str) {
  return (Str) { .data = str.data, .length = str.length };
}


#endif /* MUDC_STRING_IMPLEMENTATION */
