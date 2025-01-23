#include "motor_1.h"  //??led???
#include "stm32f10x.h"  //??STM32???
#include "stm32f10x_rcc.h"  //??STM32?RCC???
#include "delay_other.h"       //???
#include "PWM.h"
#include <stdlib.h>
#include "TrackSensor.h"


uint8_t pos_1 = 0;
uint8_t pos_2 = 0;

void Motor_Config(void)  //???????
{
	GPIO_InitTypeDef GPIO_InitStructure;   //??GPIO_InitTypeDef???
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);  //??????
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6; //??IN??
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //??????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //??????
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //???GPIOA?????,??
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6); //??????
	PWM_Init();
}

void Motor_1_STOP(void)
{
	IN1(High);
	IN2(High);
}
 
void Motor_1_PRun(void)
{
	IN1(Low);
	IN2(High);
}
 
void Motor_1_NRun(void)
{
	IN1(High);
	IN2(Low);
}
 
void Motor_2_STOP(void)
{
	IN3(High);
	IN4(High);
}
 
void Motor_2_PRun(void)
{
	IN3(Low);
	IN4(High);
}
 
void Motor_2_NRun(void)
{
	IN3(High);
	IN4(Low);
}

void straight_run()
{
	Motor_1_PRun();
	Motor_2_PRun();
	PWM_SetCompare1(70); // set the CRR to change the speed;range 0,100
	PWM_SetCompare2(70);
}

void back()
{
	Motor_1_NRun();
	Motor_2_NRun();
	
	PWM_SetCompare1(75); // set the CRR to change the speed;range 0,100
	PWM_SetCompare2(75);
}

void P_right()
{
	Motor_1_PRun();
	Motor_2_PRun();
	
	PWM_SetCompare2(70);
	PWM_SetCompare1(90);
	
}

void P_left()
{
	Motor_1_PRun();
	Motor_2_PRun();
	
	PWM_SetCompare1(70);
	PWM_SetCompare2(80);
}

void N_right()
{
	Motor_1_NRun();
	Motor_2_NRun();
	
	PWM_SetCompare1(70);
	PWM_SetCompare2(100);
}

void Nb_right()
{

}

void N_left()
{
	Motor_1_NRun();
	Motor_2_NRun();
	
	PWM_SetCompare1(100);
	PWM_SetCompare2(70);

}

void stop(){
	Motor_1_STOP();
	Motor_2_STOP();
	PWM_SetCompare1(0);
	PWM_SetCompare2(0);
}


void back_into_garage(){
	Motor_Config(); 
	TCRT5000_Init();
	while(1){
		/*
	if (Tracking_D2 == 0 && pos_1 == 0) {
	pos_1 = 1;
	Delay_s(1);
	break;
	}
		*/
	if (Tracking_DO  == 0 && Tracking_D1 == 0){
			straight_run();
	}		
		else if(Tracking_DO == 1 && Tracking_D1 == 0 ){
			P_right();
	}
	else if(Tracking_DO == 0 && Tracking_D1 == 1 ){
			P_left();
	}

	else if(Tracking_DO == 1 && Tracking_D1 == 1 ){
			straight_run();
	}	
	
	
	}
	while(1)	
	{
		if (Tracking_D2 == 0 && pos_1 == 1) {
			pos_2 = 1;
			break;
		}
	if (Tracking_DO  == 0 && Tracking_D1 == 0){
			straight_run();
	}		
		else if(Tracking_DO == 1 && Tracking_D1 == 0 ){
			P_right();
	}
	else if(Tracking_DO == 0 && Tracking_D1 == 1 ){
			P_left();
	}

	else if(Tracking_DO == 1 && Tracking_D1 == 1 ){
			straight_run();
	}	
	}

	
}


void back_into_garage_2()
{
	Motor_Config(); 
	stop();
	Delay_ms(2000);
	
	back();
	Delay_ms(800);
	
	stop();
	Delay_s(1);
	
	P_right();
	Delay_ms(2000);
	
	stop();
	Delay_s(1);
	
	N_right();
	Delay_ms(1300);
	
	back();
	Delay_ms(500);
	
	stop();
}

void cefang_into_garage()
{
	Motor_Config(); 
	TCRT5000_Init();
	straight_run();
	while(1){
		/*
	if (Tracking_D2 == 0 && pos_1 == 0) {
	pos_1 = 1;
	Delay_s(1);
	break;
	}
		*/
	if (Tracking_DO  == 0 && Tracking_D1 == 0){
			straight_run();
	}		
		else if(Tracking_DO == 1 && Tracking_D1 == 0 ){
			P_right();
	}
	else if(Tracking_DO == 0 && Tracking_D1 == 1 ){
			P_left();
	}

	else if(Tracking_DO == 1 && Tracking_D1 == 1 ){
			straight_run();
	}	
	
	
	}
	while(1)	
	{
		if (Tracking_D2 == 0 && pos_1 == 1) {
			pos_2 = 1;
			break;
		}
	if (Tracking_DO  == 0 && Tracking_D1 == 0){
			straight_run();
	}		
		else if(Tracking_DO == 1 && Tracking_D1 == 0 ){
			P_right();
	}
	else if(Tracking_DO == 0 && Tracking_D1 == 1 ){
			P_left();
	}

	else if(Tracking_DO == 1 && Tracking_D1 == 1 ){
			straight_run();
	}	
	}
}

void cefang_into_garage2()
{
	Motor_Config(); 
	stop();
	Delay_ms(2000);
	
	back();
	Delay_ms(800);
	
	stop();
	Delay_s(1);
	
	P_right();
	Delay_ms(2500);
	
	back();
	Delay_ms(1500);
	
	stop();
	Delay_s(1);
	
	N_left();
	Delay_ms(500);
	
	stop();

}