#include <LiquidCrystal_I2C.h>

/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: OHMIMETRO
   aLumno:Christian SoLorzano
   Fecha: 8/06/2023
*/
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  LCD.init();
  LCD.backlight();
}

void loop() {

  float R2 = 10000;
  float Vout = analogRead(A0);
  float Vout2= map(Vout,0,1023,0,500000);
  LCD.setCursor(0,1);
  float Vout3= Vout2/100000;
  float V1 = (R2*5) / Vout3;
  float R1 = V1 - R2;
  R1=R1+9;
  LCD.setCursor(0, 0);
  LCD.print("R1=");
  LCD.setCursor(3, 0);
  LCD.print(R1);
  




}
