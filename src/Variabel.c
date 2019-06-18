#include "variabel.h"
/*
int8_t shooting() {
    while(1) {
        if(s == 1) {
    return 1;
        }
    else{
    return 0;
    }
    }

}


void bullet_create(int8_t a, spaceship_t x) {
    bullet_t b;
    b.x = x.x;
    b.y = x.y;
    b.vx = x.vx;
    b.vy = x.vy;
    b.style =


    if (shooting() = 1) {

    }






}

*/

/* include in main
int i, n;
   time_t t;

   n = 5;

   Intializes random number generator
   srand((unsigned) time(&t));

*/



void coordinatRandomiser(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, meteor_t *m) {
    m->x = (rand() % (x2-x1)) + x1;
    m->y = (rand() % (y2-y1)) + y1;

}



void drawMeteor(int8_t x, int8_t y) {

    gotoxy(x, y);
    printf("  .----.  ");
    gotoxy(x, y + 1);
    printf(".'%c%c%c%c%c%c'.",178,178,178,178,178,178);
    gotoxy(x, y + 2);
    printf(":%c%c%c%c%c%c%c%c:",178,178,178,178,178,178,178,178);
    gotoxy(x, y + 3);
    printf("'.%c%c%c%c%c%c.'",178,178,178,178,178,178);
    gotoxy(x, y + 4);
    printf("  `''''`  ");
}

/*
void gravityCheck(bullet_t *b, meteor_t *m) {

    if (b.x < m.x && b.x > m.x - 4 && b.y < m.y && b.y > m.y - 2) {
        b.vx += 1;
        b.vy += 1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y < m.y && b.y > m.y - 2) {
        b.vy += 1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y < m.y && b.y > m.y - 2) {
        b.vx += -1;
        b.vy += 1;
    }

    if (b.x < m.x && b.x > m.x - 4 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx += 1;
    }

    if (b.x < m.x && b.x > m.x - 4 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vx += 1;
        b.vy += -1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vy += -1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vx += -1;
        b.vy += -1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx += -1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx = 0;
        b.vy = 0;
    }

}

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







