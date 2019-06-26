#include "stm32f30x_conf.h" //STM32 config
#include "30010_io.h" // Indput/output library for this source
#include "ansi.h" // ansi commands used to control Putty
#include "timer.h" // Control of the on board timer on the ARM Cortex
#include "joystick.h" // Joystick control on the Mbed Extension
#include "lcd.h" // Printing functions for the LCD on the Mbed Extension
#include "shipcontrol.h" //Control of user ship, enemy ship and bullets
#include "variabel.h" // Update functions and Power Up functions
#include "mbedInteract.h" //Interactions with mbed board
#include "asciiArt.h" // Different animations used in graphics in Putty


int main(void) {
    //Define variables and structs
    uint8_t highScoreMulti; //Used to calculate high depending on which difficulty user selects
    uint8_t x1 , y1, x2, y2; //x1 and y1 defines the north western corner of the course, x2 and y2 the south eastern
    uint8_t flagbullet, flagbuzzer; //flagbullet checks if user fires bullet and flagbuzzer is used to sequence the buzzer melody
    heart_t heart; // Hearth Power Up struct
    nuke_t nuke; // Nuke Power Up struct
    ship_t ship; // User Ship struct
    ship_t enemy[5]; // Enemy ships struct
    meteor_t m[3]; // Meteor struct
    bullet_t bullet[5]; // User bullet struct
    bullet_t enemyBullet[5]; // Enemy bullet struct
    diff_t difficulty; // Difficulty struct

    //hardware init
    uart_init( 2000000 ); //Initialize USB serial emulation at 2000000 baud
    setupTimer2();
    setupTimer15();
    startTimer15();
    setupjoystick();
    lcd_init();
    clrscr();
    setupRGB();

    //Main game loop
    while(1) {
        //Initialize structs and variables
        x1 = 1, y1 = 1, x2 = 160, y2 = 40;
        flagbullet = 0, flagbuzzer = 0;
        initHP(&heart);
        initEnemy(enemy, x1, y1, x2, y1);
        initMeteor(m);
        bulletSetup(bullet);
        bulletSetup(enemyBullet);
        setRGB('s');

        //start up menu and difficulty selection
        menu_init();
        choose_diff(&ship, &highScoreMulti, &difficulty);

        // Prints get ready to LCD
        lcd_clear_buffer();
        lcd_write_string("Get ready! Look at Putty", 0, 0);
        lcd_push_buffer(&buffer);

        // Plays start up melody
        startTimer2();
        while(flagbuzzer != 5) {
        buzzer(&flagbuzzer);
        }
        flagbuzzer = 0;
        restartTimer15();

        while(1){

            display_stats(ship.healthpoints,ship.killcount);
            if (readJoystick() == 0x02 || ship.healthpoints == 0) { //press down to end game
                break;
            }

            // Creates bullets if user shoots. Updates position of the bullets
            flagbullet = shipControl(&ship, x1, y1, x2, y2);
            updateBullet(&ship, bullet, flagbullet, x1, y1, x2, y2);

            // Meteor gravity and bullet hit update functions
            gravityCheckBullet(bullet, m);
            gravityCheckShip(&ship, m);
            meteorBulletHit(bullet, m);
            meteorBulletHit(enemyBullet, m);

            enemyHitCheck(bullet, enemy, &ship, &nuke); // Checks if user bullet hits enemy ship
            updateEnemyPosition(enemy,&difficulty, x1, y1, x2, y2); // Updates enemy ship position depending on difficulty selected
            updateEnemyBullet(&ship, enemyBullet, enemy, x1, y1, x2, y2); // Creates enemy bullet and updates position of bullets
            collisionDetection(&ship, enemy); // Checks if there is a collision between user and enemy ship
            shipHitDetection(&ship, enemyBullet); // Checks if user ship is hit by enemy bullet
            enemiesDead(enemy, x1, y1, x2, y2); // Respawns enemy if all are dead

            //Power Ups update functions
            getHP(&ship, &heart, timer15);
            powerUp_Nuke(&ship,&nuke);
            use_Nuke(&ship, enemy, &nuke);

            // RGB light showing health points. green 3 lives, yellow 2 lives, red one life
            RGBStatus(&ship, flagbullet);

            // Prints graphics with a rate controlled by the flagrefreshrate selected in the timer15 interrupt handler
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

        // Game Over screen on Putty and LCD.
        gameOver(ship.killcount, highScoreMulti);
        clrscr();
        gotoxy(10,10);
        drawGameOver(50,25);

        // Returns to the start menu
        while(readJoystick() != 0x10) {};
        restartTimer15();
        startTimer15();
    }
}
