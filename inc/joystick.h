#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"


#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

void setupjoystick();
void setupRGB();
uint8_t readJoystick();

#endif
