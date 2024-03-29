// lcd.h

#include <stdio.h>
#include <stdint.h>
#include "charset.h"
#include "timer.h"
#include "30010_io.h"

#ifndef _LCD_H_
#define _LCD_H_

//buffer for lcd display - Global for easy use in programs
uint8_t buffer[512];
void lcd_clear_buffer();
void lcd_write_string(char s[], uint8_t slice, uint8_t line);
void lcd_write_string_line(char s[], uint8_t slice, uint8_t line, uint8_t current_line);
void lcd_update(uint8_t *slice, uint8_t *line);
void lcd_update_line(uint8_t *slice, uint8_t *line);

#endif
