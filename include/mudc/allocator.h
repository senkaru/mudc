/* allocator.h */

/* Header */
#ifndef MUDC_INCLUDE_ALLOCATOR_H
#define MUDC_INCLUDE_ALLOCATOR_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN

/* Standard Library */
#include <stddef.h>

/* MudC */
#include "option.h"


typedef struct Allocator Allocator;

typedef void *(AllocFn)(Allocator *self, size_t size);
typedef void (FreeFn)(Allocator *self, void *ptr);
typedef void *(AlignedAllocFc)(Allocator *self, size_t alignment, size_t size);
typedef void *(CallocFn)(Allocator *self, size_t num, size_t size);
typedef void *(ReallocFn)(Allocator *self, void *ptr, size_t size);

struct Allocator {
  void *data;
  AllocFn *alloc;
  FreeFn *free;
  AlignedAllocFn *aligned_alloc;
  CallocFn *calloc;
  ReallocFn *realloc;
};
OPTION_TYPEDEF(OptAllocator, Allocator);
OPTION_TYPEDEF(OptAllocatorPtr, Allocator *);


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_ALLOCATOR_H */

/* Implementation */
#ifdef MUDC_ALLOCATOR_IMPLEMENTATION
#endif /* MUDC_ALLOCATOR_IMPLEMENTATION */
