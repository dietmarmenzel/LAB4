//*****************************************************************************
// Universidad del Valle de Guatemala
// BE3015 - Electrónica Digital 2
// Gunther Dietmar Menzel - 19106
// LAB4
//*****************************************************************************

//*****************************************************************************
// Librerías
//*****************************************************************************
#include <Arduino.h>
#include <LiquidCrystal.h>
//#include "LCD4bits.h"

//*****************************************************************************
// Definición de pines
//*****************************************************************************
#define d4 14
#define d5 27
#define d6 26
#define d7 25
#define en 12
#define rs 13

#define pot1 34
#define pot2 35

#define boton1 23
#define boton2 22

//*****************************************************************************
// Prototipos de función
//*****************************************************************************
void Contador(void);

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int ContadorBoton1 = 0; //Contador Boton en entero

// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);
uint8_t decenas, unidades, decimal;
uint8_t decenas2, unidades2, decimal2;
int adcRaw;
float voltaje1;
float voltaje2;