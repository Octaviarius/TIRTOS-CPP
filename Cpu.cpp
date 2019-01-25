/*!
 * \file Cpu.cpp
 * \brief Начальное конфигурирование CPU.
 *
 */

#include "Cpu.hpp"
#include <DSP28x_Project.h>


#define NUM_CORES	1
#define NUM_BUSES	3
#define EXTERN_CLOCK	(20*1000000UL)
#define SYSTEM_CPU_MULT	15



namespace tirtos{


float CCpu::input_clock = CCpu::initInputClock();
float CCpu::buses[NUM_BUSES][3];



float CCpu::initInputClock(){
	input_clock = EXTERN_CLOCK;

	buses[MainBus][0] = float(SysCtrlRegs.PLLCR.bit.DIV + 1) / float(1<<(3 - SysCtrlRegs.PLLSTS.bit.DIVSEL));
	buses[MainBus][1] = input_clock * buses[MainBus][0];
	buses[MainBus][2] = 1.0 / buses[MainBus][1];

	buses[LowSpeedBus][0] = (SysCtrlRegs.LOSPCP.bit.LSPCLK == 0) ? 1.0 : 1.0 / (float)(SysCtrlRegs.LOSPCP.bit.LSPCLK * 2);
	buses[LowSpeedBus][1] = buses[MainBus][1] * buses[LowSpeedBus][0];
	buses[LowSpeedBus][2] = 1.0 / buses[LowSpeedBus][1];

	buses[HiSpeedBus][0] = (SysCtrlRegs.HISPCP.bit.HSPCLK == 0) ? 1.0 : 1.0 / (float)(SysCtrlRegs.HISPCP.bit.HSPCLK * 2);
	buses[HiSpeedBus][1] = buses[MainBus][1] * buses[HiSpeedBus][0];
	buses[HiSpeedBus][2] = 1.0 / buses[LowSpeedBus][1];

	return EXTERN_CLOCK;
}


CCpu::CCpu(){

}


CCpu::~CCpu(){

}




int CCpu::NumCores(){
	return NUM_CORES;
}

int CCpu::NumBuses(){
	return NUM_CORES;
}


uint16_t CCpu::PartID(){
	return DevEmuRegs.PARTID.all;
}


void CCpu::setFreq(float freq, int bus){
	setMult(Mult(bus) * freq / Freq(bus), bus);
}


void CCpu::setMult(float mult, int bus){
	switch(bus){

		case MainBus:{
			float last_mult = buses[MainBus][0];

			if(mult < 0.125 || mult > 31)
				return;
			else if(mult >= 0.125 && mult < 4){
				InitPll(8 * mult - 1, 0);
				mult = (int)(mult * 8) / 8.0;
			}else if(mult >= 4 && mult < 8){
				InitPll(4 * mult - 1, 1);
				mult = (int)(mult * 4) / 4.0;
			}else if(mult >= 8 && mult < 16){
				InitPll(2 * mult - 1, 2);
				mult = (int)(mult * 2) / 2.0;
			}else if(mult >= 16 && mult < 32){
				InitPll(mult, 3);
				mult = (int)(mult * 1) / 1.0;
			}

			last_mult = mult / last_mult;

			CpuTimer0Regs.PRD.all = uint32_t(float(CpuTimer0Regs.PRD.all) * last_mult);
			CpuTimer1Regs.PRD.all = uint32_t(float(CpuTimer1Regs.PRD.all) * last_mult);
			CpuTimer2Regs.PRD.all = uint32_t(float(CpuTimer2Regs.PRD.all) * last_mult);

			buses[MainBus][0] = mult;
			buses[MainBus][1] = input_clock * mult;
			buses[MainBus][2] = 1.0 / buses[MainBus][1];

			buses[LowSpeedBus][1] = buses[MainBus][1] * buses[LowSpeedBus][0];
			buses[LowSpeedBus][2] = 1.0 / buses[LowSpeedBus][1];

			buses[HiSpeedBus][1] = buses[MainBus][1] * buses[HiSpeedBus][0];
			buses[HiSpeedBus][2] = 1.0 / buses[HiSpeedBus][1];
			break;
		}


		case LowSpeedBus:{
			if(mult < 1.0 / 14.0 || mult > 1.0)
				return;

			EALLOW;
			if(mult == 1.0)
				SysCtrlRegs.LOSPCP.bit.LSPCLK = 0;
			else
				SysCtrlRegs.LOSPCP.bit.LSPCLK = 0.5 / mult;
			EDIS;

			if(SysCtrlRegs.LOSPCP.bit.LSPCLK == 0)
				mult = 1;
			else
				mult = 0.5 / (float)SysCtrlRegs.LOSPCP.bit.LSPCLK;

			buses[LowSpeedBus][0] = mult;
			buses[LowSpeedBus][1] = buses[MainBus][1] * mult;
			buses[LowSpeedBus][2] = 1.0 / buses[LowSpeedBus][1];
			break;
		}


		case HiSpeedBus:{
			if(mult < 1.0 / 62.0 || mult > 1.0)
				return ;

			EALLOW;
			if(mult == 1.0)
				SysCtrlRegs.HISPCP.bit.HSPCLK = 0;
			else
				SysCtrlRegs.HISPCP.bit.HSPCLK = 0.5 / mult;
			EDIS;

			if(SysCtrlRegs.HISPCP.bit.HSPCLK == 0)
				mult = 1;
			else
				mult = 0.5 / (float)SysCtrlRegs.HISPCP.bit.HSPCLK;

			buses[HiSpeedBus][0] = mult;
			buses[HiSpeedBus][1] = buses[MainBus][1] * mult;
			buses[HiSpeedBus][2] = 1.0 / buses[HiSpeedBus][1];
			break;
		}

	}
}


float CCpu::Mult(int bus){
	return buses[bus][0];
}

float CCpu::Freq(int bus){
	return buses[bus][1];
}

float CCpu::Rate(int bus){
	return buses[bus][2];
}


float CCpu::InputFreq(){
	return EXTERN_CLOCK;
}



};
