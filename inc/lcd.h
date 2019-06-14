#include <stdio.h>
#include <stdint.h>
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "charset.h"
#include "timer.h"

#ifndef _LCD_H_
#define _LCD_H_

//buffer for lcd display - Global for easy use in programS
uint8_t buffer[512];
void lcd_write_string(char s[], uint8_t slice, uint8_t line);
void lcd_update();

#endif
