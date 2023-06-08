/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: Control de una secuencia de colores RGB
   aLumno:Christian SoLorzano
   Fecha: 8/06/2023
*/
#define R 3
#define G 5
#define B 6
#define POT A0
int D;

void setup() {

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(POT, INPUT);

}

void loop() {
  //transformo los limites para asi cambiar el delay
  D = map(analogRead(POT), 0, 1023, 100, 1000);

  //AnalogWrite pone valores a los leds 
  // D= Son los nuevos limites
  analogWrite(R, 174);
  analogWrite(G, 92);
  analogWrite(B, 230);
  delay(D);
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
  delay(D);
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 255);
  delay(D);
  analogWrite(R, 189);
  analogWrite(G, 174);
  analogWrite(B, 20);
  delay(D);
  analogWrite(R, 255);
  analogWrite(G, 87);
  analogWrite(B, 35);
  delay(D);


}
