#ifndef __MOTOR_H_
#define __MOTOR_H_

extern char front_right_speed_duty;
extern char behind_left_speed_duty;
extern char behind_right_speed_duty;

void CarMove(void);
void CarRun(int left_speed, int right_speed);
void CarGo(void);
void CarBack(void);
void CarLeft(void);
void CarRight(void);
void CarStop(void);
void CarRight(void);
void CarStop(void);
void MotorInit(void);
#endif

