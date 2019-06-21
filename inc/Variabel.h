#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include <stdlib.h>
#include "shipcontrol.h"

#ifndef _VARIABEL_H_
#define _VARIABEL_H_

typedef struct {
    uint8_t x, y;
} meteor_t;
void gravityCheckBullet(bullet_t b[], meteor_t m[]);
void meteorBulletHit(bullet_t b[], meteor_t m[]);
void gravityCheckShip(ship_t *ship, meteor_t m[]);
//void powerUp_Nuke (spaceship_t x);
//void use_Nuke(int8_t a);
//void powerUp_Bullets(spaceship_t x);

#endif

