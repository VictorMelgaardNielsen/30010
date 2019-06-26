//CourseDesign.c

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

void initMeteor(meteor_t m[]) {
    m[0].x = 45;
    m[0].y = 30;
    m[1].x = 85;
    m[1].y = 10;
    m[2].x = 120;
    m[2].y = 23;

}
