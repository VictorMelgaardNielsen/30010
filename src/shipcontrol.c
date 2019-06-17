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

void bulletSetup(ball_t * bullet) {
    bullet->x = 0;
    bullet->y = 0;
    bullet->vx = 0;
    bullet->vy = 0;
}

//Ship control from terminal
void shipControl(ship_t * ship, ball_t * bullet) {
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
            bullet->x = ship->x;
            bullet->y = ship->y;
            printBullet(&ship, &bullet);
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

void printBullet(ship_t * ship, ball_t * bullet) {
    bullet->x = ship->x;
    bullet->y = ship->y;
    //while (1) {
        printf("%c", 'a');
        gotoxy(bullet->x, bullet->y);
        if (ship->angle == 0) {
            printf("%c", 'o');
            bullet->y--;
        }
        if (ship->angle == 1) {
            printf("%c", 'o');
            bullet->x++;
            bullet->y--;
     //   }
    }
}



//lav et array af bullets.

//bullet->x > 0 && bullet->y > 0 && bullet->x < 60 && bullet->y < 60













// omkring bullets, hvis velocity bliver 0, slettes bullet.
// power up, bouncing balls.
