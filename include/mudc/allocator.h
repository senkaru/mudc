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


typedef enum AllocError {
  AllocSuccess = 0,
  AllocFailure = 1
} AllocError;
OPT_TYPEDEF(OptAllocError, AllocError);
OPT_TYPEDEF(OptAllocErrorPtr, AllocError *);

typedef struct Allocator Allocator;

typedef AllocError AllocFn(
    Allocator self,
    void **dest,
    size_t size
);
typedef void FreeFn(Allocator self, void *ptr);
typedef AllocError AlignedAllocFn(
    Allocator self,
    void **dest,
    size_t alignment,
    size_t size
);
typedef AllocError CallocFn(
    Allocator self,
    void **dest,
    size_t num,
    size_t size
);
typedef AllocError ReallocFn(
    Allocator self,
    void **restrict dest,
    void *restrict ptr,
    size_t size
);

struct Allocator {
  void *data;
  AllocFn *alloc;
  FreeFn *free;
  AlignedAllocFn *aligned_alloc;
  CallocFn *calloc;
  ReallocFn *realloc;
};
OPT_TYPEDEF(OptAllocator, Allocator);
OPT_TYPEDEF(OptAllocatorPtr, Allocator *);


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_ALLOCATOR_H */

/* Implementation */
#ifdef MUDC_ALLOCATOR_IMPLEMENTATION
#endif /* MUDC_ALLOCATOR_IMPLEMENTATION */
