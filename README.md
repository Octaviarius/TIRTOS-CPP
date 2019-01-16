# TIRTOS-CPP

This source code is wrapping C-styled TIRTOS API to human-readable view :)

Objects, such as Threads, Interrupts, Timers and many other are encapsulated in C++ classes with methods

For example, code which construct timer:

C-styled:
```c
	Void timer_handler(UArg a){
		//do something
	}
	
	Clock_Handle handle;
	Clock_Params params;
	
	//construction section
	...
	Clock_Params_init(&params);
	params.arg = 666;
	params.startFlag = 1;
	handle = Clock_create(&timer_handler, 1000, &params, NULL);
	...
	
	
	//in other place in your code you want change timer period
	//...
	Clock_setPeriod(handle, 2000);
	//...
```
	
	
C++ styled:
```cpp
    void timer_handler_func(){
    	//do something
    }
    	
    class TSomeClass{
    public:
    	void timer_handler_meth(){
    		//do something
    	}
    };
    	
    //for function pointer declare
    TTimer tick_func(TFastFunctor(&timer_handler_func), 1000, true);
    //for method of class declare
    TSomeClass myclass;
    TTimer tick_meth(TFastFunctor(&myclass, &TSomeClass::timer_handler_meth), 1000, true);
    
    //in other place in your code you want change timer period
    //...
    tick_func.setPeriod(2000);
    tick_meth.setPeriod(4000);
    //...
```
	
How you see this unified interface provided for fast and simple declaration and use tirtos objects for more power utility!
	
	
