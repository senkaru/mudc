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


OPT_TYPEDEF(OptSize, size_t);
OPT_TYPEDEF(OptPtrDiff, ptrdiff_t);
OPT_TYPEDEF(OptMaxAlign, max_align_t);
OPT_TYPEDEF(OptWChar, wchar_t);

#ifdef __STDC_WANT_LIB_EXT1__
OPT_TYPEDEF(OptRSize, rsize_t);
#endif


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_STDDEF_H */

/* Implementation */
#ifdef MUDC_STDDEF_IMPLEMENTATION
#endif /* MUDC_STDDEF_IMPLEMENTATION */
