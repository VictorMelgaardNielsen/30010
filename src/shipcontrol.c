#include "shipcontrol.h" //headeren inkluderes i c filen
#include <string.h>

void shipSetup(ship_t * ship) {
    ship->x = 10;
    ship->y = 10;
    ship->vx = 0;
    ship->vy = 0;
    ship->angle = 0; // The ship can be controlled in eight different directions.
    ship->powerup = 0;
}


void bulletSetup(bullet_t * bullet[4]) {
    for (int i = 0; i < sizeof(bullet)/sizeof(bullet[0]); i++) {
        bullet[i]->x = -1;
        bullet[i]->y = -1;
        bullet[i]->vx = 0;
        bullet[i]->vy = 0;
        bullet[i]->angle = 0;
    }
}


//Ship control from terminal
int shipControl(ship_t * ship) {
    int flagbullet = 0;
    if (uart_get_count() > 0) {
        char s[1] = {'0','0'};
        s[0] = uart_get_char();
        if (s[0] == 'a') {
            ship->angle -= 1;
            if (ship->angle < 0) {
                ship->angle = 7;
            }
        }
        if (s[0] == 'd') {
            ship->angle += 1;
            if (ship->angle >= 8) {
                ship->angle = 0;
            }
        }
        if (s[0] == 'w') {
            if (ship->angle == 0) {
                ship->y -= 1;
            }
            if (ship->angle == 1) {
                ship->x += 1;
                ship->y -= 1;
            }
            if (ship->angle == 2) {
                ship->x += 1;
            }
            if (ship->angle == 3) {
                ship->x += 1;
                ship->y += 1;
            }
            if (ship->angle == 4) {
                ship->y += 1;
            }
            if (ship->angle == 5) {
                ship->x -= 1;
                ship->y += 1;
            }
            if (ship->angle == 6) {
                ship->x -= 1;
            }
            if (ship->angle == 7) {
                ship->x -= 1;
                ship->y -= 1;
            }
        }
        if (s[0] == 's') {
            flagbullet = 1;
            return flagbullet;
        }
    }
}

//Print ship according to its angle.
void printShip(ship_t * ship) {
    gotoxy(ship->x, ship->y);
    if (ship->angle == 0) {
        printf("^");
    }
    if (ship->angle == 1) {
        printf("/");
    }
    if (ship->angle == 2) {
        printf(">");
    }
    if (ship->angle == 3) {
        printf("\\");
    }
    if (ship->angle == 4) {
        printf("|");
    }
    if (ship->angle == 5) {
        printf("/");
    }
    if (ship->angle == 6) {
        printf("<");
    }
    if (ship->angle == 7) {
        printf("\\");
    }


}

void createBullet(ship_t * ship, bullet_t * bullet[4], int flagbullet, int x1, int y1, int x2, int y2) {
    if (flagbullet == 1) {
        for (int i = 0; i < sizeof(bullet)/sizeof(bullet[0]); i++) {
            if (bullet[i]->x == -1) {
                bullet[i]->x = ship->x;
                bullet[i]->y = ship->y;
                bullet[i]->angle = ship->angle;
            }
        }

    }
    for (int i = 0; i < sizeof(bullet)/sizeof(bullet[0]); i++) {
        if ((bullet[i]->x > x1 && bullet[i]->x < x2) && (bullet[i]->y > y1 && bullet[i]->y < y2)) {
            switch (bullet[i]->angle)
            {
                case 0:
                   bullet[i]->y -= 1;
                break;

                case 1:
                   bullet[i]->x += 1;
                   bullet[i]->y -= 1;
                break;

                case 2:
                   bullet[i]->x += 1;
                break;

                case 3:
                   bullet[i]->y -= 1;
                break;

                case 4:
                   bullet[i]->y += 1;
                break;

                case 5:
                    bullet[i]->x -= 1;
                    bullet[i]->y += 1;
                break;

                case 6:
                   bullet[i]->x -= 1;
                break;

                case 7:
                    bullet[i]->x -= 1;
                    bullet[i]->y -= 1;
                break;
            }

        }
        else {
            bullet[i]->x = -1;
            bullet[i]->y = -1;
        }
    }
}

void printBullet(bullet_t * bullet[4]) {
    for (int i = 0; i < sizeof(bullet)/sizeof(bullet[0]); i++) {
        if (bullet[i]->x != 0) {
            gotoxy(bullet[i]->x, bullet[i]->y);
            printf("a");
        }
    }
}






//lav et array af bullets.

//bullet->x > 0 && bullet->y > 0 && bullet->x < 60 && bullet->y < 60













// omkring bullets, hvis velocity bliver 0, slettes bullet.
// power up, bouncing balls.
