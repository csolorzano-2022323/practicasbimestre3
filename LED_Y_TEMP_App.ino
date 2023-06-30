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

#include <SoftwareSerial.h>
#include <OneWire.h>
#include <Wire.h>
#include <DallasTemperature.h>
#include <Ticker.h>


OneWire ourWire(5);
DallasTemperature sensors(&ourWire);

#define led 2 

char recepcion;
SoftwareSerial BT(10, 11);
void temps (void);
Ticker temp_ticker(temps, 10000);

void setup()
{
  Serial.begin(9600);
  Serial.println("listo");
  BT.begin(9600);
  pinMode(led, OUTPUT);
  sensors.begin();
  temp_ticker.start();
}

void loop()
{

  if (BT.available())
  {
    recepcion = BT.read();

    if (recepcion == '1') {
      digitalWrite(led, HIGH);
      Serial.print("on");
    }

    if (recepcion == '2') {
      digitalWrite(led, LOW);
      Serial.print("off");
    }
  }
}

void temps (void)
{
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  BT.print(temp);
  BT.println(" C");
}
