#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "joystick.h"
#include "shipcontrol.h"

#ifndef _MBEDINTERACT_H_
#define _MBEDINTERACT_H_

void menu_init();
void choose_diff(ship_t * ship, uint8_t * highscoreMulti);
void display_stats(uint8_t health, uint8_t kills);
void gameOver(uint8_t kills, uint8_t highScoreMulti);

#endif
