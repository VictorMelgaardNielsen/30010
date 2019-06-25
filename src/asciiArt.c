#include "asciiArt.h"

void drawFinalBoss (int8_t x, int8_t y) {
gotoxy(x,y);
printf("     %c%c%c%c%c                 ",220,223,223,223,220);
gotoxy(x,y+1);
printf("%c%c%c%c%c %c   %c                ",220,219,219,219,223,184,219);
gotoxy(x,y+2);
printf("    %c     %c                ",219,219);
gotoxy(x,y+3);
printf("     %c    %c                ",219,219);
gotoxy(x,y+4);
printf("    %c     %c%c%c              ",219,219,220,220);
gotoxy(x,y+5);
printf("    %c    %c%c  %c%c%c%c%c         ",219,220,223,223,223,223,223,220);
gotoxy(x,y+6);
printf("   %c    %c        %c%c%c       ",219,219,223,223,220);
gotoxy(x,y+7);
printf("   %c    %c%c          %c%c     ",219,219,220,223,220);
gotoxy(x,y+8);
printf("    %c%c    %c%c          %c%c   ",223,220,223,220,223,220);
gotoxy(x,y+9);
printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ",223,220,220,220,220,220,219,220,220,220,220,220,220,220,220,220,220,220,223,220);
gotoxy(x,y+10);
printf("          %c  %c             ",219,219);
gotoxy(x,y+11);
printf("          %c  %c             ",219,219);
gotoxy(x,y+12);
printf("         %c%c %c%c             ",220,219,220,219);

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

