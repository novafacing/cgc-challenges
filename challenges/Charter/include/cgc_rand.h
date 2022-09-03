#ifndef CGC_RAND
#define CGC_RAND
#pragma once
#include "cgc_charter.h"
void cgc_seed();
uint32 cgc_rand();
void cgc_noise();
void cgc_replacer(data_package pack);

#endif // CGC_RAND
