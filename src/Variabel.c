#include "variabel.h"

void gravityCheckBullet(bullet_t b[], meteor_t m[]) {
    int i, j;

    for(j = 0; j < 3; j++) {
        for(i = 0; i < 5; i++) {
            if (b[i].x < m[j].x && b[i].x > m[j].x - 4 && b[i].y < m[j].y && b[i].y > m[j].y - 2) {
                b[i].vx += 1;
                b[i].vy += 1;
            }

            if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y < m[j].y && b[i].y > m[j].y - 2) {
                b[i].vy += 1;
            }

            if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 14 && b[i].y < m[j].y && b[i].y > m[j].y - 2) {
                b[i].vx += -1;
                b[i].vy += 1;
            }

            if (b[i].x < m[j].x && b[i].x > m[j].x - 4 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                b[i].vx += 1;
            }

            if (b[i].x < m[j].x && b[i].x > m[j].x - 4 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 6) {
                b[i].vx += 1;
                b[i].vy += -1;
            }

            if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 6) {
                b[i].vy += -1;
            }

            if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 14 && b[i].y > m[j].y + 4 && b[i].y < m[j].y + 6) {
                b[i].vx += -1;
                b[i].vy += -1;
            }

            if (b[i].x > m[j].x + 10 && b[i].x < m[j].x + 14 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                b[i].vx += -1;
            }

            if (b[i].x >= m[j].x && b[i].x <= m[j].x + 10 && b[i].y >= m[j].y && b[i].y <= m[j].y + 4) {
                b[i].x = -1;
                b[i].y = -1;
            }
        }
    }
}

void gravityCheckShip(ship_t *ship, meteor_t m[]) {
    int j;


    for (j = 0; j < 3; j++) {
        if (ship->x < m[j].x && ship->x > m[j].x - 4 && ship->y < m[j].y && ship->y > m[j].y - 2) {
            ship->vx += 1;
            ship->vy += 1;
        }

        if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y < m[j].y && ship->y > m[j].y - 2) {
            ship->vy += 1;
        }

        if (ship->x > m[j].x + 10 && ship->x < m[j].x + 14 && ship->y < m[j].y && ship->y > m[j].y - 2) {
            ship->vx += -1;
            ship->vy += 1;
        }

        if (ship->x < m[j].x && ship->x > m[j].x - 4 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
            ship->vx += 1;
        }

        if (ship->x < m[j].x && ship->x > m[j].x - 4 && ship->y > m[j].y + 4 && ship->y < m[j].y + 6) {
            ship->vx += 1;
            ship->vy += -1;
        }

        if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y > m[j].y + 4 && ship->y < m[j].y + 6) {
            ship->vy += -1;
        }

        if (ship->x > m[j].x + 10 && ship->x < m[j].x + 14 && ship->y > m[j].y + 4 && ship->y < m[j].y + 6) {
            ship->vx += -1;
            ship->vy += -1;
        }

        if (ship->x > m[j].x + 10 && ship->x < m[j].x + 14 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
            ship->vx += -1;
        }

        if (ship->x >= m[j].x && ship->x <= m[j].x + 10 && ship->y >= m[j].y && ship->y <= m[j].y + 4) {
            ship->healthpoints = 0;
        }
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







