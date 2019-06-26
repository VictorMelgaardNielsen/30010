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
    setupTimer2();
    uint8_t flagbuzzer = 0;

    uint8_t highScoreMulti, x1 = 1, y1 = 1, x2 = 160, y2 = 40, buzzkey = 1;
    heart_t heart;
    initHP(&heart);
    ship_t enemy[5];
    initEnemy(enemy, x1, y1, x2, y1);
    meteor_t m[3];
    initMeteor(m);
    bullet_t bullet[5];
    bulletSetup(bullet);
    bullet_t enemyBullet[5];
    bulletSetup(enemyBullet);
    ship_t ship;
    diff_t difficulty;
    uint8_t flagbullet = 0;
    nuke_t nuke;

    //hardware init
    uart_init( 2000000 ); //Initialize USB serial emulation at 9600 baud
    restart:
    setupTimer15();
    startTimer15();
    setupjoystick();
    lcd_init();
    clrscr();
    setupRGB();
    setRGB('s');

    //start up menu and difficulty selection
    menu_init();
    choose_diff(&ship, &highScoreMulti, &difficulty);
    lcd_clear_buffer();
    lcd_write_string("Get ready! Look at Putty", 0, 0);
    lcd_push_buffer(&buffer);
    while(flagbuzzer != 5) {
    buzzer(&flagbuzzer);
    }
    restartTimer15();

    while(1){

        display_stats(ship.healthpoints,ship.killcount);
        if (readJoystick() == 0x02 || ship.healthpoints == 0) { //press down to end game
            break;
        }

        flagbullet = shipControl(&ship, x1, y1, x2, y2);
        updateBullet(&ship, bullet, flagbullet, x1, y1, x2, y2);
        gravityCheckBullet(bullet, m);
        meteorBulletHit(bullet, m);
        meteorBulletHit(enemyBullet, m);
        gravityCheckShip(&ship, m);
        enemyHitCheck(bullet, enemy, &ship, &nuke);
        updateEnemyPosition(enemy,&difficulty, x1, y1, x2, y2);
        updateEnemyBullet(&ship, enemyBullet, enemy, x1, y1, x2, y2);
        collisionDetection(&ship, enemy);
        shipHitDetection(&ship, enemyBullet);
        enemiesDead(enemy, x1, y1, x2, y2);
        getHP(&ship, &heart, timer15);
        powerUp_Nuke(&ship,&nuke);
        use_Nuke(&ship, enemy, &nuke);
        RGBStatus(&ship, flagbullet);

        if (flagrefreshrate == 1) {
            clrscr();
            buildCourse(x1, y1, x2, y2, m);
            printShip(&ship);
            printBullet(bullet, 12);
            printEnemy(enemy);
            bulletsLeft(bullet,x2,y2);
            flagrefreshrate = 0;
            printBullet(enemyBullet, 9);
            drawHeart(heart);
            drawNuke(nuke);
        }

    }

    gameOver(ship.killcount, highScoreMulti);
    clrscr();
    gotoxy(10,10);
    drawGameOver(50,25);

    while(readJoystick() != 0x10) {};
    goto restart;

}



/*
int main() {
    //hardware init
    uart_init( 2000000 ); //Initialize USB serial emulation at 2000000 baud
    setuptimer();
    starttimer();
    setupjoystick();
    lcd_init();
    clrscr();

    gameOver(5, 1);

    //while(1);
}
*/
