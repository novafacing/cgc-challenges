#ifndef CGC_BLOCK
#define CGC_BLOCK
#pragma once

void* _NSConcreteStackBlock;
void* _NSConcreteGlobalBlock;

void _Block_object_assign(void* dst, const void *src, int flag);
void _Block_object_dispose(void* arg, int flag);

#endif // CGC_BLOCK
