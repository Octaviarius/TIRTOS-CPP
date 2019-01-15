#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define STRINGIZE(A)    #A


using namespace std;

namespace tirtos {




template<class T>
class CSmartPointer {
private:
    struct TServiceData{
        size_t links;
        size_t size;
        T data;
    } *ptr;



    void acquire() const{
        if(ptr != nullptr)
            ptr->links++;
    }

    // realease link and if no links anymore that allocated memory is delete
    void release(){
        if(ptr != nullptr){
            if(ptr->links == 1){
                delete(ptr);
                ptr = nullptr;
            }else
                ptr->links--;
        }
    }
public:

    CSmartPointer() {
        ptr = nullptr;
    }

    CSmartPointer(size_t count) {
        ptr = nullptr;
        allocate(count);
    }

    CSmartPointer(CSmartPointer &other){
        other.acquire();
        ptr = other.ptr;
    }

    ~CSmartPointer(){
        release();
    }


    size_t links() const   {return (ptr == nullptr) ? 0 : ptr->links;}
    size_t size() const   {return (ptr == nullptr) ? 0 : ptr->size;}
    size_t count() const   {return (ptr == nullptr) ? 0 : (ptr->size - ((uintptr_t)&ptr->data - (uintptr_t)ptr) / sizeof(T);}


    CSmartPointer &operator=(const CSmartPointer &other){
        if(ptr != other.ptr){
            FORCE_CAST(CSmartPointer, other).acquire();
            release();
            ptr = other.ptr;
        }
        return *this;
    }

    operator T*()                   {return (ptr == nullptr) ? nullptr : &ptr->data;}
    T &operator[](std::size_t i)    {return (ptr == nullptr) ? printf("SmartPointer<"STRINGIZE(T)">"STRINGIZE(__FUNCTION_)" is null"), *(T*)nullptr : (&ptr->data)[i];}
    T &operator->()                 {return (ptr == nullptr) ? printf("SmartPointer<"STRINGIZE(T)">"STRINGIZE(__FUNCTION_)" is null"), *(T*)nullptr : ptr->data;}
    T &operator*()                  {return (ptr == nullptr) ? printf("SmartPointer<"STRINGIZE(T)">"STRINGIZE(__FUNCTION_)" is null"), *(T*)nullptr : ptr->data;}


    T *allocate(size_t count = 1)   {
        release();
        size_t sz = sizeof(TServiceData) + (count-1)*sizeof(T);
        ptr = (TServiceData*) new char[sz];
        new(&ptr->data) T[count];
        ptr->size = sz;
        acquire();
        return &ptr->data;
    }


    void reset() {
        release();
        ptr = nullptr;
    }




};













} /* namespace tirtos */


