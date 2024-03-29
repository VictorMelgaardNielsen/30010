//shipcontrol.c

#include "shipcontrol.h" // Headeren inkluderes i c filen

void shipSetup(ship_t * ship) {
    ship->x = 10;
    ship->y = 10;
    ship->vx = 2;
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

// Reads from terminal. The ship can be controlled by flying in eight different directions. Wasd for control and shoot. Buzzkey at b.
uint8_t shipControl(ship_t * ship, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    uint8_t flagbullet = 0;
    if (uart_get_count() > 0) { // Reads number of characters in the buffer
        char s[0] = {'0'};
        s[0] = uart_get_char(); // Returns the first element of the buffer
        if (s[0] == 'a') {
            if (ship->vx == 0 && ship->vy == -1) { // Position 0 out of index 0 to 7
                ship->vx = -2;
                ship->vy = -1;
            } else if (ship->vx == -2 && ship->vy == -1) { // Position 7
                ship->vx = -2;
                ship->vy = 0;
            } else if (ship->vx == -2 && ship->vy == 0) { // Position 6
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
            return 0;
        }
        if (s[0] == 'd') {
            if (ship->vx == 0 && ship->vy == -1) { // Position 0 out of index 0 to 7
                ship->vx = 2;
                ship->vy = -1;
            } else if (ship->vx == 2 && ship->vy == -1) { // Position 1
                ship->vx = 2;
                ship->vy = 0;
            } else if (ship->vx == 2 && ship->vy == 0) { // Position 2
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
            return 0;
        }
        if (s[0] == 'w') { // Fly ship forward by updating velocity. If statements limits ship to the boundaries of window size.
            if (ship->x < x1+2) {
                if (ship->vx != -2 && ship->vx != 0){
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->x > x2-2 ) {
                if (ship->vx != 2 && ship->vx != 0){
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->y < y1+2) {
                if (ship->vy != -1) {
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else if (ship->y > y2-1) {
                if (ship->vy != 1) {
                    ship->x += ship->vx;
                    ship->y += ship->vy;
                }
            } else {
                ship->x += ship->vx;
                ship->y += ship->vy;
            }
            return 0;
        }
        if (s[0] == 's') { // Shoot
            flagbullet = 1;
            return flagbullet; // Sets flagbullet high, signaling the updateBullet function to update.
        }
        if (s[0] == 'b') { // Buzzkey, pauses game and prints buzz-screen until unpaused.
            stopTimer15();
            clrscr();
            printbuzzscreen();
            while(1) {
                s[0] = uart_get_char();
                if (s[0] == 'b') {
                    break;
                }
            }
            startTimer15();
            return 0;
        }
    }
}

// Prints ship according to its velocity.
void printShip(ship_t * ship) {
    gotoxy(ship->x, ship->y);
    if (ship->vx == 0 && ship->vy == -1) { // Position 0 out of 8
            printf("^");
    } else if (ship->vx == 2 && ship->vy == -1) { // Position 1 out of 8
            printf("/");
    } else if (ship->vx == 2 && ship->vy == 0) { // Position 2 out of 8
            printf(">");
    } else if (ship->vx == 2 && ship->vy == 1) {
            printf("\\");
    } else if (ship->vx == 0 && ship->vy == 1) {
            printf("v");
    } else if (ship->vx == -2 && ship->vy == 1) {
            printf("/");
    } else if (ship->vx == -2 && ship->vy == 0) {
            printf("<");
    } else if (ship->vx == -2 && ship->vy == -1) {
            printf("\\");
    }
}

// Creates and updates user ship bullets according to the user ships velocity.
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
    // Updates bullet velocity
    if (flagbullettimer == 1) {
        for (int i = 0; i < 5; i++) {
            if ((bullet[i].x > x1 && bullet[i].x < x2) && (bullet[i].y > y1 && bullet[i].y < y2)) { // Checks if bullets are within the boundaries of the window.
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

void printBullet(bullet_t bullet[], uint8_t color) {
    for (int i = 0; i < 5; i++) {
        if (bullet[i].x != -1) {
            gotoxy(bullet[i].x, bullet[i].y);
            fgcolor(color);
            printf("o");
            fgcolor(15);
        }
    }
}

// Shows amount of bullets left in the bottom right side of the screen
void bulletsLeft(bullet_t bullet[], uint8_t x2, uint8_t y2) {
    uint8_t amountofbullets = 0;
    for (int i = 0; i < 5; i++) {
        if (bullet[i].x == -1) {
        amountofbullets += 1;
        }
    }
    gotoxy(x2-15, y2+2);
    printf("%s%d","Bullets Left: ", amountofbullets);
}

// Initialize enemy ships, a total of 5.
void initEnemy(ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    int i = 0;
    for (i; i < 5; i++) {
        enemy[i].x = x2-1;
        enemy[i].y = 8 + i*7;
        enemy[i].vx = -2;
        enemy[i].vy = 0;
        enemy[i].healthpoints = 1;
    }
}

void printEnemy(ship_t enemy[]) {
    int i = 0;
    for (i; i < 5; i++) {
        if (enemy[i].healthpoints != 0) {
            gotoxy(enemy[i].x,enemy[i].y);
            printf("<-");
        }
    }
}

// Updates enemy position according to the difficulty of the game level. Higher level makes the enemy ships fly faster.
void updateEnemyPosition(ship_t enemy[], diff_t * difficulty, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    int i;
    if (flagenemy == 1) { // Increments counter value in difficulty struct.
        (difficulty->counterValue)++;
        flagenemy = 0;
    }
    if (difficulty->diffValue == difficulty->counterValue) { // Updates enemy position if when counter value matches difficulty.
        for (i = 0; i < 5; i++) {
            enemy[i].x += enemy[i].vx;
            enemy[i].y += enemy[i].vy;
        }
        flagenemy = 0;
        difficulty->counterValue = 0;
    }
    for (i = 0; i < 5; i++) { // Kills ship enemies, if they reside at enemy border.
        if (enemy[i].x <= x1 || enemy[i].y <= y1 || enemy[i].x >= x2 || enemy[i].y >= y2) {
            enemy[i].healthpoints = 0;
        }
    }
}

// Creates and updates enemy bullets according to the user ship placement on the map.
void updateEnemyBullet(ship_t * ship, bullet_t enemybullet[], ship_t enemy[], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    if (flagenemybullettimer == 1) {
        for (int i = 0; i < 5; i++) {
            int16_t bulletvectorx = ship->x - enemy[i].x; // Calculates vector between ship and enemy ship.
            int16_t bulletvectory = ship->y - enemy[i].y;
            // Calculation for bullet shots; up, down, forward and backwards.
            if (bulletvectorx < 0 && bulletvectory == 0 && enemybullet[i].x == -1) { // Creates new bullet, if bullets are available. Available bullets resides at (-1,-1)
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = -2;
                enemybullet[i].vy = 0;
            } else if (bulletvectorx > 0 && bulletvectory == 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = 2;
                enemybullet[i].vy = 0;
            } else if (bulletvectorx == 0 || bulletvectorx == 1 && bulletvectory > 0 && enemybullet[i].x == -1) { // Two bulletvectorx values to take into account a ship velocity of two.
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = 0;
                enemybullet[i].vy = 2;
            } else if (bulletvectorx == 0 || bulletvectorx == 1 && bulletvectory < 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = 0;
                enemybullet[i].vy = -2;
            }
            // Calculation for bullet shots at an oblique angle.
              else if (bulletvectorx < 0 && bulletvectory < 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = -2;
                enemybullet[i].vy = -2;
            } else if (bulletvectorx > 0 && bulletvectory < 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = 2;
                enemybullet[i].vy = -2;
            } else if (bulletvectorx < 0 && bulletvectory > 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = -2;
                enemybullet[i].vy = 2;
            } else if (bulletvectorx > 0 && bulletvectory > 0 && enemybullet[i].x == -1) {
                enemybullet[i].x = enemy[i].x;
                enemybullet[i].y = enemy[i].y;
                enemybullet[i].vx = 2;
                enemybullet[i].vy = 2;
            }
        }
    }
    // Updates enemybullet velocity.
    if (flagenemybullettimer == 1) {
        for (int i = 0; i < 5; i++) {
            if ((enemybullet[i].x > x1 && enemybullet[i].x < x2) && (enemybullet[i].y > y1 && enemybullet[i].y < y2)) {
                enemybullet[i].x += enemybullet[i].vx; // Adds the calculated velocity calculated above when flagenemybullets goes high.
                enemybullet[i].y += enemybullet[i].vy;
            } else {
                enemybullet[i].x = -1;
                enemybullet[i].y = -1;
            }
        }
        flagenemybullettimer = 0;
    }
}

// Detects collisions between user ship and enemyships.
void collisionDetection(ship_t * ship, ship_t enemyShip[]) {
    for (int i = 0; i < 5; i++) {
        if (ship->x == enemyShip[i].x || ship->x == enemyShip[i].x+1 && ship->y == enemyShip[i].y) { //Two enemyShip values to take into account a velocity of two, otherwise the ships might not be able to collide.
            ship->healthpoints -= 1;
            enemyShip[i].healthpoints = 0;
            enemyShip[i].x = -3;
            enemyShip[i].y = -3;
        }
    }
}

// Detects if user ship gets hit by enemy bullets.
void shipHitDetection(ship_t * ship, bullet_t enemybullet[]) {
    for (int i = 0; i < 5; i++) {
        if (ship->x == enemybullet[i].x || ship->x == enemybullet[i].x+1 && ship->y == enemybullet[i].y) {
            ship->healthpoints -= 1;
            enemybullet[i].x = -1;
            enemybullet[i].y = -1;
        }
    }
}
