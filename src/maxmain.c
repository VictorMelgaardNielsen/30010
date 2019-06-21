#include "stm32f30x_conf.h" //STM32 config
#include "30010_io.h" // Indput/output library for this source
#include "ansi.h"
#include "Lutfile.h"
#include "angles.h"
#include "timer.h"
#include "joystick.h"
#include "lcd.h"
#include "shipcontrol.h"
#include "variabel.h"
#include "mbedInteract.h" //Interactions with mbed board
#include "finalBoss.h"

/*
int main(void) {
    uint8_t highScoreMulti, x1 = 1, y1 = 1, x2 = 160, y2 = 40;
    meteor_t m[3];
    initMeteor(m);
    bullet_t bullet[5];
    ship_t ship;
    int flagbullet = 0;

    //hardware init
    uart_init( 1000000 ); //Initialize USB serial emulation at 9600 baud
    printf("\e[?251");
    setuptimer();
    starttimer();
    setupjoystick();
    lcd_init();
    clrscr();

    //start up menu and difficulty selection
    menu_init();
    choose_diff(&ship, &highScoreMulti);
    bulletSetup(bullet);

    while(1){
        display_stats(ship.healthpoints,ship.killcount);
        if (readJoystick() == 0x02 || ship.healthpoints == 0) { //press down to end game
            break;
        }

        flagbullet = shipControl(&ship, x1, y1, x2, y2);
        updateBullet(&ship, bullet, flagbullet, x1, y1, x2, y2);

        if (flagrefreshrate == 1) {
            clrscr();
            buildCourse(x1, y1, x2, y2, m);
            printShip(&ship);
            printBullet(bullet);
            gravityCheckBullet(bullet, m);
            meteorBulletHit(bullet, m);
            gravityCheckShip(&ship, m);
            flagrefreshrate = 0;
            bulletsLeft(bullet,x2,y2);
        }

    }

    gameOver(ship.killcount, highScoreMulti);
    clrscr();
    gotoxy(10,10);
//    drawFinalBoss(50,25);

}

*/
/*
int main() {
    uart_init( 1000000 ); //Initialize USB serial emulation at 9600 baud

    buildCourse(1,1,160,40);

    while(1);
}

*/
