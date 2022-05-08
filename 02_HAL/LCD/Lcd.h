/*
 * Lcd.h
 *
 *  Created on: Apr 24, 2022
 *      Author: Eslam Ali
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_PORT_DATA
#define LCD_PORT_DIR

/*LCD command */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_CURSOR_BLINKING            0x0F
#define LCD_SET_CURSOR_LOCATION        0x80    /*force cursor to beginning of the 1st line */
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_ENTRY_MODE                 0x06


#define LCD_PORT_ID                    GPIO_PORTB

#define LCD_RS_PORT_ID                 GPIO_PORTB
#define LCD_RS_PIN_ID                  GPIO_PIN_0

#define LCD_E_PORT_ID                  GPIO_PORTB
#define LCD_E_PIN_ID                   GPIO_PIN_1

#define LCD_RW_PORT_ID                 GPIO_PORTB
#define LCD_RW_PIN_ID                  GPIO_PIN_2


/* Description:
 * initialization function
 * set RS , RW , E and data port as output pins
 * */
void Lcd_Init(void);

/* Description:
 * this function used to clear the  of LCD
 * */
void LCD_clearScreen(void);

/*Description
 * this function used to display a string on the screen of the LCD
 * */
void LCD_displayString(char * str);

/* Description:
 * this function used to move the cursor to specific row and column
 * */
void LCD_moveCursorXY(unsigned char r, unsigned char col);

/*
 * Description :
 * Display the string in the required position on the screen
 */
void LCD_displayStringRowColumn(uint08_t row,uint08_t col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(sint16_t data);

void Data(uint08_t data);


#endif /* LCD_H_ */
