#include "stm32f10x.h"         //???
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
 
#include "motor_1.h"
#include "Delay.h"
#include "PWM.h"
#include "TrackSensor.h"
#include "Serial.h"

uint8_t RxData;
int main(void)
{
	/*
	Delay_s(1);
	//back_into_garage_2();
	cefang_into_garage2();
	*/
	Serial_Init();
	
	while (1)
	{
		if (Serial_GetRxFlag()==1)
		{
			if (Serial_RxData == 0x45)
			{
				//back_into_garage_2();
				cefang_into_garage2();
			}
			
		}
	}
}
