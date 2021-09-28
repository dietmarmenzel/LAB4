//*****************************************************************************
// Universidad del Valle de Guatemala
// BE3015 - Electrónica Digital 2
// Gunther Dietmar Menzel - 19106
// LAB4
//*****************************************************************************

//*****************************************************************************
// Librerías
//*****************************************************************************
//Librería para la pantalla LCD
#include <Arduino.h>
#include <LiquidCrystal.h>

//*****************************************************************************
// Definición de pines
//*****************************************************************************
//Definición de pines para la pantalla LCD
#define d4 14
#define d5 27
#define d6 26
#define d7 25
#define en 12
#define rs 13
//Definición de pines para los potenciómetros
#define pot1 34
#define pot2 35
//Definición de pines para los botones
#define boton1 23
#define boton2 22

//*****************************************************************************
// Prototipos de función
//*****************************************************************************
//Varibale para el contador de 8 bits
void Contador(void);

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int ContadorBoton1 = 0; //Contador Boton en entero

// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);
//Decenas, unidades y decimales para los dos voltajes
uint8_t decenas, unidades, decimal;
uint8_t decenas2, unidades2, decimal2;
int adcRaw;
float voltaje1; //Voltaje1 para el primer potenciómetro
float voltaje2; //Voltaje2 para el segundo potenciómetro

//*****************************************************************************
// Configuración
//*****************************************************************************
void setup() {
  Serial.begin(115200); //Configuración serial
  //LCD_Init(rs, en, d4, d5, d6, d7);
  // Initialize The LCD. Parameters: [ Columns, Rows ]
  LCD.begin(16, 2); //Pantalla LCD 16*2
  
  //Configuración de los pines de los botones
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  
}

//*****************************************************************************
// Loop Principal
//*****************************************************************************
void loop() {
  Contador ();

  //Asignando los valores del voltaje 1, decenas, unidades y decimales
  voltaje1 = analogReadMilliVolts(pot1) / 10.0; //Voltaje para el potenciómetro 1
  int temp = voltaje1; 
  decenas = temp / 100.0;
  temp = temp - decenas *100.0;
  unidades = temp / 10.0;
  temp = temp - unidades *10.0;
  decimal = temp;

  //Imprimiendo voltaje 1
  Serial.print(voltaje1);
  Serial.print("\t");

  //Asignando los valores del voltaje 2, decenas, unidades y decimales
  voltaje2 = analogReadMilliVolts(pot2) / 10.0; //Voltaje para el potenciómetro 2
  int temp2 = voltaje2;
  decenas2 = temp2 / 100.0;
  temp2 = temp2 - decenas2 *100.0;
  unidades2 = temp2 / 10.0;
  temp2 = temp2 - unidades2 *10.0;
  decimal2 = temp2;

  //Imprimiendo voltaje 2
  Serial.print(voltaje2);
  Serial.print("\t");

  //Imprimiendo las decenas, unidades y decimales del potenciometro 1
  Serial.print(decenas);
  Serial.print("\t");
  Serial.print(unidades);
  Serial.print("\t");
  Serial.println(decimal);

  //Imprimiendo las decenas, unidades y decimales del potenciometro 2
  Serial.print(decenas2);
  Serial.print("\t");
  Serial.print(unidades2);
  Serial.print("\t");
  Serial.println(decimal2);

  //Imprimiendo el contador del boton
  Serial.print("\t");
  Serial.println(ContadorBoton1);

  //Asignando lo que tiene que decir la pantalla LCD
  LCD.clear();
  LCD.print("Vol1:");
  LCD.print(" ");
  LCD.print("Vol2:");
  LCD.print(" ");
  LCD.print("CPU:");

  LCD.setCursor(1,1);
  LCD.print(decenas);
  LCD.print('.');
  LCD.print(unidades);
  LCD.print(decimal);
  
  LCD.print (" ");
  LCD.print(decenas2);
  LCD.print('.');
  LCD.print(unidades2);
  LCD.print(decimal2);

  //Iniciando los parámetros en los que tiene que trabajar el contador de 8 bits
  void Contador(void){

    int b1 = digitalRead(boton1);
    int b2 = digitalRead(boton2);

    if (b1 == 0)
    {
      ContadorBoton1 = ContadorBoton1 + 1;
      if (ContadorBoton1 > 255)

      {
        ContadorBoton1 = 0;
      }
    }
    if (b2 == 0)
    {
      ContadorBoton1 = ContadorBoton1 - 1;
      if (ContadorBoton1 < 0)

      {
        ContadorBoton1 = 255;
      }

    }
  }
  
  LCD.print (" ");
  LCD.print(ContadorBoton1);
  
  delay(2);
  
}

//FIN DEL CÓDIGO