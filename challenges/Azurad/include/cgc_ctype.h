#ifndef CGC_CTYPE
#define CGC_CTYPE
#ifndef CTYPE_H_
#define CTYPE_H_

int cgc_digittoint(int c);
int cgc_isascii(int c);
int cgc_isdigit(int c);
int cgc_isprint(int c);
int cgc_isalnum(int c);
int cgc_isalpha(int c);
int cgc_islower(int c);
int cgc_isupper(int c);
int cgc_isspace(int c);
int cgc_ispunct(int c);
int cgc_iscntrl(int c);
int cgc_isxdigit(int c);
int cgc_tolower(int c);
int cgc_toupper(int c);

#endif

#endif // CGC_CTYPE
