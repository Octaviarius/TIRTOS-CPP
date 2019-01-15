#pragma once

#include <stdint.h>
#include <tirtos/Module.hpp>






namespace tirtos{




class CCpu{
public:

	enum Bus{
		MainBus,
		LowSpeedBus,
		HiSpeedBus
	};

private:

	static float input_clock;
	static float buses[][3];
	static float initInputClock();

public:

	CCpu();
	~CCpu();

	static int NumCores();
	static int NumBuses();
	static uint16_t PartID();

	static float InputFreq();

	static void setFreq(float freq, int bus = MainBus);
	static void setMult(float mult, int bus = MainBus);
	static float Mult(int bus = MainBus);
	static float Freq(int bus = MainBus);
	static float Rate(int bus = MainBus);

};


};
