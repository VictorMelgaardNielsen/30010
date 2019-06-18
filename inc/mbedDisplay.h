#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "joystick.h"

#ifndef _MBEDDISPLAY_H_
#define _MBEDDISPLAY_H_

void menu_init();
uint8_t choose_diff();
void display_stats(uint8_t health, uint8_t kills);


#endif
