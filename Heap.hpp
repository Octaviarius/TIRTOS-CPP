#pragma once


#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/heaps/HeapMem.h>

#include "common.h"
#include "ErrorBlock.hpp"



namespace tirtos {



class CHeap {
    TIRTOS_OBJECT
private:
	HeapMem_Handle handle;
	HeapMem_Params params;
public:

	CHeap(void *buff, size_t size);
	~CHeap();

	void *allocate(size_t size, size_t align = 1);
	void deallocate(void *ptr, size_t size);

	size_t TotalSize();
	size_t FreeSize();
	size_t LargestFreeSize();

};




} /* namespace os */

