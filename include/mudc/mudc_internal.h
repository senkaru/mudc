/* mudc_internal.h */
#ifndef MUDC_INCLUDE_MUDC_INTERNAL_H
#define MUDC_INCLUDE_MUDC_INTERNAL_H
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
#define MUDC_CPP_GUARD_BEGIN extern "C" {
#define MUDC_CPP_GUARD_END }
#else
#define MUDC_CPP_GUARD_BEGIN
#define MUDC_CPP_GUARD_END
#endif

#ifndef MUDC_DEF
#ifdef MUDC_STATIC
#define MUDC_DEF static
#else
#define MUDC_DEF extern
#endif
#endif

#define MUDC_UNUSED(x) (void)(x)


#ifdef __cplusplus
}
#endif
#endif /* MUDC_INCLUDE_MUDC_INTERNAL_H */
