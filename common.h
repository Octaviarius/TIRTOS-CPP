#pragma once

#include <useful_header.h>
#include "ErrorBlock.hpp"


#define TIRTOS_OBJECT   private: static int m_obj_counter; \
                        private: static CErrorBlock m_error_block; \
                        private: static void _inc_object() {m_obj_counter++;} \
                        private: static void _dec_object() {m_obj_counter--;} \
                        public: static CErrorBlock *errorBlock() {return &m_error_block;} \
                        public: static int objectsCount() {return m_obj_counter;};

#define TIRTOS_OBJECT_CONSTRUCT(classname)  int classname::m_obj_counter = 0; CErrorBlock classname::m_error_block;


namespace tirtos{

typedef int (*TCallbackFunction)(void *);
typedef CFunctor1<void*, int> TCallbackFunctor;
typedef CFunctor0<void> TFastFunctor;

};//namespace os
