/* allocator_libc.h */

/* Header */
#ifndef MUDC_INCLUDE_ALLOCATOR_LIBC_H
#define MUDC_INCLUDE_ALLOCATOR_LIBC_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN

/* MudC */
#include "allocator.h"


AllocFn alloc_libc;
FreeFn free_libc;
CallocFn calloc_libc;
ReallocFn realloc_libc;
AlignedAllocFn aligned_alloc_libc;

Allocator allocator_libc(void);



MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_ALLOCATOR_LIBC_H */

/* Implementation */
#ifdef MUDC_ALLOCATOR_LIBC_IMPLEMENTATION

/* Standard Library */
#include <stddef.h>
#include <stdlib.h>


Allocator allocator_libc(void) {
  return (Allocator) {
    .data = NULL,
    .alloc = alloc_libc,
    .free = free_libc,
    .aligned_alloc = alligned_alloc,
    .calloc = calloc_libc,
    .realloc = realloc_libc
  };
}

void *alloc_libc(Allocator *self, size_t size) {
  MUDC_UNUSED(self);
  return malloc(size);
}

void free_libc(Allocator *self, void *ptr) {
  MUDC_UNUSED(self);
  free(ptr);
}

void *calloc_libc(Allocator *self, size_t num, size_t size) {
  MUDC_UNUSED(self);
  return calloc(num, size);
}

void *realloc_libc(Allocator *self, void *ptr, size_t size) {
  MUDC_UNUSED(self);
  return realloc(ptr, size);
}

void *aligned_alloc_libc(Allocator *self, size_t alignment, size_t size) {
  MUDC_UNUSED(self);
  return aligned_alloc(alignment, size);
}


#endif /* MUDC_ALLOCATOR_LIBC_IMPLEMENTATION */
