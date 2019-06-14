#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"

#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct {
    uint8_t hour;
    uint8_t mint;
    uint8_t sec;
    uint8_t msec;
} timee_t;

volatile timee_t timer2;

int flaglcd;

void setuptimer();
void starttimer();
void stoptimer();
void TIM2_IRQHandler(void);
char * readTerminal(char a[]);

#endif
