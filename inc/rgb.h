// rgb.h

#include <stdio.h>
#include <stdint.h>
#include "stm32f30x_conf.h"
#include "shipcontrol.h"

#ifndef _RGB_H_
#define _RGB_H_

void setupRGB();
void setRGB(char colour);
void RGBStatus(ship_t * ship);

#endif
