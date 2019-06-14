#include "ansi.h" //headeren inkluderes i c filen
#define ESC 0x1B

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr() {
    printf("%c[2J", ESC);
}

void clreol() {
    printf("%c[K", ESC);
}

void gotoxy (uint8_t x, uint8_t y) {
    printf("%c[%d;%dH", ESC, y, x);
}

void underline (uint8_t on) {
    if (on == 1) {
        printf("%c[%d;m" ,ESC, 04);
    }
    else {
        printf("%c[%d;m" ,ESC, 00);
    }
}

void blink (uint8_t on) {
    if (on == 1) {
        printf("%c[%d;m" ,ESC, 05);
    }
    else {
        printf("%c[%d;m" ,ESC, 25);
    }
}

void inverse (uint8_t on) {
    if (on == 1) {
        printf("%c[%d;m" ,ESC, 07);
    }
    else {
        printf("%c[%d;m" ,ESC, 27);
    }
}

void up(uint8_t x) {
    printf("%c[%dA", ESC, x);
}

void down(uint8_t x) {
    printf("%c[%dB", ESC, x);
}

void forwards(uint8_t x) {
    printf("%c[%dC", ESC, x);
}

void backwards(uint8_t x) {
    printf("%c[%dD", ESC, x);
}

void windows (uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char title[], char a, char b) {
    //Upper black square
    color(1,0);
    gotoxy(x1+2,y1);
    for (int i = x1; i < x2-2; i++) {
        printf("%c", 32);

    }
    //Right line
    color(1,7);
    gotoxy(x2,y1);
    for (int j = y1; j < y2; j++) {
        down(1);
        printf("%c", b);
        backwards(1);

    }
    //Title
    gotoxy(x1+6,y1);
    color(15,0);
    printf("%s", title);


    //Left line
    color(1,7);
    gotoxy(x1,y1);
    for (int k = y1; k < y2; k++) {
        down(1);
        printf("%c", b);
        backwards(1);
    }
    //Bottom line
    gotoxy(x1,y2);
    for (int l = x1; l < x2; l++) {
        printf("%c", a);
    }
    //Corner upper left
    gotoxy(x1,y1);
    printf("%c", 218);
    gotoxy(x1+1,y1);
    printf("%c", 180);

    //Corner bottom left
    gotoxy(x1,y2);
    printf("%c", 192);

    //Corner upper right
    gotoxy(x2-1,y1);
    printf("%c", 195);
    gotoxy(x2,y1);
    printf("%c", 191);

    //Corner bottom right
    gotoxy(x2,y2);
    printf("%c", 217);
}

void printFix(int32_t i) {
    // Prints a signed 16.16 fixed point number
    if ((i & 0x80000000) != 0) { // Handle negative numbers
        printf("-");
        i = ~i + 1;
    }
    printf("%ld.%04ld", i >> 16, 10000 * (uint32_t) (i & 0xFFFF) >> 16);
    // Print a maximum of 4 decimal digits to avoid overflow
}

void ball(ball_t *b) {

    gotoxy(b->x,b->y);
    printf("%c", 111);

}

void rotateVector(vector_t *v, int32_t a) {
    int32_t xtemp = v->x;
    (*v).x = (*v).x * cose(a) - (*v).y * sine(a);
    (*v).y = xtemp * sine(a) + (*v).y * cose(a);
    printFix(expand((*v).x));
    printf(",");
    printFix(expand((*v).y));
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






