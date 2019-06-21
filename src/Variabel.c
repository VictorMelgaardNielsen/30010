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


void enemyHitCheck(bullet_t bullet[], ship_t enemy[], ship_t * ship) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j ++) {
            if (bullet[i].x == enemy[j].x && bullet[i].y == enemy[j].y) {
                enemy[j].healthpoints = 0;
                enemy[j].x = -2;
                enemy[j].y = -2;
                bullet[i].x = -1;
                bullet[i].y = -1;
                ship->killcount++;
            }
        }
    }
}



//Power Ups!

void powerUp_Nuke(ship_t * ship, nuke_t nuke) {
    if (ship->x == nuke.x && ship->y == nuke.y) {
        ship->powerup = 1;
    }
}

void use_Nuke(ship_t * ship, ship_t enemy[]) {
    int i;

    if (ship->powerup == 1) {
        for (i = 0; i < 5; i++) {
            enemy[i].healthpoints = 0;
            ship->killcount += 5;
        }
        ship->powerup = 0;
    }

}










