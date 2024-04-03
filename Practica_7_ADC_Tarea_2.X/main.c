/**
 * OSCAR IVAN MORENO GUTIERREZ
 * PRACTICA 7 TAREA 3
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/LCDMiniDrivers/lcd.h"
#include "mcc_generated_files/adc1.h"

#define ROW_LEN 16

/*
                         Main application
 */

uint8_t row0_disp[ROW_LEN] = "_";    
uint8_t row1_disp[ROW_LEN] = "_";

uint8_t* Prow0 = &row0_disp;
uint8_t* Prow1 = &row1_disp;

char fila0[ROW_LEN];
char fila1[ROW_LEN];
uint16_t conversion = 0;
uint8_t queTanto=0;

float Volt = 0.0;
uint8_t enteroVolt= 0;
uint8_t decimalVolt= 0;

 void __attribute__ ((weak)) TMR1_CallBack(void)
{
     LED_1_Toggle();
     LED_2_Toggle();
}
 void __attribute__ ((weak)) SCCP1_COMPARE_CallBack(void)
{
    conversion = ADC1_ConversionResultGet(channel_AN0);    // Se lee el resultados del CAD
    Volt = conversion*(3.3/4096);
    sprintf(fila0,"V: %.2f ",Volt);
    //empezamos con un arreglo vacio de caracteres
    vaciarArreglo(fila1,ROW_LEN);
    // regla de 3 para determinar cuanto rellenar
    queTanto=(Volt*16)/3.3;
    llenarArreglo(fila1,queTanto);
    
}
 
// funcion para vaciar arreglos char con un espacio 
void vaciarArreglo(char *arreglo,uint8_t tamanio){
    for(uint8_t i=0; i <= tamanio;i++){
        arreglo[i]=' ';
    }
}

//funcion para llenar arreglo con ====
void llenarArreglo(char *arreglo, uint8_t tamanio){
    for(uint8_t i=0; i <= tamanio;i++){
        arreglo[i]='=';
    }
}


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    Prow0 = (uint8_t*) &fila0;
    Prow1 = (uint8_t*) &fila1;
    lcd_setContrast(0x20);
    lcd_clearDisplay();
    while (1)
    {
        lcd_writeString(Prow1, 1);
        lcd_writeString(Prow0, 0);
    }
    return 1; 
}
/**
 End of File
*/

