#include "ansi.h"
#include "Variabel.h"



void buildCourse() {
    course(1,1,160,40);
    drawMeteor(100, 30);
    drawMeteor(90, 10);
    drawMeteor(120, 22);

}

void course(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
uint8_t yStart = y1, xStart, left = x2;
gotoxy(x1,y1);

printf("%c", 201);

for (xStart = x1; xStart < x2; xStart++) {
        printf("%c", 205);
}

printf("%c", 187);
backwards(1);down(1);

for (yStart; yStart < y2; yStart++) {
    printf("%c", 186);
    down(1);
    backwards(1);
}

printf("%c", 188);
backwards(2);

for(left; left >= x1; left--) {
    printf("%c", 205);
    backwards(2);
}

printf("%c", 200);
backwards(1);
up(1);

for (y2 - 1; y2 > y1; y2--) {
    printf("%c", 186);
    up(1);
    backwards(1);
    }
}

void drawCounter(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, int nice) {


gotoxy((x1 + x2)/2, (y1 + y2)/2);
up(1);
backwards(4);
printf("%c", 218);
for (int i = 0; i < 8; i++) {
    printf("%c",196);
}
printf("%c", 191);
down(1);
backwards(1);
printf("%c", 179);
down(1);
backwards(1);
printf("%c",217);
backwards(2);
for (int j = 0; j < 8; j++) {
    printf("%c", 196);
    backwards(2);
}
printf("%c",192);
backwards(1);
up(1);
printf("%cHits:%2d", 179, nice);
}

void ball(ball_t *b) {
   // if (!(b.vy == 0 && b.vx == 0)) {
    gotoxy(b->x,b->y);
    printf("%c", 111);
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
void easy(spaceship_t *s, uint8_t *uv, uint8_t *enemyAmount, uint8_t *highscoreMulti) {
    s->health = 3;

    *uv = 6;

    *enemyAmount = 3;

    *highscoreMulti = 1;
}

void medium(spaceship_t *s, uint8_t *uv, uint8_t *enemyAmount, uint8_t *highscoreMulti) {
    s->health = 2;

    *uv = 4;

    *enemyAmount = 4;

    *highscoreMulti = 2;
}

void realShit(spaceship_t *s, uint8_t *uv, uint8_t *enemyAmount, uint8_t *highscoreMulti) {
    s->health = 1;

    *uv = 2;

    *enemyAmount = 6;

    *highscoreMulti = 4;
}
*/
