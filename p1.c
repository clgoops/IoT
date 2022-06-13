#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
int main (void)
{
int32_t number;
char TEXT0[16]="SmplKeypad";
char TEXT1[16];
UNLOCKREG(); // unlock register for programming
DrvSYS_Open(48000000);// set System Clock to run at 48MHz
LOCKREG(); // lock register from programming
// Initialize LEDs (four on-board LEDs below LCD panel)
Initial_panel();
clr_all_panel();
print_lcd(0,TEXT0); // print title
while (1) // forever loop to keep flashing four LEDs
one at a time
{
number=DrvGPIO_GetPortBits(E_GPA);
sprintf(TEXT1,"%x",number); // print scankey input to string
print_lcd(1,TEXT1);
if(number==0xfffe)
print_lcd(2,"A0");
else if(number==0xfffd)
print_lcd(2,"A1");
else if(number==0xfffb)
print_lcd(2,"A2");
else if(number==0xfff7)
print_lcd(2,"A3");
else if(number==0xffef)
print_lcd(2,"A4");
else if(number==0xffdf)
print_lcd(2,"A5");
else if(number==0xffbf)
print_lcd(2,"A6");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xfeff)
print_lcd(2,"A8");
//else if(number==0xfeff)
//print_lcd(2,"A7");
/*else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");
else if(number==0xff7f)
print_lcd(2,"A7");*/
}
}
//Add ASCII.c as well. Put one female in GND and the other in GPA14.and 12 13