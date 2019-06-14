#include "ADC.h"


void setupConverter() {
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;

    //PA0 setup
    GPIOA->MODER &= ~(0x00000003 << (0 * 2));
    GPIOA->MODER |=  (0x00000000 << (0 * 2));

    GPIOA->PUPDR &= ~(0x00000003 << (0 * 2));
    GPIOA->PUPDR |=  (0x00000002 << (0 * 2));

    //PA1 setup
    GPIOA->MODER &= ~(0x00000003 << (1 * 2));
    GPIOA->MODER |=  (0x00000000 << (1 * 2));

    GPIOA->PUPDR &= ~(0x00000003 << (1 * 2));
    GPIOA->PUPDR |=  (0x00000002 << (1 * 2));

    RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12;
    RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6;
    RCC->AHBENR |= RCC_AHBPeriph_ADC12;

    ADC1->CR = 0x00000000;
    ADC1->CFGR &= 0xFDFFC007;
    ADC1->SQR1 &= ~ADC_SQR1_L;

    ADC1->CR |= 0x00000000;
    for (int i = 0; i < 1000; i++) {}

    ADC1->CR |= 0x80000000;
    while (!(ADC1->CR & 0x80000000));
    for (int i = 0; i < 100; i++) {}

    ADC1->CR |= 0x00000001;
    while (!(ADC1->ISR & 0x00000001));

}

uint16_t readPA0() {
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

    ADC_StartConversion(ADC1);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0);

    uint16_t x = ADC_GetConversionValue(ADC1);

}

uint16_t readPA1() {
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);

    ADC_StartConversion(ADC1);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0);

    uint16_t x = ADC_GetConversionValue(ADC1);

}


