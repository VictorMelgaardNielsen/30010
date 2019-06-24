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

typedef struct {
    uint8_t x, y;
} nuke_t;

void gravityCheckBullet(bullet_t b[], meteor_t m[]);
void meteorBulletHit(bullet_t b[], meteor_t m[]);
void gravityCheckShip(ship_t *ship, meteor_t m[]);
void powerUp_Nuke(ship_t * ship, nuke_t nuke);
void enemiesDead(ship_t enemy[]);
void use_Nuke(ship_t * ship, ship_t enemy[]);
void enemyHitCheck(bullet_t bullet[], ship_t enemy[], ship_t * ship);

#endif

