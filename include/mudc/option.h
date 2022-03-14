/* option.h */

/* Header */
#ifndef MUDC_INCLUDE_OPTION_H
#define MUDC_INCLUDE_OPTION_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN


#define OPT_DEF(decl_name, type_name) \
  struct decl_name { \
    union { \
      _Bool valid; \
      _Bool some; \
    }; \
    union { \
      type_name data; \
      type_name value; \
    }; \
  }
#define OPT_TYPEDEF(decl_name, type_name) \
  typedef OPT_DEF(decl_name, type_name) decl_name

#define SOME(val) { .valid = 1, .data = val }
#define NONE { .valid = 0 }

#define IS_SOME(val) (val.valid != 0)
#define IS_NONE(val) (val.valid == 0)
#define OPT_UNWRAP(opt) opt.data

OPT_TYPEDEF(OptBool, _Bool);
OPT_TYPEDEF(OptBoolPtr, _Bool *);
OPT_TYPEDEF(OptVoidPtr, void *);
OPT_TYPEDEF(OptChar, char);
OPT_TYPEDEF(OptCharPtr, char *);
OPT_TYPEDEF(OptUChar, unsigned char);
OPT_TYPEDEF(OptUCharPtr, unsigned char *);
OPT_TYPEDEF(OptShort, short);
OPT_TYPEDEF(OptShortPtr, short *);
OPT_TYPEDEF(OptUShort, unsigned short);
OPT_TYPEDEF(OptUShortPtr, unsigned short *);
OPT_TYPEDEF(OptInt, int);
OPT_TYPEDEF(OptIntPtr, int *);
OPT_TYPEDEF(OptUInt, unsigned int);
OPT_TYPEDEF(OptUIntPtr, unsigned int *);
OPT_TYPEDEF(OptLong, long);
OPT_TYPEDEF(OptLongPtr, long *);
OPT_TYPEDEF(OptULong, unsigned long);
OPT_TYPEDEF(OptULongPtr, unsigned long *);
OPT_TYPEDEF(OptLongLong, long long);
OPT_TYPEDEF(OptLongLongPtr, long long *);
OPT_TYPEDEF(OptULongLong, unsigned long long);
OPT_TYPEDEF(OptULongLongPtr, unsigned long long *);
OPT_TYPEDEF(OptFloat, float);
OPT_TYPEDEF(OptFloatPtr, float *);
OPT_TYPEDEF(OptDouble, double);
OPT_TYPEDEF(OptDoublePtr, double *);
OPT_TYPEDEF(OptLongDouble, long double);
OPT_TYPEDEF(OptLongDoublePtr, long double *);

#ifndef __STDC_NO_COMPLEX__
OPT_TYPEDEF(OptFloatComplex, float _Complex);
OPT_TYPEDEF(OptFloatComplexPtr, float _Complex *);
OPT_TYPEDEF(OptDoubleComplex, double _Complex);
OPT_TYPEDEF(OptDoubleComplexPtr, double _Complex *);
OPT_TYPEDEF(OptLongDoubleComplex, long double _Complex);
OPT_TYPEDEF(OptLongDoubleComplexPtr, long double _Complex *);
#endif /* __STDC_NO_COMPLEX__ */

/*
 * NOTE: Optional imaginary types not declared here. Major compilers such as
 * GCC incorrectly define __STDC_IEC_559_COMPLEX__ despite not providing
 * imaginary type support, thus requiring the inclusion of the <complex.h>
 * header to check if imaginary types are properly supported. Therefore, if
 * optional imaginary types are desired, include the "mudc/complex.h" header.
 *
 * NOTE: "mudc/complex.h" is currently a work-in-progress header.
 */


MUDC_CPP_GUARD_END
#endif /* MUDC_INCLUDE_OPTION_H */

/* Implementation */
#ifdef MUDC_OPTION_IMPLEMENTATION
#endif /* MUDC_OPTION_IMPLEMENTATION */
