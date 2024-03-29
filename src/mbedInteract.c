// mbedInteract.c

#include "mbedInteract.h"

void menu_init() {
    uint8_t slice = 0, line = 1;

        while(1) {
            lcd_clear_buffer();
            lcd_write_string("Welcome!", 0, 0);
            lcd_write_string_line("Press center too start menu :)", slice, line, 1);
            lcd_push_buffer(&buffer);
            lcd_update_line(&slice, &line);
            if(readJoystick() == 0x10) {
                break;
            }
        }
        slice = 0, line = 2;
        while(1) {
            lcd_clear_buffer();
            lcd_write_string("Choose action:", 0, 0);
            lcd_write_string("Press left for help.", 0, 1);
            lcd_write_string_line("Press right too choose difficulty.", slice, line, 2);
            lcd_push_buffer(&buffer);
            lcd_update_line(&slice,&line);

            //Checks if joystick is pushed left
            if(readJoystick() == 0x04) {
                slice = 0, line = 1;
                while(!(readJoystick() == 0x10)) {
                lcd_clear_buffer();
                lcd_write_string("'A' & 'D' rotate the ship", 0, 0);
                lcd_write_string("'W' moves, 'S' shoots", 0, 1);
                lcd_write_string("Kill enemies, dodge rocks", 0, 2);
                lcd_write_string("Press center to know more", 0, 3);
                lcd_push_buffer(&buffer);

                }
                while(!(readJoystick() == 0x01)) {
                lcd_clear_buffer();
                lcd_write_string("If you kill many enemies", 0, 0);
                lcd_write_string("A nuke will spawn", 0, 1);
                lcd_write_string("It will kill all enemies", 0, 2);
                lcd_write_string("Press up to return!", 0, 3);
                lcd_push_buffer(&buffer);
                }

                slice = 0, line = 2;
            }

            //Checks if joystick is pushed right
            if (readJoystick() == 0x08) {
                while(readJoystick() == 0x08) {}
                lcd_clear_buffer();
                lcd_write_string("Choose difficulty:", 0, 0);
                lcd_write_string("Press left for EASY", 0 , 1);
                lcd_write_string("Press up for MEDIUM", 0 , 2);
                lcd_write_string("Press right for HARDCORE", 0 , 3);
                lcd_push_buffer(&buffer);
                break;
                //Her placer choose_diff() efter menu_init i main
            }
        }
}

void choose_diff(ship_t * ship, uint8_t * highscoreMulti, diff_t * difficulty) {
    while(1) {
        if(readJoystick() == 0x04) {
            ship->healthpoints = 3;
            ship->killcount = 0;
            shipSetup(ship);
            *highscoreMulti = 1;
            difficulty->diffValue = 3;
            difficulty->counterValue = 0;
            restartTimer15();
            break;
        } if(readJoystick() == 0x01) {
            ship->healthpoints = 2;
            ship->killcount = 0;
            shipSetup(ship);
            *highscoreMulti = 2;
            difficulty->diffValue = 2;
            difficulty->counterValue = 0;
            restartTimer15();
            break;
        } if(readJoystick() == 0x08) {
            ship->healthpoints = 1;
            ship->killcount = 0;
            shipSetup(ship);
            *highscoreMulti = 4;
            difficulty->diffValue = 1;
            difficulty->counterValue = 0;
            restartTimer15();
            break;
        }
    }
}

void display_stats(uint8_t health, uint8_t kills) {
    char healthStr[24] = "Health points:";
    char killStr[15] = "Kill count: ";
    char timeStr[15] = "Time: ";
    char *heart = " <3";
    char intnumber[3];
    sprintf(intnumber, "%d", kills);
    int i, j;

    for(i = 13; i < 13+health*3; i+=3) {
        for(j = 0; j < 3; j++) {
            healthStr[i+j] = heart[j];
        }
    }

    for(i = 12; i < 14; i++) {
        killStr[i] = intnumber[i-12];
    }

    sprintf(intnumber, "%02d", timer15.mint);
    i = 6;
    while(i < 8) {
        timeStr[i] = intnumber[i-6];
        i++;
    }

    timeStr[i] = ':';
    i++;

    sprintf(intnumber, "%02d", timer15.sec);
    while(i < 11) {
        timeStr[i] = intnumber[i-9];
        i++;
    }

    lcd_clear_buffer();
    lcd_write_string("Stats:",0,0);
    lcd_write_string(healthStr,0,1);
    lcd_write_string(killStr,0,2);
    lcd_write_string(timeStr,0,3);
    lcd_push_buffer(&buffer);

}

void gameOver(uint8_t kills, uint8_t highScoreMulti) {
    uint16_t highscore = 0; // 15.1 fixed point;
    char scoreStr[16] = "Highscore: ";
    char intNumber[5];
    int i = 11;
    lcd_clear_buffer();
    stopTimer15();

    highscore = kills*highScoreMulti << 1;
    /*
    if (!(120 - (int)(timer2.sec + timer2.msec*60) < 0)) {
        highscore += (timer2.sec + timer2.msec*60 << 1);
    }
    */

    //Converts the highscore back to whole numbers, but divides the highscore by two
    sprintf(intNumber, "%03ld.%0d", highscore >> 2,  ((highscore >> 1) & 0x0001)*5 );
    while (i < 16) {
        scoreStr[i] = intNumber[i - 11];
        i++;
    }

    lcd_write_string("GAME OVER", 0, 1);
    lcd_write_string(scoreStr, 0, 2);
    lcd_write_string("Press center to return", 0, 3);
    lcd_push_buffer(&buffer);

}
