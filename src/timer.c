#include "timer.h"
#include <string.h>


//Setup for timer 2 to generate square waves for various pitches.
void setupTimer2() {
    RCC->APB1ENR |= 0x00000001; // Enable clock line to timer 2;
    TIM2->CR1 = 0x0000; // Disable timer
    TIM2->ARR = 1000; // Set auto reload value
    TIM2->PSC = 0; // Set pre-scaler value
    TIM2->CR1 |= 0x0001; // Enable timer

    TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
    TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
    TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
    TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
    TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
    TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
    TIM2->CCMR2 |= TIM_OCPreload_Enable;
    TIM2->CCR3 = 500; // Set duty cycle to 50 %

    //Configuration for alternate function
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // Enable clock line for GPIO bank B
    GPIOB->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
    GPIOB->MODER |= (0x00000002 << (10 * 2)); // Set mode register

    //Specify alternative function 1, PWM. output.
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);
}

//Buzzer jingle melody indicating game started, A Major.
void buzzer(uint8_t * flagbuzzer) {
    if (timer15.sec == 1 && *flagbuzzer == 0) {//Use of timer 15 to play a new frequency every one second.
        setFreq(440);
        *flagbuzzer = 1;
    }
    if (timer15.sec == 2 && *flagbuzzer == 1) {
        setFreq(554);
        *flagbuzzer = 2;
    }
    if (timer15.sec == 3 && *flagbuzzer == 2) {
        setFreq(659);
        *flagbuzzer = 3;
    }
    if (timer15.sec == 4 && *flagbuzzer == 3) {
        setFreq(880);
        *flagbuzzer = 4;
    }
    if (timer15.sec == 5 && *flagbuzzer == 4) {
        stopTimer2();
        *flagbuzzer = 5;
    }
}

void startTimer2() {
    TIM2->CR1 |= 0x0001;
}

void stopTimer2() {
    TIM2->CR1 &= ~(0x0001);
}

//The input value freq sets the frequency of the piezo buzzer.
void setFreq(uint16_t freq) {
    uint32_t reload = 64e6 / freq / (0 + 1) - 1;
    TIM2->ARR = reload; // Set auto reload value
    TIM2->CCR3 = reload/2; // Set compare register
    TIM2->EGR |= 0x01; // Write to EGR register, to inform timer that the values have been changed.
 }

//Setup of timer 15
void setupTimer15() {
    timer15.hour = 0;
    timer15.mint = 0;
    timer15.sec = 0;
    timer15.msec = 0;

    RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 2;
    TIM15->CR1 = 0x0000;
    TIM15->ARR = 63999; // Set auto reload value
    TIM15->PSC = 9; // Set pre-scaler value
    TIM15->DIER |= 0x0001; // Enable timer interrupt

    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0);
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

    TIM15->CR1 |= 0x0001; // Enable timer
}

void restartTimer15() {
    timer15.hour = 0;
    timer15.mint = 0;
    timer15.sec = 0;
    timer15.msec = 0;
}

void startTimer15() {
    TIM15->CR1 |= 0x0001;
}

void stopTimer15() {
    TIM15->CR1 &= ~(0x0001);
}

//Tells the STM32 what to do whenever the timer interrupt is triggered.
void TIM1_BRK_TIM15_IRQHandler() {
    timer15.msec += 1;

    //Flag for enemy spaceship update
    if (timer15.msec%25 == 0) {
        flagenemy = 1;
    }

    //Flag for ship bullet speed
    if (timer15.msec%10 == 0) {
        flagbullettimer = 1;
    }

    //Flag for bullet gravity update
    if (timer15.msec%25 == 0) {
        flagravity = 1;
    }

    //Flag for spaceship gravity update
    if (timer15.msec%50 == 0) {
        flagravityship = 1;
    }

    //Flag for enemy ship bullet speed
    if (timer15.msec%10 == 0) {
        flagenemybullettimer = 1;
    }

    //Flag for game refresh rate.
    if (timer15.msec%10 == 0) {
        flagrefreshrate = 1;
    }

    if (timer15.msec == 100) {
        timer15.msec = 0;
        timer15.sec += 1;
    }
    if (timer15.sec == 60) {
        timer15.sec = 0;
        timer15.mint += 1;
    }
    if (timer15.mint == 60) {
        timer15.mint = 0;
        timer15.hour += 1;
    }

    //lcd flag
    if (timer15.msec%25 == 0) {
        flaglcd = 1;
    }
    TIM15->SR &= ~(0x0001);
 }
















