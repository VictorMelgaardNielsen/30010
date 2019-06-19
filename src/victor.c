#include "victor.h"
#include "Lutfile.h"
#include "stm32f30x_conf.h"
#include "ansi.h"

cnt = 0;


void updateposition(ball_t *v) {
    (*v).x += (*v).vx;
    (*v).y += (*v).vy;
}

void initVector(vector_t *v) {
    (*v).x = 1;
    (*v).y = 0;
}


int counter(counter_t *t, ball_t *v, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    if (v->x == x1 || v->x == x2+1)
    t->x += 1;

    if (v->y == y1 || v->y == y2+1)
    t->x += 1;
}

void ballcheck(ball_t *b, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
if (b->x == x1 || b->x == x2+1)
    b->vx *= -1;

if (b->y == y1 || b->y == y2+1)
    b->vy *= -1;
}

int32_t expand(int32_t i) {
// Converts an 18.14 fixed point number to 16.16
    return i << 2;
}

int32_t sine (int32_t a) {
    int32_t b;
    int flag = 0;
    if (a < 0) {
        a *= -1;
        flag = 1;
    }

    while (a > 512) {
        a -= 512;
    }

    b = SIN[a];
    if ( flag == 1) {
        b *= -1;
    }
return b;
}

int32_t cose (int32_t a) {
    return sine(a+128);
    }


void setLed(char colour) {

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

void rotateVector(vector_t *v, int32_t a) {
    int32_t xtemp = v->x;
    (*v).x = (*v).x * cose(a) - (*v).y * sine(a);
    (*v).y = xtemp * sine(a) + (*v).y * cose(a);
    printFix(expand((*v).x));
    printf(",");
    printFix(expand((*v).y));
}

/*
void updateEnemyPosition(enemyship_t *enemy, uint8_t *uv) {
    if (cnt == *uv) {
        enemy->x += enemy->vx;
        enemy->y += enemy->vy;
        cnt = 0;
    }
    cnt++;
}
*/
