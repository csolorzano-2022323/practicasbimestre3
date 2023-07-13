/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: Prender, apagar un led por el celular
   aLumno:Christian SoLorzano
   Fecha: 26/06/2023
*/
#include <Ticker.h>
#include <LedControl.h>   //libreria que me permite usar el controlador led max7219
#define dataPin0   12   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 11   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  10   //pin 10 conectado al pin de carga del max7219.

LedControl matrixF = LedControl(dataPin0, dataClock0, dataLoad0, 1);
byte FUEGO_0[8] = {
  B00000000,
  B00001100,
  B00101100,
  B00111110,
  B10111111,
  B10111111,
  B11111111,
  B11111111
};
byte  FUEGO_1[8] = {
  B00000000,
  B00000000,
  B00001000,
  B00101100,
  B00111110,
  B00111110,
  B11111111,
  B11111111
};

byte  FUEGO_2[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B10111100,
  B10111110,
  B11111111
};

byte  FUEGO_3[8] = {
  B00000000,
  B00001100,
  B00101100,
  B00111110,
  B10111111,
  B10111111,
  B11111111,
  B11111111
};

byte  HIELO_0[8] = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};
byte  HIELO_2[8] = {
  B10011001,
  B01011010,
  B00111100,
  B11100111,
  B11100111,
  B00111100,
  B01011010,
  B10011001
};



int i;
int MQ, conver;
unsigned long update_delay = 850;

void medicion(void);
Ticker medicionT(medicion, 2000);
void setup() {
  Serial.begin(9600);
  matrixF.shutdown(0, false); //Activo el max7219 para poder mostrar los digitos.
  matrixF.setIntensity(0, 15); //Brilo a la mitad
  matrixF.clearDisplay(0);    //limpio el display
  Serial.println("Medidor de fuego y matrix led");
  medicionT.start();
}

void loop() {
   medicionT.update();
   if (conver < 40) {

    Serial.println("Sin presencia de fuego");
    //nieve
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, HIELO_2[i]);
      
    }
    delay(500);
     matrixF.clearDisplay(0);
  }
  if (conver >40 ) {
    Serial.println("Fuego detectado");
    //fuego
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, FUEGO_0[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, FUEGO_1[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, FUEGO_2[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, FUEGO_3[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++)
    {
      matrixF.setRow(0, i, FUEGO_2[i]);
    }
    delay(1000);    
  }
    
}

void medicion(void) {

  MQ = analogRead(A0);
  conver = map(MQ, 0, 1023, 0, 100);
  Serial.println(conver);  
}
}

