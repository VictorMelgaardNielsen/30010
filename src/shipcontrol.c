#include "shipcontrol.h" //Headeren inkluderes i c filen
#include <string.h>

void shipSetup(ship_t * ship) {
    ship->x = 10;
    ship->y = 10;
    ship->vx = 1;
    ship->vy = 0;
    ship->powerup = 0;
}


void bulletSetup(bullet_t bullet[]) {
    for (int i = 0; i < 5; i++) {
        bullet[i].x = -1;
        bullet[i].y = -1;
        bullet[i].vx = 0;
        bullet[i].vy = 0;
    }
}

//Ship control from terminal. The ship can be controlled by flying in eight different directions.
uint8_t shipControl(ship_t * ship, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    uint8_t flagbullet = 0;
    if (uart_get_count() > 0) { // Reads number of characters in the buffer
        char s[0] = {'0'};
        s[0] = uart_get_char(); // Returns the first element of the buffer
        if (s[0] == 'a') {
            if (ship->vx == 0 && ship->vy == -1) { //position 0 out of index 0 to 7
                ship->vx = -2;
                ship->vy = -1;
            } else if (ship->vx == -2 && ship->vy == -1) { // position 7
                ship->vx = -2;
                ship->vy = 0;
            } else if (ship->vx == -2 && ship->vy == 0) { // position 6
                ship->vx = -2;
                ship->vy = 1;
            } else if (ship->vx == -2 && ship->vy == 1) {
                ship->vx = 0;
                ship->vy = 1;
            } else if (ship->vx == 0 && ship->vy == 1) {
                ship->vx = 2;
                ship->vy = 1;
            } else if (ship->vx == 2 && ship->vy == 1) {
                ship->vx = 2;
                ship->vy = 0;
            } else if (ship->vx == 2 && ship->vy == 0) {
                ship->vx = 2;
                ship->vy = -1;
            } else if (ship->vx == 2 && ship->vy == -1) {
                ship->vx = 0;
                ship->vy = -1;
            }
        }
        if (s[0] == 'd') {
            if (ship->vx == 0 && ship->vy == -1) { //position 0 out of index 0 to 7
                ship->vx = 2;
                ship->vy = -1;
            } else if (ship->vx == 2 && ship->vy == -1) { //position 1
                ship->vx = 2;
                ship->vy = 0;
            } else if (ship->vx == 2 && ship->vy == 0) { //position 2
                ship->vx = 2;
                ship->vy = 1;
            } else if (ship->vx == 2 && ship->vy == 1) {
                ship->vx = 0;
                ship->vy = 1;
            } else if (ship->vx == 0 && ship->vy == 1) {
                ship->vx = -2;
                ship->vy = 1;
            } else if (ship->vx == -2 && ship->vy == 1) {
                ship->vx = -2;
                ship->vy = 0;
            } else if (ship->vx == -2 && ship->vy == 0) {
                ship->vx = -2;
                ship->vy = -1;
            } else if (ship->vx == -2 && ship->vy == -1) {
                ship->vx = 0;
                ship->vy = -1;
            }
        }
        if (s[0] == 'w') { // Fly ship forward by updating velocity. If statements limits ship to the boundaries of window size.
            if (ship->x == x1+1) {
                if (ship->vx != -2 && ship->vx != 0){
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->x == x2-1 ) {
                if (ship->vx != 2 && ship->vx != 0){
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->y == y1+1) {
                if (ship->vy != -1) {
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->y == y2-1) {
                if (ship->vy != 1) {
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else {
                ship->x += ship->vx;
                ship->y += ship->vy;
              }
        }
        if (s[0] == 's') { // Shoot
            flagbullet = 1;
            return flagbullet;
        }
    }
}

//Prints ship according to its velocity.
void printShip(ship_t * ship) {
    gotoxy(ship->x, ship->y);
    if (ship->vx == 0 && ship->vy == -1) { //position 0 out of 8
            printf("^");
    } else if (ship->vx == 1 && ship->vy == -1) { //position 1 out of 8
            printf("/");
    } else if (ship->vx == 1 && ship->vy == 0) { //position 2 out of 8
            printf(">");
    } else if (ship->vx == 1 && ship->vy == 1) {
            printf("\\");
    } else if (ship->vx == 0 && ship->vy == 1) {
            printf("v");
    } else if (ship->vx == -1 && ship->vy == 1) {
            printf("/");
    } else if (ship->vx == -1 && ship->vy == 0) {
            printf("<");
    } else if (ship->vx == -1 && ship->vy == -1) {
            printf("\\");
    }
}

void updateBullet(ship_t * ship, bullet_t bullet[], uint8_t flagbullet, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    if (flagbullet == 1) {
        for (int i = 0; i < 5; i++) {
            if (bullet[i].x == -1) { // Creates new bullet, if bullets are available. Available bullets resides at (-1,-1)
                bullet[i].x = ship->x;
                bullet[i].y = ship->y;
                bullet[i].vx = ship->vx*2;
                bullet[i].vy = ship->vy*2;
                break;
            }
        }
    }
    //Updates bullet velocity
    if (flagbullettimer == 1) {
        for (int i = 0; i < 5; i++) {
            if ((bullet[i].x > x1 && bullet[i].x < x2) && (bullet[i].y > y1 && bullet[i].y < y2)) {
                bullet[i].x += bullet[i].vx;
                bullet[i].y += bullet[i].vy;
            }
            else {
                bullet[i].x = -1;
                bullet[i].y = -1;
            }
        }
        flagbullettimer = 0;
    }
}

void printBullet(bullet_t bullet[]) {
    for (int i = 0; i < 5; i++) {
        if (bullet[i].x != 0) {
            gotoxy(bullet[i].x, bullet[i].y);
            printf("o");
        }
    }
}

void bulletsReady(bullet_t bullet[], uint8_t x2, uint8_t y2) {
    uint8_t amountofbullets = 0;
    for (int i = 0; i < 5; i++) {
        if (bullet[i].x == -1) {
        amountofbullets += 1;
        }
    }
    gotoxy(x2-15, y2+1);
    printf("%s%d","Bullets Left: ", amountofbullets);
}


//I rapport tilføj visuel beskrivelse

// sizeof(bullet)/sizeof(bullet[0])

// lav ship grænser, så ship ikke kan flyve ud af banen.

// omkring bullets, hvis velocity bliver 0, slettes bullet.
// power up, bouncing balls.
