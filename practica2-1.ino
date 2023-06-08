
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

//Directivas
#define LED  3 //LED
int POT=0; // Potenciometro
int brillo; // intensidad del led


void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {

  int brillo = map(analogRead(POT),0,1023,0,255);
  analogWrite(LED,brillo);

}
