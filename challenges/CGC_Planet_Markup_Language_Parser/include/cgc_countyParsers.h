#ifndef CGC_COUNTYPARSERS
#define CGC_COUNTYPARSERS
/*

Author: John Berry <hj@cromulence.co>

Copyright (c) 2014 Cromulence LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifndef __COUNTYPARSERS_H__
#define __COUNTYPARSERS_H__

#include "libcgc.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_service.h"
#include "cgc_helper.h"
#include "cgc_genericParsers.h"
#include "cgc_cityParsers.h"

int cgc_countyMenu( pCounty co );
void cgc_initCounty( pCounty co );
void cgc_freeCounty( pCounty co );
void cgc_printCountyInfo( pCounty co);
pCounty cgc_countyTopLevel( pstring str);
double cgc_extractArea( pstring str );
double cgc_extractDensity( pstring str );
char *cgc_extractSeat( pstring str );

#endif


#endif // CGC_COUNTYPARSERS
