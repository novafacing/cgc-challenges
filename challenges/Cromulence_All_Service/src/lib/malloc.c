/*

Author: Jason Williams <jdw@cromulence.com>

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
#include "cgc_malloc.h"
#include "cgc_stdlib.h"
#include <stdlib.h>

#define ALLOC_PAGE_SIZE (4096)

#define FREE_BLOCK_NEXT(block)                                                 \
  (((tMallocAllocFtr *)((void *)block +                                        \
                        (((tMallocAllocHdr *)block)->alloc_size & ~0x3) -      \
                        sizeof(tMallocAllocHdr)))                              \
       ->pNext)
#define FREE_BLOCK_PREV(block)                                                 \
  (((tMallocAllocFtr *)((void *)block +                                        \
                        (((tMallocAllocHdr *)block)->alloc_size & ~0x3) -      \
                        sizeof(tMallocAllocHdr)))                              \
       ->pPrev)

#define SET_BIT(val, bit) (val |= (bit))
#define CLEAR_BIT(val, bit) (val &= ~(bit))
#define IS_BIT_SET(val, bit) (val & (bit))

tMallocManager g_memManager;

void *cgc_calloc(cgc_size_t count, cgc_size_t obj_size) {
  cgc_size_t allocation_size = (count * obj_size);
  void *pMemBuffer;

  pMemBuffer = cgc_malloc(allocation_size);

  cgc_memset(pMemBuffer, 0, allocation_size);

  return (pMemBuffer);
}

void *cgc_add_free_list(cgc_size_t request_size) {
  // Include header
  cgc_size_t grow_size = (request_size + 4);

  // Increases the size of the free list
  if (grow_size % ALLOC_PAGE_SIZE != 0) {
    grow_size = (grow_size / ALLOC_PAGE_SIZE) + 1;
    grow_size *= ALLOC_PAGE_SIZE;
  }

  void *pAllocLocation;

  if (cgc_allocate(grow_size, 0, &pAllocLocation) != 0) {
    // Out of memory
    cgc__terminate(-2);
  }

  // Provision allocation
  tMallocAllocHdr *pNewAllocHdr = (tMallocAllocHdr *)pAllocLocation;
  tMallocAllocFtr *pNewAllocFtr =
      (tMallocAllocFtr *)(pAllocLocation +
                          (grow_size - sizeof(tMallocAllocFtr)));

  pNewAllocHdr->alloc_size = (grow_size - sizeof(tMallocAllocHdr));

  // Link at front
  pNewAllocFtr->pPrev = NULL;
  pNewAllocFtr->pNext = g_memManager.pFreeList;
  g_memManager.pFreeList = pNewAllocHdr;

  return (void *)pNewAllocHdr;
}

void *cgc_malloc(cgc_size_t alloc_size) { return malloc(alloc_size); }

void cgc_free(void *pItem) {
  free(pItem);
  return;
}
