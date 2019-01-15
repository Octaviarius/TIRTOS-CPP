/*!
 * \file Queue.hpp
 * \brief Определение очереди.
 */
#pragma once


#include "MutexLocker.hpp"
#include "Semaphore.hpp"
#include <stddef.h>


using namespace std;

namespace tirtos{


//================================/ CQueue /======================================
template<class T>
class CQueue {
private:

	struct qelem_t{
		qelem_t *next;
		T elem;
	};

	qelem_t *head, *tail;
	uint16_t reserved;
	uint16_t len;
	uint16_t max_len;
	bool is_external_mutex;

	CMutex *mutex;
	CSemaphore sem;

public:

	CQueue(CMutex *mutex = NULL);
	~CQueue();

	bool push(const T &data);
	bool pop(T &data, long timeout = BIOS_NO_WAIT);

	int reserve(size_t count);
	size_t Reserved();

	size_t Length();

	T *Head();
	T *Tail();

	bool isEmpty();

	void setMaxLength(size_t maxlen);
	size_t MaxLength();

	void clear();
};




































template<class T>
CQueue<T>::CQueue(CMutex *mutex) :
	sem(0)
{

	head = tail = new qelem_t;
	head->next = head;
	reserved = 1;
	len = 0;
	max_len = (uint16_t)-1;

	if(mutex == NULL){
		this->mutex = new CMutex();
		is_external_mutex = false;
	}else{
		this->mutex = mutex;
		is_external_mutex = true;
	}

}





template<class T>
CQueue<T>::~CQueue(){
	if(!is_external_mutex)
		delete mutex;
};


template<class T>
bool CQueue<T>::push(const T &data){
	bool ret = true;

	mutex->lock();
	if(max_len == 0 || max_len > len){

		if(tail->next != head){
			tail->elem = data;
			tail = tail->next;
			len++;
			sem.release();
		}else{
			qelem_t *q = new qelem_t;
			if(q == NULL)
				ret = false;
			else{
				q->next = tail->next;
				tail->next = q;
				tail->elem = data;
				tail = q;
				len++;
				reserved++;
				sem.release();
			}
		}
	}else
		ret = false;
	mutex->unlock();

	return ret;
};





template<class T>
bool CQueue<T>::pop(T &data, long timeout){
	bool ret = true;

	if(!sem.acquire(timeout))
		ret = false;
	else{
		mutex->lock();

		if(head == tail)
			ret = false;
		else{
			data = head->elem;
			head = head->next;
			len--;
		}

		mutex->unlock();
	}

	return ret;
};






template<class T>
int CQueue<T>::reserve(size_t count){
	CMutexLocker locker(mutex);
	int ret = 0;

	while(count-- > 0){

		qelem_t *q = new qelem_t;
		if(q == NULL){
			ret = -1;
			break;
		}else{
			q->next = tail->next;
			tail->next = q;
			reserved++;
		}
	}

	return ret;
}


template<class T>
size_t CQueue<T>::Reserved(){
	CMutexLocker locker(mutex);
	return reserved;
}




template<class T>
size_t CQueue<T>::Length() {
	CMutexLocker locker(mutex);
	return len;
};





template<class T>
T *CQueue<T>::Head() {
	CMutexLocker locker(mutex);
	return (head == tail) ? NULL : &head->elem;
};



template<class T>
T *CQueue<T>::Tail() {
	CMutexLocker locker(mutex);
	return (head == tail) ? NULL : &tail->elem;
};





template<class T>
bool CQueue<T>::isEmpty() {
	CMutexLocker locker(mutex);
	return len == 0;
};


template<class T>
void CQueue<T>::setMaxLength(size_t maxlen){
	CMutexLocker locker(mutex);
	if(maxlen < max_len && maxlen != 0){
		tail = head;
		len = 0;
	}
	max_len = maxlen;
};


template<class T>
size_t CQueue<T>::MaxLength(){
	CMutexLocker locker(mutex);
	return max_len;
};





template<class T>
void CQueue<T>::clear(){
	CMutexLocker locker(mutex);
	tail = head;
	len = 0;
};



};//namespace
