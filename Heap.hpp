#pragma once


#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/heaps/HeapMem.h>

#include "ErrorBlock.hpp"



namespace tirtos {



class CHeap {
private:
	HeapMem_Handle handle;
	HeapMem_Params params;
	CErrorBlock *eb;

	static CErrorBlock eblock;
	static size_t obj_counter;
public:

	CHeap(void *buff, size_t size, CErrorBlock *eb = NULL);
	~CHeap();

	void *allocate(size_t size, size_t align = 1);
	void deallocate(void *ptr, size_t size);

	size_t HeapsCount();

	size_t TotalSize();
	size_t FreeSize();
	size_t LargestFreeSize();


};

} /* namespace os */

