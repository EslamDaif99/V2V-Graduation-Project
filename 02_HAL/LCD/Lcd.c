/*
 * Lcd.c
 */

#include "Type.h"
#include "GPIO.h"
#include "Lcd.h"

static void Cmd(uint08_t data);
static void Write(uint08_t data);
static void EnPulse(void);
static uint08_t* itoa(sint16_t value, uint08_t* buffer, uint16_t base);
static void Delay(uint32_t t);




/* Description:
 * initialization function
 * set RS , RW , E and data port as output pins
 * */
void Lcd_Init(void)
{
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_0);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_1);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_2);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_3);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_4);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_5);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_6);
    GPIO_Init(LCD_PORT_ID, GPIO_PIN_7);

    GPIO_SetPortDirection(LCD_PORT_ID, GPIO_DIRECTION_OUTPUT);
    GPIO_SetPortState(LCD_PORT_ID, 0x00);

    Delay(5000);
    Write(LCD_TWO_LINES_FOUR_BITS_MODE);

    EnPulse();
    Delay(200);
    Write(LCD_CLEAR_COMMAND);
    Write(LCD_CURSOR_OFF);
    Write(LCD_ENTRY_MODE);

}

/* Description:
 * this function used to clear the  of LCD
 * */
void LCD_clearScreen(void){
    Cmd(LCD_CLEAR_COMMAND);        /* clear the screen*/
}


/*Description
 * this function used to display a string on the screen of the LCD
 * */
void LCD_displayString(char * str)
{
    uint08_t i = 0;
    while(str[i] != '\0')
    {
        Data(str[i]);
        i++;
    }
}


/* Description:
 * this function used to move the cursor to specific row and column
 * */
void LCD_moveCursorXY(uint08_t row , uint08_t column){
        uint08_t address;

        switch(row)
        {
        case 0 :
            address= column ;
            break;
        case 1 :
            address= 0x40 + column ;
            break;
        case 2 :
            address= 0x10 + column ;
            break;
        case 3 :
            address= 0x50 + column ;
            break;
        }
        Cmd(LCD_SET_CURSOR_LOCATION | address);

}

/*
 * Description :
 * Display the string in the required position on the screen
 */
void LCD_displayStringRowColumn(uint08_t row,uint08_t col,const char *Str){

    LCD_moveCursorXY(row,col);   /* go to to the required LCD position */
    LCD_displayString(Str);      /* display the string */
}


static void Write(uint08_t data)
{
    uint08_t d;
    /* out the last 4 bits of the required command to the data bus D4 --> D7 */
    d = GPIO_readPort(LCD_PORT_ID);
    d &= 0x0F;
    d |= (data & 0xF0);
    GPIO_SetPortState(LCD_PORT_ID, d);
    EnPulse();
    /*repeat for second nibble */
    d = GPIO_readPort(LCD_PORT_ID);
    d &= 0x0F;
    d |= data<<4;
    GPIO_SetPortState(LCD_PORT_ID, d);
    EnPulse();

    Delay(2000);
}

void Data(uint08_t data)
{
    GPIO_SetPinState(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_STATE_HIGH);
    Write(data);
}

static void Cmd(uint08_t data)
{
    GPIO_SetPinState(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_STATE_LOW);
    Write(data);
}

static void EnPulse(void)
{
    GPIO_SetPinState(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_STATE_HIGH);
    Delay(1);
    GPIO_SetPinState(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_STATE_LOW);
    Delay(1);
}


/*  implement   itoa()   function
value – Value to be converted to a string.
buffer – Array to store the result.
base – Numerical base used to represent the value as a string, between 2 and 16
Return Value: a pointer to the resulting null-terminated string, same as parameter buffer.
*/
static uint08_t* itoa(sint16_t value, uint08_t* buffer, uint16_t base)
{
    // invalid input
    if (base < 2 || base > 16) {
        return buffer;
    }
    sint16_t n = value;
    // consider the absolute value of the number
    if(n<0){
        n=0-n ;
    }

    uint16_t i = 0;
    while (n)
    {
        sint16_t r = n % base;

        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // if the number is 0
    if (i == 0) {
        buffer[i++] = '0';
    }

    /* If the base is 10 and the value is negative, the resulting string
    is preceded with a minus sign (-)
    With any other base, value is always considered unsigned */

    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';                 // null terminate string

    // reverse the string and return it
    uint16_t k=0, j=i-1 ;
    while (k < j) {
        uint08_t *x= &buffer[k++], *y= &buffer[j--], t ;
        t = *x; *x = *y; *y = t;      // to swap two numbers

    }
    return buffer;
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(sint16_t data)
{
    uint08_t buffer[16]; /* String to hold the ascii result */
    itoa(data,buffer,10); /* Use itoa to convert the data to its corresponding ASCII value, 10 for decimal */
    LCD_displayString(buffer); /* Display the string */
}




static void Delay(uint32_t t)
{
    uint32_t i;
    for(i=0;i<t*3;i++)
    {
        __asm__("NOP");
    }
}
