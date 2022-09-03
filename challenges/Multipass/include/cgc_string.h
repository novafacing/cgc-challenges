#ifndef CGC_STRING
#define CGC_STRING
#ifndef CGC_STRING
#define CGC_STRING
#ifndef STRING_H_
#define STRING_H_

#include "cgc_stddef.h"

extern void *cgc_memcpy(void *dest, const void *src, cgc_size_t n);
extern void *cgc_memmove(void *dest, const void *src, cgc_size_t n);
extern void *cgc_memset(void *dest, int c, cgc_size_t n);
extern int memcmp(void *s1, const void *s2, cgc_size_t n);
extern void *cgc_memchr(const void *s, int c, cgc_size_t n);

extern cgc_size_t cgc_strlen(const char *s);
extern char *cgc_strcpy(char *dest, const char *src);
extern char *cgc_strncpy(char *dest, const char *src, cgc_size_t n);
extern char *cgc_strchr(const char *s, int c);
extern char *cgc_strsep(char **stringp, const char *delim);
extern int strcmp(const char *s1, const char *s2);

#endif /* !STRING_H_ */

#endif // CGC_STRING

#endif // CGC_STRING
