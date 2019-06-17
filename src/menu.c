#include "menu.h"

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
                lcd_write_string("HELP HELP HELP!", 0, 0);
                lcd_write_string_line("Press center too return :)", slice, line, 1);
                lcd_push_buffer(&buffer);
                lcd_update_line(&slice,&line);
                }
                slice = 0, line = 2;
            }

            //Checks if joystick is pushed right
            if (readJoystick() == 0x08) {
                lcd_clear_buffer();
                lcd_write_string("Choose difficulty:", 0, 0);
                lcd_write_string("Press left for EASY", 0 , 1);
                lcd_write_string("Press up for MEDIUM", 0 , 2);
                lcd_write_string("Press right for REAL SHIT", 0 , 3);
                lcd_push_buffer(&buffer);
                break;
                //Her kommer choose_diff funktionen
                //choose_diff();
            }
        }
        printf("Der er break\n");
}

void choose_diff() {

}
