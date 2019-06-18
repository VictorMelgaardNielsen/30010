#include "timer.h"
#include <string.h>



void setuptimer() {

    timer2.hour = 0;
    timer2.mint = 0;
    timer2.sec = 0;
    timer2.msec = 0;

    RCC->APB1ENR |= RCC_APB1Periph_TIM2;
    TIM2->CR1 = 0x0000; // configure timer 2
    TIM2->ARR = 639999; // 10*10^-3*64*10^6 - 1
    TIM2->PSC = 0x0000; // set prescale
    TIM2->DIER |= 0x0001; // Enable timer 2 interupts

    NVIC_SetPriority(TIM2_IRQn, 0000);
    NVIC_EnableIRQ(TIM2_IRQn);
}

void starttimer() {
    TIM2->CR1 |= 0x0001;
}

void stoptimer() {
    TIM2->CR1 &= ~(0x0001);
}

void TIM2_IRQHandler(void) {

    timer2.msec += 1;

    if (timer2.msec%50 == 0) {
        flagenemy = 1;
    }

    if (timer2.msec == 100) {
        timer2.msec = 0;
        timer2.sec += 1;
    }
    if (timer2.sec == 60) {
        timer2.sec = 0;
        timer2.mint += 1;
    }
    if (timer2.mint == 60) {
        timer2.mint = 0;
        timer2.hour += 1;
    }

    //lcd flag
    if (timer2.msec%25 == 0) {
        flaglcd = 1;
    }

    TIM2->SR &= ~(0x0001);
}

/*
char * readTerminal(char a[]){
    int i = 0;
    while (i < 10) {
        if(uart_get_count() > 0) {
            a[i] = uart_get_char();
            if (a[i] == 0x0D) {
                a[i] = 0x00;
            return a;
            }
            printf("%c",a[i]);
            i++;
        }
    }
    return a;
}
*/

uint8_t command(char s1[]) {
    uint8_t number = 0;
    int i = 0;
    char s2[10] = {'s','t','a','r','t','0','0','0','0','0'};
    while (i < 10) {
        if(uart_get_count() > 0) {
            s1[i] = uart_get_char();
            printf("%c",s1[i]);
            if (s1[i] == 0x0D) {
                if(strcmp(s1, s2) == 0) {
                    number = 1;
                    return number;
                }
                else {
                    printf("%s", "no command");
                }
            }
        i++;
        }
    }
}
































