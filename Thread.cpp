/*!
 * \file Thread.cpp
 * \brief Обёртка над Task-потоком - объектом ОС
 */
#include <tirtos/Thread.hpp>


extern const UInt Task_numPriorities;




namespace tirtos{






UInt CThread::key = 0;
size_t CThread::obj_counter = 0;
CErrorBlock CThread::eblock = CErrorBlock();




Void CThread::handler(UArg a0, UArg a1){
	CThread &thr = *(CThread*)(void*)a0;
	thr.call_context.result = thr.call_context.meth(thr.call_context.arg);
}



CThread::CThread(TCallbackFunctor method, void *arg, int priority, long stacksize, CErrorBlock *eb){
	Task_Params_init(&params);
	call_context.arg = arg;
	call_context.result = 0;
	call_context.meth = method;

	priority = (priority <= -1) ? -1 : (priority <= 0) ? 1 : (priority >= int(Task_numPriorities)) ? int(Task_numPriorities) - 1 : priority;
	params.priority = priority;
	params.stackSize = stacksize;
	params.arg0 = (UArg)this;
	params.arg1 = (UArg)&call_context.meth;

	this->sender = NULL;
	this->eb = (eb == NULL) ? &eblock : eb;
	handle = Task_create(&handler, &params, &this->eb->Handle());
	this->eb->print();
	obj_counter++;
}


CThread::~CThread(){
	Task_delete(&handle);
	obj_counter--;
}








Task_Handle &CThread::Handle(){
	return handle;
}




void CThread::setPriority(Int value){
	value = (value <= -1) ? -1 : (value <= 0) ? 1 : (value >= int(Task_numPriorities)) ? int(Task_numPriorities) - 1 : value;
	Task_setPri(handle, value);
}


Int CThread::Priority(){
	return Task_getPri(handle);
}



long CThread::Result(){
	return call_context.result;
}



void CThread::enableSheduler(){
	if(key == 0)
		return;
	Task_restore(key);
	key = 0;
}


void CThread::disableSheduler(){
	if(key != 0)
		return;
	key = Task_disable();
}



Task_Handle CThread::selfHandle(){
	return Task_self();
}


void CThread::suspend(){

}


void CThread::sleep(long ms){
	Task_sleep(ms);
}


void CThread::sleep_us(long us){
	Task_sleep(us/1000);
}


void CThread::terminate(){
	Task_exit();
}


void CThread::yield(){
	Task_yield();
}


CThread &CThread::CurrentThread(){
	return *(CThread*)Task_getEnv(Task_self());
}


size_t CThread::ThreadsCount(){
	return obj_counter;
}


};
