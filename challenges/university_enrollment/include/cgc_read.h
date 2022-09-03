#ifndef CGC_READ
#define CGC_READ
#ifndef READ_H_
#include "cgc_stdlib.h"

int cgc_readline(char *buf, cgc_size_t buf_size);
int cgc_readnum(char *buf, cgc_size_t buf_size);

#endif

#endif // CGC_READ
