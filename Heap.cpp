#include "Heap.hpp"
#include <xdc/runtime/Memory.h>


namespace tirtos {



TIRTOS_OBJECT_CONSTRUCT(CHeap);



CHeap::CHeap(void *buff, size_t size){
	HeapMem_Params_init(&params);
	params.buf = (typeof(params.buf))buff;
	params.size = size;
	params.minBlockAlign = 1;

	handle = HeapMem_create(&params, &errorBlock()->Handle());

	_inc_object();
}


CHeap::~CHeap(){
	_dec_object();
}

void *CHeap::allocate(size_t size, size_t align){
	return Memory_alloc((xdc_runtime_IHeap_Handle)handle, size, align, &m_error_block.Handle());
}


void CHeap::deallocate(void *ptr, size_t size){
	Memory_free((xdc_runtime_IHeap_Handle)handle, ptr, size);
}






size_t CHeap::TotalSize(){
	Memory_Stats stats;
	Memory_getStats((xdc_runtime_IHeap_Handle)handle, &stats);
	return stats.totalSize;
}


size_t CHeap::FreeSize(){
	Memory_Stats stats;
	Memory_getStats((xdc_runtime_IHeap_Handle)handle, &stats);
	return stats.totalFreeSize;
}

size_t CHeap::LargestFreeSize(){
	Memory_Stats stats;
	Memory_getStats((xdc_runtime_IHeap_Handle)handle, &stats);
	return stats.largestFreeSize;
}






} /* namespace os */
