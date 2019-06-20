#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include "timer.h"

#ifndef _SHIPCONTROL_H_
#define _SHIPCONTROL_H_

typedef struct {
    int32_t x, y, vx, vy;
    int8_t angle;
    uint8_t powerup;
    uint8_t healthpoints;
    uint8_t killcount;
} ship_t;

typedef struct {
    int32_t x, y, vx, vy;
    int8_t angle;
} bullet_t;

void shipSetup(ship_t * ship);
int shipControl(ship_t * ship);
void printShip(ship_t * ship);
void bulletSetup(bullet_t bullet[]);
void updateBullet(ship_t * ship, bullet_t * bullet, int flagbullet, int x1, int y1, int x2, int y2);
void printBullet(bullet_t * bullet);
void eraseship (ship_t * ship);
void erasebullet (bullet_t bullet[]);


#endif
