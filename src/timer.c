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

void restarttimer() {
    timer2.hour = 0;
    timer2.mint = 0;
    timer2.sec = 0;
    timer2.msec = 0;
}

void starttimer() {
    TIM2->CR1 |= 0x0001;
}

void stoptimer() {
    TIM2->CR1 &= ~(0x0001);
}

//Tells the STM32 what to do whenever the timer interrupt is triggered.
void TIM2_IRQHandler(void) {
<<<<<<< HEAD
<<<<<<< refs/remotes/origin/master

=======
>>>>>>> Min branch åbnes op!
=======

>>>>>>> menu-branch
    timer2.msec += 1;

    //Flag for enemy spaceship update
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

<<<<<<< HEAD
<<<<<<< refs/remotes/origin/master
=======



>>>>>>> Min branch åbnes op!
=======
>>>>>>> menu-branch
    TIM2->SR &= ~(0x0001);
}

//Read terminal takes an empty char array and returns the text written in terminal when enter is pressed
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

//Command takes a returns a different number, depending on whether the user inputs
//"start". "stop", "split", "reset", or "help".
uint8_t timerCommand() {
    int flagStartStop = 0;
    timee_t split1;
    split1.hour = 0;
    split1.mint = 0;
    split1.sec = 0;
    split1.msec = 0;

    timee_t split2;
    split2.hour = 0;
    split2.mint = 0;
    split2.sec = 0;
    split2.msec = 0;
    uint8_t number = 0;
    int i = 0;
    char s1[10] = {'0','0','0','0','0','0','0','0','0','0'};
    char s2[10] = {'s','t','a','r','t','0x0D','0','0','0','0'};
    char s3[10] = "";
    char s4[10] = "start";

    while (i < 10) {
        if(uart_get_count() > 0) {
            s1[i] = uart_get_char();
            printf("%c",s1[i]);
            if (s1[i] == 0x0D) {
                if(strcmp(s1, s2) == 0) {
                    number = 0;
                    return number;
                }
                else if(strcmp(s1, s2) == 0) {
                    number = 1;
                    return number;
                }
                else if(strcmp(s1, s2) == 0) {
                    number = 2;
                    return number;
                }
                else if(strcmp(s1, s2) == 0) {
                    number = 3;
                    return number;
                }
                else if(strcmp(s1, s2) == 0) {
                    number = 4;
                    return number;
                }
            }
            i++;
        }
    }

}

//commandHelp
void timerCommandHelp() {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n","The list of commands are:","start","stop","split1","split2","reset","help");
}































