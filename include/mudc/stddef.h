/* stddef.h */

/* Header */
#ifndef MUDC_INCLUDE_STDDEF_H
#define MUDC_INCLUDE_STDDEF_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN

/* Standard Library */
#include <stddef.h>

/* MudC */
#include "option.h"


OPTION_TYPEDEF(OptSize, size_t);
OPTION_TYPEDEF(OptPtrDiff, ptrdiff_t);
OPTION_TYPEDEF(OptMaxAlign, max_align_t);
OPTION_TYPEDEF(OptWChar, wchar_t);

#ifdef __STDC_WANT_LIB_EXT1__
OPTION_TYPEDEF(OptRSize, rsize_t);
#endif


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_STDDEF_H */

/* Implementation */
#ifdef MUDC_STDDEF_IMPLEMENTATION
#endif /* MUDC_STDDEF_IMPLEMENTATION */
