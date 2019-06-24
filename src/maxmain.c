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
#include "asciiArt.h"


int main(void) {
    uint8_t highScoreMulti, x1 = 1, y1 = 1, x2 = 160, y2 = 40, buzzkey = 0;
    ship_t enemy[5];
    initEnemy(enemy, x1, y1, x2, y1);
    meteor_t m[3];
    initMeteor(m);
    bullet_t bullet[5];
    bullet_t enemyBullet[5];
    bulletSetup(enemyBullet);
    ship_t ship;
    diff_t difficulty;
    int flagbullet = 0;

    //hardware init
    uart_init( 2000000 ); //Initialize USB serial emulation at 9600 baud
    setuptimer();
    starttimer();
    setupjoystick();
    lcd_init();
    clrscr();

    //start up menu and difficulty selection
    menu_init();
    choose_diff(&ship, &highScoreMulti, &difficulty);
    bulletSetup(bullet);

    while(1){
        display_stats(ship.healthpoints,ship.killcount);
        if (readJoystick() == 0x02 || ship.healthpoints == 0) { //press down to end game
            break;
        }

        flagbullet = shipControl(&ship, x1, y1, x2, y2, &buzzkey);
        updateBullet(&ship, bullet, flagbullet, x1, y1, x2, y2);
        gravityCheckBullet(bullet, m);
        meteorBulletHit(bullet, m);
        gravityCheckShip(&ship, m);
        enemyHitCheck(bullet, enemy, &ship);
        updateEnemyPosition(enemy,&difficulty, x1, y1, x2, y2);
        updateenemyBullet(&ship, enemyBullet, enemy, x1, y1, x2, y2);

        if (flagrefreshrate == 1) {
            clrscr();
            buildCourse(x1, y1, x2, y2, m);
            printShip(&ship);
            printBullet(bullet);
            printEnemy(enemy);
            bulletsLeft(bullet,x2,y2);
            flagrefreshrate = 0;
            printBullet(enemyBullet);
        }

    }

    gameOver(ship.killcount, highScoreMulti);
    clrscr();
    gotoxy(10,10);
//    drawFinalBoss(50,25);

}



/*
int main() {
    uart_init( 1000000 ); //Initialize USB serial emulation at 9600 baud

    buildCourse(1,1,160,40);

    while(1);
}

*/
