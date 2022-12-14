#ifndef CGC_TERRITORYPARSERS
#define CGC_TERRITORYPARSERS
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

#ifndef __TERRITORYPARSERS_H__
#define __TERRITORYPARSERS_H__

#include "libcgc.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_service.h"
#include "cgc_helper.h"
#include "cgc_genericParsers.h"
#include "cgc_countyParsers.h"

void cgc_initTerritory( pTerritory ty);
int cgc_territoryMenu( pTerritory ty );
void cgc_freeTerritory( pTerritory ty );
void cgc_printTerritoryInfo( pTerritory ty );
pTerritory cgc_territoryTopLevel( pstring str);
int cgc_extractEstablished( pstring str );
char *cgc_extractFounder( pstring str );

#endif


#endif // CGC_TERRITORYPARSERS
