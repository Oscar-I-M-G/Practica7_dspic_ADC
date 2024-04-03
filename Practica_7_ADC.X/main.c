/*
 * OSCAR IVAN MORENO GUTIERREZ
 * PRACTICA 7 
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/LCDMiniDrivers/lcd.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/adc1.h"

#define ROW_LEN 16
//variables de ayuda
/*
    Main application
 */
uint8_t row0_disp[ROW_LEN] = "";    
uint8_t row1_disp[ROW_LEN] = "";
uint8_t* Prow0 = &row0_disp;
uint8_t* Prow1 = &row1_disp;

char fila0[ROW_LEN];
char fila1[ROW_LEN];

uint16_t conversion = 0;

 void __attribute__ ((weak)) TMR1_CallBack(void)
{
     
}

void __attribute__ ((weak)) SCCP1_COMPARE_CallBack(void)
{
    conversion = ADC1_ConversionResultGet(POTE);
    sprintf(fila1,"%d     ",conversion);
}


int main(void)
{
    SYSTEM_Initialize();
    sprintf(fila0,"Oscar Ivan");
    lcd_setContrast(0x20);
    lcd_clearDisplay();
    Prow0 = (uint8_t*) &fila0;
    Prow1 = (uint8_t*) &fila1;
    while(1)
    {
        lcd_writeString(Prow0, 0);
        lcd_writeString(Prow1, 1);
        
    }    
}


