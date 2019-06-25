#include "stm32f30x_conf.h" //STM32 config
#include "30010_io.h" // Indput/output library for this source
#include "ansi.h"
#include "Lutfile.h"
#include "timer.h"
#include "joystick.h"
#include "lcd.h"
#include "shipcontrol.h"


/*
int16_t power(int16_t a, int16_t exp) {
//Calculates a^exp
    int16_t i, r = a;
    for (i = 1; i < exp; i++) {
        r*= a;
    }
    return(r);
}

int main(void)
{
    int16_t a;
    uart_init( 9600 ); //Initialize USB serial emulation at 9600 baud
    clreol();
    color(1,7);
    printf("\n\n x x^2 x^3 x^4\n");
    for (a = 0; a < 10; a++)
        printf("%8d%8d%8d%8d\n",a, power(a, 2), power(a, 3), power (a, 4));
    while(1){}


}
*/
/*
int main(void) {
    uart_init( 9600 ); //Initialize USB serial emulation at 9600 baud
    color(1,7);
    clrscr();
    windows (5, 5, 60, 20, "Window title", 196, 179);

    while(1){};
}
*/
/*
//Exercise 3
int main(void) {
    uart_init( 9600 ); //Initialize USB serial emulation at 9600 baud
    clrscr();
   // sine(923); // Calculate sin (in degrees)
   // cose(800); // Calculate cos in degrees

   // printFix(expand(b));
   vector_t vec;
   initVector(&vec);
  // vec.x=6;
  // vec.y=4;
   rotateVector(&vec, 1280);



    while(1){};
}

*/

//Exercise 4
/*

 int main(void) {
    uart_init( 115200 ); //Initialize USB serial emulation at 9600 baud

    clrscr();
    counter_t cnt;
    ball_t v;
    v.x = 7;
    v.y = 4;
    v.vx = 1;
    v.vy = 1;
    cnt.x =0;

    //course values
    uint8_t x1 = 1;
    uint8_t y1 = 1;
    uint8_t x2 = 40;
    uint8_t y2 = 10;

    for (int i = 0; i < 100; i++) {
    int j = 0;
    clrscr();
    course(x1, y1, x2, y2);
    ballcheck(&v, x1, y1, x2, y2);
    updateposition(&v);
    counter(&cnt, &v, x1, y1, x2, y2);
    ball(&v);
    drawCounter(x1, y1, x2, y2, cnt.x);
        while( j < 1000000) {
            j++;
        }
    }

    while(1){};
}



/*
//Exercise 5
int main(void) {
    uart_init( 9600 ); //Initialize USB serial emulation at 9600 baud

    clrscr();

    while(1) {

        if(readJoystick() == 0x01) {
            printf("UP!\n");
            setLed('r');
            while(readJoystick() == 0x01) {
            }
        }

        if(readJoystick() == 0x02) {
            printf("DOWN!\n");
            setLed('g');
            while(readJoystick() == 0x02) {
            }
        }

        if(readJoystick() == 0x04) {
            printf("LEFT!\n");
            setLed('b');
            while(readJoystick() == 0x04) {
            }
        }

        if(readJoystick() == 0x08) {
            printf("RIGHT!\n");
            setLed('c');
            while(readJoystick() == 0x08) {
            }
        }

        if(readJoystick() == 0x10) {
            printf("CENTER!\n");
            setLed('m');
            while(readJoystick() == 0x10) {
            }
        } else {
            setLed('s');
        }
    }
}
*/

// Exercise 6
/*
int main(void) {
    int flagStartStop = 0;
    timee_t split1;
    split1.hour = 0;
    split1.mint = 0;
    split1.sec = 0;
    split1.msec = 0;

    timee_t split2;
    split2.hour = 0;
    split2.mint = 0;
    split2.sec = 0;
    split2.msec = 0;

    uart_init( 9600 );//Initialize USB serial emulation at 9600 baud

    setuptimer();
    setupjoystick();

    while(1){

        if (readJoystick() == 0x10 && flagStartStop == 0) {
            starttimer();
            flagStartStop = 1;
            while(readJoystick() == 0x10) {
            }
        } if (readJoystick() == 0x10 && flagStartStop == 1) {
            stoptimer();
            flagStartStop = 0;
            while(readJoystick() == 0x10) {
            }
        } if (readJoystick() == 0x02) {
            stoptimer();
            timer2.hour = 0;
            timer2.mint = 0;
            timer2.sec = 0;
            timer2.msec = 0;
            flagStartStop = 0;
        } if (readJoystick() == 0x04) {
            TIM2->DIER &= ~0x0001;
            split1.hour = timer2.hour;
            split1.mint = timer2.mint;
            split1.sec = timer2.sec;
            split1.msec = timer2.msec;
            TIM2->DIER |= 0x0001;
        } if (readJoystick() == 0x08) {
            TIM2->DIER &= ~0x0001;
            split2.hour = timer2.hour;
            split2.mint = timer2.mint;
            split2.sec = timer2.sec;
            split2.msec = timer2.msec;
            TIM2->DIER |= 0x0001;
        }


        if (timer2.msec == 1) {
            clrscr();
            printf("%02d:%02d:%02d\n", timer2.hour, timer2.mint, timer2.sec);
            printf("%02d:%02d:%02d:%02d\n", split1.hour, split1.mint, split1.sec, split1.msec);
            printf("%02d:%02d:%02d:%02d\n", split2.hour, split2.mint, split2.sec, split2.msec);
        }


    }
}

*/

//excersise 6.2
/*
int main(void) {
    uart_init( 9600 );
    clrscr();
    uart_clear();
    char a[10] = "";

    //readTerminal(a);

    printf("%s", readTerminal(a));




    while(1){};

}

/*
//Exercise 6.2 del 2
int main(void) {
    int number = 0;
    uart_init( 9600 );
    clrscr();
    uart_clear();
    setuptimer();
    timerCommandHelp();

    int flagStartStop = 0;
    timee_t split1;
    split1.hour = 0;
    split1.mint = 0;
    split1.sec = 0;
    split1.msec = 0;

    timee_t split2;
    split2.hour = 0;
    split2.mint = 0;
    split2.sec = 0;
    split2.msec = 0;

    starttimer();

    number = timerCommand();
    printf("%d", number);

    /*
    while(1){
        if (number == 0 && flagStartStop == 0) {
            starttimer();
            flagStartStop = 1;
        } if (number == 1 && flagStartStop == 1) {
            stoptimer();
            flagStartStop = 0;
        } if (number == 2) {
            stoptimer();
            timer2.hour = 0;
            timer2.mint = 0;
            timer2.sec = 0;
            timer2.msec = 0;
            flagStartStop = 0;
        } if (number == 3) {
            TIM2->DIER &= ~0x0001;
            split1.hour = timer2.hour;
            split1.mint = timer2.mint;
            split1.sec = timer2.sec;
            split1.msec = timer2.msec;
            TIM2->DIER |= 0x0001;
        } if (number == 4) {
            TIM2->DIER &= ~0x0001;
            split2.hour = timer2.hour;
            split2.mint = timer2.mint;
            split2.sec = timer2.sec;
            split2.msec = timer2.msec;
            TIM2->DIER |= 0x0001;
        }
        else if (number == 5) {
            timerCommandHelp();
        }
        else {
            timerCommandHelp();
        }


        if (timer2.msec == 1) {
            clrscr();
            printf("%02d:%02d:%02d\n", timer2.hour, timer2.mint, timer2.sec);
            printf("%02d:%02d:%02d:%02d\n", split1.hour, split1.mint, split1.sec, split1.msec);
            printf("%02d:%02d:%02d:%02d\n", split2.hour, split2.mint, split2.sec, split2.msec);
        }
    }
    */
    /*
}
*/


/*
//Exercise 7
int main(void) {
    uint8_t slice = 0;
    uint8_t line = 0;
    uart_init(9600);//Initialize USB serial emulation at 9600 baud

    setuptimer();
    starttimer();

    lcd_init();

    while(1) {
        lcd_write_string("hej",slice,line);
        lcd_push_buffer(&buffer);
        lcd_update(&slice,&line);
    }

}
*/


/*
//Ship control
int main(void) {
    uint8_t x1 = 1;
    uint8_t y1 = 1;
    uint8_t x2 = 60;
    uint8_t y2 = 20;
    uint8_t flagbullet = 0;
    uint8_t buzzkey = 1;
    bullet_t bullet[5];
    ship_t enemyShip[5];
    initEnemy(enemyShip, x1, y1, x2, y1);
    uart_init( 2000000 ); //Initialize USB serial emulation at 9600 baud
    color(1,7);
    clrscr();
    uart_clear();
    ship_t ship;
    shipSetup(&ship);
    bulletSetup(bullet);
    bullet_t enemyBullet[5];
    bulletSetup(enemyBullet);
    setuptimer();
    starttimer();
    diff_t difficulty;
    difficulty.diffValue = 2;
    difficulty.counterValue = 0;

    while(1){
        flagbullet = shipControl(&ship, x1, y1, x2, y2, &buzzkey);
        updateBullet(&ship, bullet, flagbullet, x1, y1, x2, y2);
        updateEnemyPosition(enemyShip, &difficulty, x1, y1, x2, y2);
        updateEnemyBullet(&ship, enemyBullet, enemyShip, x1, y1, x2, y2);
        collisionDetection(&ship, enemyShip);

        if (flagrefreshrate == 1) {
            clrscr();
            windows (x1, y1, x2, y2, "DTU Space Invaders 3000", 196, 179);
            printShip(&ship);
            printBullet(bullet, 4);
            flagrefreshrate = 0;
            bulletsLeft(bullet, x2, y2);
            printEnemy(enemyShip);
            printBullet(enemyBullet, 1);
        }
    }
}
*/

/*
//tests
int main(void) {
    uart_init( 1000000 ); //Initialize USB serial emulation at 9600 baud
    clrscr();
    char a = 2;
    char b = 3;
    char c;
    c = a++ + ++b;

        printf("%d",c);
}
*/

//I rapport tilf�j visuel beskrivelse af angle, se sketch.

// sizeof(bullet)/sizeof(bullet[0])

// power up; bouncing balls.

