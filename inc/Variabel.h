#include <stdio.h>
#include <stdint.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include <stdlib.h>

#ifndef _VARIABEL_H_
#define _VARIABEL_H_

typedef struct {
    int32_t x, y;
} meteor_t;
void drawMeteor(int8_t x, int8_t y);
//void gravityCheck(bullet_t *b, meteor_t *m);
//void powerUp_Nuke (spaceship_t x);
void use_Nuke(int8_t a);
//void powerUp_Bullets(spaceship_t x);
void coordinatRandomiser(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, meteor_t *m);

#endif

