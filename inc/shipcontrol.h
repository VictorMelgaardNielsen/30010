#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"

#ifndef _SHIPCONTROL_H_
#define _SHIPCONTROL_H_

typedef struct {
    int32_t x, y, vx, vy;
    int8_t angle;
    uint8_t powerup;
} ship_t;

void shipSetup(ship_t * ship);
void shipControl(ship_t * ship, ball_t * bullet);
void printShip(ship_t * ship);
void bulletSetup(ball_t * bullet);
void printBullet(ship_t * ship, ball_t * bullet);



#endif
