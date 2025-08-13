#include "motor.h"
#include "interface.h"
#include "stm32f10x.h"

//GPIO配置函数
void MotorGPIO_Configuration(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_F_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(FRONT_LEFT_F_GPIO, &GPIO_InitStructure);    
	
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_B_PIN;	
	GPIO_Init(FRONT_LEFT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_F_PIN;	
	GPIO_Init(FRONT_RIGHT_F_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_B_PIN;	
	GPIO_Init(FRONT_RIGHT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_F_PIN;	
	GPIO_Init(BEHIND_LEFT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_B_PIN;	
	GPIO_Init(BEHIND_LEFT_B_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_F_PIN;	
	GPIO_Init(BEHIND_RIGHT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_B_PIN;	
	GPIO_Init(BEHIND_RIGHT_B_GPIO, &GPIO_InitStructure);  
	
}

//根据占空比驱动电机转动
void CarMove(void)
{   
	
	 BEHIND_RIGHT_EN;
	
 /* //左前轮
	if(front_left_speed_duty > 0)//向前
	{
		if(speed_count < front_left_speed_duty)
		{
			FRONT_LEFT_GO;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty < 0)//向后
	{
		if(speed_count < (-1)*front_left_speed_duty)
		{
			FRONT_LEFT_BACK;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else                //停止
	{
		FRONT_LEFT_STOP;
	}*/
	
		//右前轮
	if(front_right_speed_duty > 0)//向前
	{
		if(speed_count < front_right_speed_duty)
		{
			FRONT_RIGHT_GO;
		}else                //停止
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty < 0)//向后
	{
		if(speed_count < (-1)*front_right_speed_duty)
		{
			FRONT_RIGHT_BACK;
		}else                //停止
		{
			FRONT_RIGHT_STOP;
		}
	}
	else                //停止
	{
		FRONT_RIGHT_STOP;
	}
	
	//左后轮
	if(behind_left_speed_duty > 0)//向前
	{
		if(speed_count < behind_left_speed_duty)
		{
			BEHIND_LEFT_GO;
		}	else                //停止
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty < 0)//向后
	{
		if(speed_count < (-1)*behind_left_speed_duty)
		{
			BEHIND_LEFT_BACK;
		}	else                //停止
		{
			BEHIND_LEFT_STOP;
		}
	}
	else                //停止
	{
		BEHIND_LEFT_STOP;
	}
	
/*		//右后轮
	if(behind_right_speed_duty > 0)//向前
	{
		if(speed_count < behind_right_speed_duty)
		{
			BEHIND_RIGHT_GO;
//ٶ
void CarRun(int left_speed, int right_speed)
{
        front_left_speed_duty = left_speed;
        behind_left_speed_duty = left_speed;
        front_right_speed_duty = right_speed;
        behind_right_speed_duty = right_speed;
}

//ǰ
void CarGo(void)
{
        CarRun(SPEED_DUTY, SPEED_DUTY);
}

//
void CarBack(void)
{
        CarRun(-SPEED_DUTY, -SPEED_DUTY);
}

//
void CarLeft(void)
{
        CarRun(-SPEED_DUTY, SPEED_DUTY);
}

//
void CarRight(void)
{
        CarRun(SPEED_DUTY, -SPEED_DUTY);
}

//ֹͣ
void CarStop(void)
{
        CarRun(0, 0);
}
	behind_left_speed_duty=-20;
	behind_right_speed_duty=SPEED_DUTY+10;//增加后轮驱动力
}

//向右
void CarRight(void)
{
	front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=-20;
	behind_left_speed_duty=SPEED_DUTY+10;//增加后轮驱动力
	behind_right_speed_duty=-20;
}

//停止
void CarStop(void)
{
	front_left_speed_duty=0;
	front_right_speed_duty=0;
	behind_left_speed_duty=0;
	behind_right_speed_duty=0;
}

void MotorInit(void)
{
	MotorGPIO_Configuration();
	CarStop();
}

