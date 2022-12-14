#ifndef CGC_STDARG
#define CGC_STDARG
#ifndef STDARG_H_
#define STDARG_H_

#ifdef WIN
#include <stdarg.h>
#else
typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)
#endif

#endif

#endif // CGC_STDARG
