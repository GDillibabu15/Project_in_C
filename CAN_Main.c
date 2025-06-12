/*Program to transmit 1byte of Data from CAN2 to CAN1*/
#include<lpc21xx.h>
#include "can_fun.c"
#include "lcd_fun.c"

int main()
{
  unsigned int b;
  lcd_config();
  can_config();

  can_tx(33668790);                 //load the data

  b=can_rx();                  //load the recievd variable to variable b
  lcd_num(b);         
}