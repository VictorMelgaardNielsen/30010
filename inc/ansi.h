#include <stdio.h>
#include <stdint.h>
#include "Lutfile.h"

#ifndef _ANSI_H_
#define _ANSI_H_

typedef struct {
    int32_t x, y, vx, vy;
} ball_t;
typedef struct{
    int32_t x, y;
} vector_t;

void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrscr();
void clreol();
void gotoxy (uint8_t x, uint8_t y);
void underline (uint8_t on);
void blink (uint8_t on);
void inverse (uint8_t on);
void up(uint8_t x);
void down(uint8_t x);
void forwards(uint8_t x);
void backwards(uint8_t x);
void windows (uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char title[], char a, char b);
void printFix(int32_t i);
void course(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void ball(ball_t *b);
void rotateVector(vector_t (*v),int32_t a);
void drawCounter(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, int nice);


#endif
