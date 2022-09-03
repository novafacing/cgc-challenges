#ifndef CGC_TIME
#define CGC_TIME
#pragma once

#include "cgc_cstdint.h"

extern uint32_t cgc_ticks;

class Time
{
  public:
    static void Reset(void);
    static uint32_t GetTime(void);
    static void Tick(void);
};

#endif // CGC_TIME
