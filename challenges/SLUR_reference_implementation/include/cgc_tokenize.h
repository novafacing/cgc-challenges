#ifndef CGC_TOKENIZE
#define CGC_TOKENIZE
#ifndef __TOKENIZE_H_
#define __TOKENIZE_H_

#include "cgc_list.h"

DEF_LIST(tok, char *);

tok_list *cgc_tokenize(char *expr);

#endif /* __TOKENIZE_H_ */

#endif // CGC_TOKENIZE
