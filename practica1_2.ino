/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: Contador
   aLumno:Christian SoLorzano
   Fecha: 2/06/2023
*/

// librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
//sensor y boton
#define S 8
#define B 2

//OneWire y DallasTemperature
OneWire oneWire(S);
DallasTemperature sensor(&oneWire);

// Funcion de la  temperatura y boton
void botonS();
void temperature (void);

//Timer del boton y temperatura 
Ticker boton(botonS,6000);
Ticker TEMPERATURA (temperature, 3000);
int Celsius;



void setup() {
  
  Serial.begin(9600);
  sensor.begin();
  TEMPERATURA.start();
  boton.start();
  pinMode(B, INPUT);
  
}

void loop() {
  //TEMPERATURA.update();
  boton.update();
  TEMPERATURA.update(); 
  }

void temperature (void){ 
  sensor.requestTemperatures();
  Celsius = sensor.getTempCByIndex(0); 
  if(Celsius> -127){
  Serial.print(Celsius);
  Serial.println(" C  ");
  delay(100); 
  }
  else if(Celsius= -127){
  Serial.println("Error");
}
}
  
void botonS(){
 
  int estado = digitalRead(B);  
  if(estado == HIGH){
    
    Serial.println("El boton esta");
    Serial.println("Boton Presionado");
  }

  if(estado == LOW){
    Serial.println("El boton esta");
    Serial.println("Boton No Presionado");
  }
}
