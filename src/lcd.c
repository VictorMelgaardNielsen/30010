#include "lcd.h"

void lcd_write_string(char s[], uint8_t slice, uint8_t line) {
    int i, j = 0;
    int index = slice + (128*line);
    memset(buffer,0x00,512);
    while(!(s[j] == '\0')) {
        for(i = 0; i < 5; i++) {
            buffer[index] = character_data[s[j]-0x20][i];
            index++;
        }
    j++;
    }
}

void lcd_update(uint8_t *slice, uint8_t *line) {
    if (flaglcd == 1 && *slice<128) {
        (*slice)++;
    } if (flaglcd == 1 && *slice == 128) {
        (*slice) = 0;
        (*line)++;
    }
    flaglcd = 0;
}

