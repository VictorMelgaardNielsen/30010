#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include "timer.h"

#ifndef _SHIPCONTROL_H_
#define _SHIPCONTROL_H_


//------------------------------Structs-----------------------------
typedef struct {
    int16_t x, y, vx, vy;
    uint8_t powerup;
    uint8_t healthpoints;
    uint8_t killcount;
} ship_t;

typedef struct {
    int16_t x, y, vx, vy;
} bullet_t;


typedef struct {
    uint8_t diffValue, counterValue;
} diff_t;


//------------------------------Functions---------------------------
void shipSetup(ship_t * ship);
uint8_t shipControl(ship_t * ship, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t * buzzkey);
void printShip(ship_t * ship);
void bulletSetup(bullet_t bullet[]);
void updateBullet(ship_t * ship, bullet_t * bullet, uint8_t flagbullet, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void printBullet(bullet_t * bullet);
void eraseship (ship_t * ship);
void erasebullet (bullet_t bullet[]);
void bulletsLeft(bullet_t bullet[], uint8_t x2, uint8_t y2);
void initEnemy(ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void printEnemy(ship_t enemy[]);
void updateEnemyPosition(ship_t enemy[], diff_t * difficulty, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void initEnemy(ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void printEnemy(ship_t enemy[]);
void updateenemyBullet(ship_t * ship, bullet_t enemybullet[], ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void updateEnemyPosition(ship_t enemy[], diff_t * difficulty, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);


#endif
