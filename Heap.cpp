#include <tirtos/Heap.hpp>
#include <xdc/runtime/Memory.h>


namespace tirtos {


CErrorBlock CHeap::eblock;
size_t CHeap::obj_counter = 0;



CHeap::CHeap(void *buff, size_t size, CErrorBlock *eb){
	HeapMem_Params_init(&params);
	params.buf = (typeof(params.buf))buff;
	params.size = size;
	params.minBlockAlign = 1;

	this->eb = (eb == NULL) ? &eblock : eb;
	handle = HeapMem_create(&params, &this->eb->Handle());

	obj_counter++;
}


CHeap::~CHeap(){
	obj_counter--;
}

void *CHeap::allocate(size_t size, size_t align){
	return Memory_alloc((xdc_runtime_IHeap_Handle)handle, size, align, &eb->Handle());
}


void CHeap::deallocate(void *ptr, size_t size){
	Memory_free((xdc_runtime_IHeap_Handle)handle, ptr, size);
}




size_t CHeap::HeapsCount(){
	return obj_counter;
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
