#include "joystick.h"

void setupjoystick(){
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

    // PC0 set to input
    GPIOC->MODER &= ~(0x00000003 << (0 * 2));
    GPIOC->MODER |=  (0x00000000 << (0 * 2));

    GPIOC->PUPDR &= ~(0x00000003 << (0 * 2));
    GPIOC->PUPDR |=  (0x00000002 << (0 * 2));

    // PA4 set to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2));
    GPIOA->MODER |=  (0x00000000 << (4 * 2));

    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2));
    GPIOA->PUPDR |=  (0x00000002 << (4 * 2));

    // PB5 set to input
    GPIOB->MODER &= ~(0x00000003 << (5 * 2));
    GPIOB->MODER |=  (0x00000000 << (5 * 2));

    GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
    GPIOB->PUPDR |=  (0x00000002 << (5 * 2));

    // PC1 set to input
    GPIOC->MODER &= ~(0x00000003 << (1 * 2));
    GPIOC->MODER |=  (0x00000000 << (1 * 2));

    GPIOC->PUPDR &= ~(0x00000003 << (1 * 2));
    GPIOC->PUPDR |=  (0x00000002 << (1 * 2));

    // PB0 set to input
    GPIOB->MODER &= ~(0x00000003 << (0 * 2));
    GPIOB->MODER |=  (0x00000000 << (0 * 2));

    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2));
    GPIOB->PUPDR |=  (0x00000002 << (0 * 2));
}

uint8_t readJoystick() {
    uint8_t data = 0;
    uint16_t val = 0;

    // PA4 value to bit 0 in data (Up)
    val = GPIOA->IDR & (0x0001 << 4);
    data |= val >> 4;

    // PB0 value to bit 1 in data (Down)
    val = GPIOB->IDR & (0x0001 << 0);
    data |= val << 1;

    // PC1 value to bit 2 in data (Left)
    val = GPIOC->IDR & (0x0001 << 1);
    data |= val << 1;

    // PC0 value to bit 3 in data (Right)
    val = GPIOC->IDR & (0x0001 << 0);
    data |= val << 3;

    // PB5 value to bit 4 in data (Center)
    val = GPIOB->IDR & (0x0001 << 5);
    data |= val >> 1;

    return data;
}
