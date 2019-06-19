#include <stdio.h>
#include <stdint.h>
#include "ansi.h"

#ifndef _ANGLES_H_
#define _ANGLES_H_

typedef struct {
    int x;
} counter_t;
int cnt;
int32_t expand(int32_t i);
int32_t sine (int32_t a);
int32_t cose (int32_t a);
void updateposition(ball_t *v);
void initVector(vector_t (*v));
int counter(counter_t *t, ball_t *v, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void ballcheck(ball_t *b, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void setLED(char colour);

#endif
