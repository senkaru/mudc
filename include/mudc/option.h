/* option.h */

/* Header */
#ifndef MUDC_INCLUDE_OPTION_H
#define MUDC_INCLUDE_OPTION_H
#include "mudc_internal.h"
MUDC_CPP_GUARD_BEGIN


#define OPTION_DEF(decl_name, type_name) \
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
#define OPTION_TYPEDEF(decl_name, type_name) \
  typedef OPTION_DEF(decl_name, type_name) decl_name

#define SOME(val) { .valid = 1, .data = val }
#define NONE { .valid = 0 }

#define IS_SOME(val) (val.valid != 0)
#define IS_NONE(val) (val.valid == 0)
#define OPTION_UNWRAP(opt) opt.data

OPTION_TYPEDEF(OptBool, _Bool);
OPTION_TYPEDEF(OptBoolPtr, _Bool *);
OPTION_TYPEDEF(OptVoidPtr, void *);
OPTION_TYPEDEF(OptChar, char);
OPTION_TYPEDEF(OptCharPtr, char *);
OPTION_TYPEDEF(OptUChar, unsigned char);
OPTION_TYPEDEF(OptUCharPtr, unsigned char *);
OPTION_TYPEDEF(OptShort, short);
OPTION_TYPEDEF(OptShortPtr, short *);
OPTION_TYPEDEF(OptUShort, unsigned short);
OPTION_TYPEDEF(OptUShortPtr, unsigned short *);
OPTION_TYPEDEF(OptInt, int);
OPTION_TYPEDEF(OptIntPtr, int *);
OPTION_TYPEDEF(OptUInt, unsigned int);
OPTION_TYPEDEF(OptUIntPtr, unsigned int *);
OPTION_TYPEDEF(OptLong, long);
OPTION_TYPEDEF(OptLongPtr, long *);
OPTION_TYPEDEF(OptULong, unsigned long);
OPTION_TYPEDEF(OptULongPtr, unsigned long *);
OPTION_TYPEDEF(OptLongLong, long long);
OPTION_TYPEDEF(OptLongLongPtr, long long *);
OPTION_TYPEDEF(OptULongLong, unsigned long long);
OPTION_TYPEDEF(OptULongLongPtr, unsigned long long *);
OPTION_TYPEDEF(OptFloat, float);
OPTION_TYPEDEF(OptFloatPtr, float *);
OPTION_TYPEDEF(OptDouble, double);
OPTION_TYPEDEF(OptDoublePtr, double *);
OPTION_TYPEDEF(OptLongDouble, long double);
OPTION_TYPEDEF(OptLongDoublePtr, long double *);

#ifndef __STDC_NO_COMPLEX__
OPTION_TYPEDEF(OptFloatComplex, float _Complex);
OPTION_TYPEDEF(OptFloatComplexPtr, float _Complex *);
OPTION_TYPEDEF(OptDoubleComplex, double _Complex);
OPTION_TYPEDEF(OptDoubleComplexPtr, double _Complex *);
OPTION_TYPEDEF(OptLongDoubleComplex, long double _Complex);
OPTION_TYPEDEF(OptLongDoubleComplexPtr, long double _Complex *);
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
