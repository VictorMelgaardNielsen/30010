#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include "variabel.h"


#ifndef _ASCIIART_h_
#define _ASCIIART_h_

void drawFinalBoss (int8_t x, int8_t y);
void drawGameOver(int8_t x, int8_t y);
void drawNuke(nuke_t nuke);
void drawHeart(heart_t heart);

#endif
