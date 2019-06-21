#include "ansi.h"
#include "Variabel.h"



void buildCourse(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, meteor_t m[]) {
    course(x1,y1,x2,y2);
    drawMeteor(m[0].x,m[0].y);
    drawMeteor(m[1].x,m[1].y);
    drawMeteor(m[2].x,m[2].y);

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

gotoxy(x1,y1+1);
 for (yStart = y1; yStart < y2; yStart++) {
    printf("%c", 186);
    down(1);
    backwards(1);
 }

printf("%c", 200);

for (xStart = x1; xStart < x2; xStart++) {
        printf("%c", 205);
}

printf("%c", 188);

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

void initMeteor(meteor_t m[]) {
    m[0].x = 100;
    m[0].y = 30;
    m[1].x = 90;
    m[1].y = 10;
    m[2].x = 120;
    m[2].y = 22;

}





