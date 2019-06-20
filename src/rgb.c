#include "rgb.h"


void setupRGB(){
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

   //OUTPUTS
    // Set pin PB4 to output red LED
    GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2));
    GPIOB->OSPEEDR |=  (0x00000002 << (4 * 2));

    GPIOB->OTYPER &= ~(0x0001 << (4));
    GPIOB->OTYPER &= ~(0x0000 << (4));

    GPIOB->MODER &= ~(0x00000003 << (4 * 2));
    GPIOB->MODER |=  (0x00000001 << (4 * 2));

     // Set pin PC7 to output green LED
    GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2));
    GPIOC->OSPEEDR |=  (0x00000002 << (7 * 2));

    GPIOC->OTYPER &= ~(0x0001 << (7));
    GPIOC->OTYPER &= ~(0x0000 << (7));

    GPIOC->MODER &= ~(0x00000003 << (7 * 2));
    GPIOC->MODER |=  (0x00000001 << (7 * 2));

    // Set pin PA9 to output blue LED
    GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2));
    GPIOA->OSPEEDR |=  (0x00000002 << (9 * 2));

    GPIOA->OTYPER &= ~(0x0001 << (9));
    GPIOA->OTYPER &= ~(0x0000 << (9));

    GPIOA->MODER &= ~(0x00000003 << (9 * 2));
    GPIOA->MODER |=  (0x00000001 << (9 * 2));
}

void setRGB(char colour) {

    if (colour == 'r') {
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
        GPIOA->ODR |= (0x0001 << 9);

    } else if (colour == 'g') {
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
        GPIOA->ODR |= (0x0001 << 9);

    } else if (colour == 'b') {
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
        GPIOA->ODR &= ~(0x0001 << 9);

    } else if (colour == 'c') {
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
        GPIOA->ODR &= ~(0x0001 << 9);

    } else if (colour == 'm') {
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
        GPIOA->ODR &= ~(0x0001 << 9);

    } else if (colour == 'y') {
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
        GPIOA->ODR |= (0x0001 << 9);

    } else if (colour == 'w') {
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
        GPIOA->ODR &= ~(0x0001 << 9);

    } else if (colour == 's') {
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
        GPIOA->ODR |= (0x0001 << 9);
    }


}

