// lcd.c

#include "lcd.h"

void lcd_clear_buffer() {
    memset(buffer,0x00,512);
}

void lcd_write_string(char s[], uint8_t slice, uint8_t line) {
    int i, j = 0;
    int index = slice + (128*line);
    while(!(s[j] == '\0')) {
        for(i = 0; i < 5; i++) {
            buffer[index] = character_data[s[j]-0x20][i];
            index++;
            if (index >= 511) {
                index -= 511;
            }
        }
    j++;
    }
}

void lcd_write_string_line(char s[], uint8_t slice, uint8_t line, uint8_t current_line) {
    int i, j = 0;
    int index = slice + (128*line);
    while(!(s[j] == '\0')) {
        for(i = 0; i < 5; i++) {
            if(current_line*128 <= index && index < (current_line+1)*128) {
                buffer[index] = character_data[s[j]-0x20][i];
            }
            index++;
            if (index >= (current_line+1)*128) {
                index -= (current_line+1)*128;
            }
        }
    j++;
    }
}

void lcd_update(uint8_t *slice, uint8_t *line) {
    if (flaglcd == 1 && *slice < 128) {
        (*slice) += 5;
        flaglcd = 0;
    } if (flaglcd == 1 && *slice == 128) {
        (*slice) = 0;
        (*line)++;
        flaglcd = 0;
    } if (flaglcd == 1 && *slice + ((*line)*128) >= 512) {
        (*slice) = 0;
        (*line) = 0;
        flaglcd = 0;
    }
}

void lcd_update_line(uint8_t *slice, uint8_t *line) {
    if (flaglcd == 1 && *slice > 0) {
        (*slice) -= 5;
        flaglcd = 0;
    }
    if (flaglcd == 1 && *slice <= 0) {
        (*slice) = 127;

        if (!((*line) == 0)) {
            (*line)--;
        } else {
            (*line) = 3;
        }
        flaglcd = 0;
    }
}
