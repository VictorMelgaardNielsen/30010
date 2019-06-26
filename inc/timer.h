#include <stdio.h>
#include <stdint.h>
#include "stm32f30x_conf.h"

#ifndef _TIMER_H_
#define _TIMER_H_

//------------------------------Structs-----------------------------
typedef struct {
    uint8_t hour;
    uint8_t mint;
    uint8_t sec;
    uint8_t msec;
} timee_t;

volatile timee_t timer15;

//------------------------------Global variables--------------------
int flagenemy;
int flaglcd;
int flagbullettimer;
int flagrefreshrate;
int flagravity;
int flagravityship;
int flagenemybullettimer;

//------------------------------Functions---------------------------
void setupTimer2();
void startTimer2();
void stopTimer2();
void setFreq(uint16_t freq);
void buzzer(uint8_t * flagbuzzer);

void setupTimer15();
void restartTimer15();
void startTimer15();
void stopTimer15();
void TIM1_BRK_TIM15_IRQHandler();

#endif
