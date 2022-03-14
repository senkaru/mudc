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

/* Str functions */

#define str_new(strlike) _Generic(strlike, \
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
#endif /* MUDC_STRING_IMPLEMENTATION */
