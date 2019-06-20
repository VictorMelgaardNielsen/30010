#include "variabel.h"

void gravityCheckBullet(bullet_t b[], meteor_t m[]) {
    int i = 0, j=   0;

    while(j < 3){
        while (i < 5) {
            if (flagravity == 1) {
                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    b[i].vx += 1;
                    b[i].vy += 1;
                }

                if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    b[i].vy += 1;
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y < m[j].y && b[i].y > m[j].y - 5) {
                    b[i].vx += -1;
                    b[i].vy += 1;
                }

                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    b[i].vx += 1;
                }

                if (b[i].x < m[j].x && b[i].x > m[j].x - 10 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    b[i].vx += 1;
                    b[i].vy += -1;
                }

                if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    b[i].vy += -1;
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 9) {
                    b[i].vx += -1;
                    b[i].vy += -1;
                }

                if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 20 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    b[i].vx += -1;
                }



            flagravity = 0;
            }

             if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                    b[i].x = -1;
                    b[i].y = -1;

                }
                i++;
        }
        j++;

    }
}

void gravityCheckShip(ship_t *ship, meteor_t m[]) {
    int j;
if (flagravityship == 1) {
    for (j = 0; j < 3; j++) {

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->x += 1;
                ship->y += 1;
            }

            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->y += 1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y < m[j].y && ship->y > m[j].y - 5) {
                ship->x += -1;
                ship->y += 1;
            }

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->x += 1;
            }

            if (ship->x < m[j].x && ship->x > m[j].x - 10 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->x += 1;
                ship->y += -1;
            }

            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->y += -1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y > m[j].y + 4 && ship->y < m[j].y + 9) {
                ship->x += -1;
                ship->y += -1;
            }

            if (ship->x > m[j].x + 10 && ship->x < m[j].x + 20 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->x += -1;
            }
            if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
                ship->healthpoints = 0;
            }


        }


        flagravityship = 0;
    }
}

/*

void powerUp_Nuke (spaceship_t x) {
    counter_t nuke = 0;

    if (x.x == n.x && x.y == n.y) {
        nuke++;
    }

}

void use_Nuke(int8_t a) {
    if (n == 1) {
    enemyship_t e;
    e.life--;
    }
}

void update_Bullets(spaceship_t x) {
    if (x.x == laser.x && x.y == laser.y) {
        bullets.style = 2;
    }

    if ()

}

*/







