#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "timer.h"

#ifndef _COURSEDESIGN_H_
#define _COURSEDESIGN_H_


void buildCourse(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, meteor_t m[]);
void course(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void drawCounter(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, int nice);
void ball(ball_t *b);
void drawMeteor(int8_t x, int8_t y);
void initMeteor(meteor_t m[]);
#end if
