#include "asciiArt.h"

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

void drawGameOver(int8_t x, int8_t y) {
gotoxy(x,y);
printf("%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c",219,219,219,223,223,223,219,219,219,219,219,223,223,223,219,219,219,219,219,219,223,219,220,219,223,219,219,219,219,219,223,223,223);
gotoxy(x,y+1);
printf("%c%c    %c%c %c%c     %c%c %c%c   %c   %c%c %c%c   ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+2);
printf("%c%c   %c%c%c %c%c%c%c%c%c%c%c%c %c%c   %c   %c%c %c%c%c%c%c",219,219,220,220,220,219,219,220,220,220,220,220,219,219,219,219,223,219,219,219,219,220,220,220);
gotoxy(x,y+3);
printf("%c%c    %c%c %c%c     %c%c %c%c       %c%c %c%c   ",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+4);
printf("%c%c%c%c%c%c%c%c %c%c     %c%c %c%c       %c%c %c%c%c%c%c",219,219,219,220,220,220,219,219,219,219,219,219,219,219,219,219,219,219,220,220,220);
gotoxy(x,y+6);
printf("%c%c%c%c%c%c%c%c%c %c%c%c%c  %c%c%c %c%c%c%c%c %c%c%c%c%c%c%c%c%c ",219,219,219,223,223,223,219,219,219,223,219,219,219,219,219,223,219,219,223,223,223,219,219,223,223,223,223,219,219,220);
gotoxy(x,y+7);
printf("%c%c     %c%c   %c%c  %c%c  %c%c    %c%c     %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+8);
printf("%c%c     %c%c   %c%c  %c%c  %c%c%c%c%c %c%c%c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,223,223,223,219,219,220,220,220,220,220,223,223);
gotoxy(x,y+9);
printf("%c%c     %c%c   %c%c  %c%c  %c%c    %c%c     %c%c ",219,219,219,219,219,219,219,223,219,219,219,219,219,219);
gotoxy(x,y+10);
printf("%c%c%c%c%c%c%c%c%c    %c%c%c    %c%c%c%c%c %c%c     %c%c%c",219,219,219,220,220,220,219,219,219,223,219,223,219,219,220,220,220,219,219,219,219,220);

}

void drawNuke(nuke_t nuke) {
    if (nuke.available == 1) {
gotoxy(nuke.x,nuke.y);
printf(". \\\"/ .");
gotoxy(nuke.x,nuke.y+1);
printf(".-.\".-.");
gotoxy(nuke.x,nuke.y+2);
printf(" ` . ` ");
    }



}


void drawHeart(heart_t heart) {
    if (heart.available == 1) {
    gotoxy(heart.x,heart.y);
    printf(" _  _ ");
    gotoxy(heart.x,heart.y+1);
    printf("( \\/ )");
    gotoxy(heart.x,heart.y+2);
    printf(" \\  / ");
    gotoxy(heart.x,heart.y+3);
    printf("  \\/  ");
    }

}

void printbuzzscreen() {
    gotoxy(1,1);
    printf("EXCEL\n\n");
    printf("Balance Sheet (in trillion $)\n");
    printf("Space Invaders Space Industries Inc.\n\n");
    printf("%s%s%66s","Current assets:\n", "Cash", "7,314\n");
    printf("Accounts receivable:\n");
    printf("%s%61s","Inventory", "5,560\n");
    printf("Prepaid expenses\n");
    printf("Short-term investments\n");
    printf("%s%50s","Total current assets", "12,874");
}


