// variabel.c

#include "variabel.h"

void gravityCheckBullet(bullet_t b[], meteor_t m[]) {
    int i, j;

    if (flagravity == 1) {
        for (j = 0; j < 3; j++){
            for (i = 0; i < 5; i++) {
                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    if (b[i].vx < 3 && b[i].vy < 2) {
                        b[i].vx += 2;
                        b[i].vy += 1;
                    }
                }

                if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    if (b[i].vy < 2) {
                        b[i].vy += 1;
                    }
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    if (b[i].vx > -3 && b[i].vy < 2) {
                        b[i].vx += -2;
                        b[i].vy += 1;
                    }
                }

                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    if (b[i].vx < 3) {
                        b[i].vx += 2;
                    }
                }

                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    if (b[i].vx < 3 && b[i].vy > -2) {
                        b[i].vx += 2;
                        b[i].vy += -1;
                    }
                }

                if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    if (b[i].vy > -3) {
                        b[i].vy += -2;
                    }
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    if (b[i].vx > -3 && b[i].vy > -2) {
                        b[i].vx += -2;
                        b[i].vy += -1;
                    }
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    if (b[i].vx > -3) {
                        b[i].vx += -2;
                    }
                }
                /*
                if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    b[i].x = -1;
                    b[i].y = -1;
                }
                */
            }
        }
    flagravity = 0;
    }
}

void meteorBulletHit(bullet_t b[], meteor_t m[]) {
    int i, j;

    for (j = 0; j < 3; j++){
        for (i = 0; i < 5; i++) {
            if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    b[i].x = -1;
                    b[i].y = -1;
            }
        }
    }
}

void gravityCheckShip(ship_t *ship, meteor_t m[]) {
    int j;
if (flagravityship == 1) {
    for (j = 0; j < 3; j++) {

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->x += 2;
                ship->y += 1;
            }

            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->y += 1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->x += -2;
                ship->y += 1;
            }

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->x += 2;
            }

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->x += 2;
                ship->y += -1;
            }

            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->y += -1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->x += -2;
                ship->y += -1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->x += -2;
            }
            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->healthpoints = 0;
            }


        }


        flagravityship = 0;
    }
}


void enemyHitCheck(bullet_t bullet[], ship_t enemy[], ship_t * ship, nuke_t *nuke) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j ++) {
            if ((bullet[i].x == enemy[j].x || bullet[i].x == enemy[j].x + 1) && bullet[i].y == enemy[j].y) {
                ship->killcount++;
                if (ship->killcount%10 == 0) {
                    nuke->x = enemy[j].x;
                    nuke->y = enemy[j].y;
                    nuke->available = 1;
                }
                enemy[j].healthpoints = 0;
                enemy[j].x = -2;
                enemy[j].y = -2;
                bullet[i].x = -1;
                bullet[i].y = -1;
            }
        }
    }
}

void enemiesDead(ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    int i, alive = 0;

    for (i = 0; i < 5; i++) {
        if (enemy[i].healthpoints == 1) {
            alive++;
        }
    }

    if (alive == 0) {
        initEnemy(enemy, x1, y1, x2, y2);
    }
}

//Power Ups!

void powerUp_Nuke(ship_t * ship, nuke_t * nuke) {
    if (ship->x == nuke->x + 3 && ship->y == nuke->y + 1) {
        ship->powerup = 1;
        nuke->available = 0;
    }
}

void use_Nuke(ship_t * ship, ship_t enemy[], nuke_t * nuke) {
    int i;

    if (ship->powerup == 1) {
        nuke->x = -3;
        nuke->y = -3;
        for (i = 0; i < 5; i++) {
            enemy[i].healthpoints = 0;
        }
        ship->killcount += 5;
        ship->powerup = 0;
    }

}

void initHP (heart_t *heart) {
    heart->x = 79;
    heart->y = 19;
}


void getHP(ship_t * ship, heart_t * heart, timee_t time) {
    if (time.sec == 59) {
        initHP(heart);
        heart->available = 1;

    }
    if ((ship->x == heart->x+3 || ship->x == heart->x+4) && ship->y == heart->y+2) {
        if (ship->healthpoints < 3) {
        ship->healthpoints += 1;
        heart->x = -3;
        heart->y = -3;
        }
        heart->available = 0;
    }

}










