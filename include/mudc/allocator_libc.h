/* allocator_libc.h */

/* Header */
#ifndef MUDC_INCLUDE_ALLOCATOR_LIBC_H
#define MUDC_INCLUDE_ALLOCATOR_LIBC_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN

/* MudC */
#include "allocator.h"


MUDC_DEF AllocFn alloc_libc;
MUDC_DEF FreeFn free_libc;
MUDC_DEF CallocFn calloc_libc;
MUDC_DEF ReallocFn realloc_libc;
MUDC_DEF AlignedAllocFn aligned_alloc_libc;

MUDC_DEF Allocator allocator_libc(void);



MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_ALLOCATOR_LIBC_H */

/* Implementation */
#ifdef MUDC_ALLOCATOR_LIBC_IMPLEMENTATION

/* Standard Library */
#include <stddef.h>
#include <stdlib.h>


MUDC_DEF Allocator allocator_libc(void) {
  return (Allocator) {
    .data = NULL,
    .alloc = alloc_libc,
    .free = free_libc,
    .aligned_alloc = aligned_alloc_libc,
    .calloc = calloc_libc,
    .realloc = realloc_libc
  };
}

MUDC_DEF AllocError alloc_libc(
    Allocator *restrict self,
    void **restrict dest,
    size_t size
) {
  MUDC_UNUSED(self);
  *dest = malloc(size);
  return *dest ? AllocSuccess : AllocFailure;
}

MUDC_DEF void free_libc(Allocator *restrict self, void *restrict ptr) {
  MUDC_UNUSED(self);
  free(ptr);
}

MUDC_DEF AllocError calloc_libc(
    Allocator *restrict self,
    void **restrict dest,
    size_t num,
    size_t size
) {
  MUDC_UNUSED(self);
  *dest = calloc(num, size);
  return *dest ? AllocSuccess : AllocFailure;
}

MUDC_DEF AllocError realloc_libc(
    Allocator *restrict self,
    void **restrict dest,
    void *restrict ptr,
    size_t size
) {
  MUDC_UNUSED(self);
  *dest = realloc(ptr, size);
  return *dest ? AllocSuccess : AllocFailure;
}

MUDC_DEF AllocError aligned_alloc_libc(
    Allocator *restrict self,
    void **restrict dest,
    size_t alignment,
    size_t size
) {
  MUDC_UNUSED(self);
  *dest = aligned_alloc(alignment, size);
  return *dest ? AllocSuccess : AllocFailure;
}


#endif /* MUDC_ALLOCATOR_LIBC_IMPLEMENTATION */
