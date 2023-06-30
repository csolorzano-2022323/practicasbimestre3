/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: Cinta transportadora
   aLumno:Christian SoLorzano
   Fecha: 15/06/2023
*/
#include <Servo.h>
#define SO 6
#define LEDFOTO A0
#define LEDA  8
#define LEDR  7
#define LEDV  9

int intensidadA, intensidadR, intensidadV;
int resultado;
int tol = 8;
bool value = 0;
int contador = 0;
Servo servo;

void setup() {

  Serial.begin(9600);
  pinMode(SO, INPUT);
  pinMode(LEDFOTO, INPUT);
  pinMode(LEDA, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(LEDA, LOW);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDV, LOW);


  servo.attach(10);
  servo.write(90);
  delay(1000);
  servo.write(0);


}

void loop() {

  value = digitalRead(SO);

  if (value == HIGH) {

    // PASO 1
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(1);

    //PASO 2
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(1);

    //PASO 3
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(1);

    //PASO 4
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 5

    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 6
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 7
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 8
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1);



  }

  if (value == LOW) {

    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1000);
    SLUM();

    if ((intensidadV >= 130 && intensidadV <= 131) && (intensidadR >= 130 && intensidadR <= 131) && (intensidadA >= 130 && intensidadA <= 131)) {
    servo.write(1000);
    delay(2000);
    servo.write(0);
  }
   else { 
    
    caminar();
   }
  }
 
}

void SLUM() {

  digitalWrite(LEDR, HIGH);
  delay(150);
  resultado = analogRead(LEDFOTO);
  intensidadR = map(resultado, 0, 1023, 255, 0);
  Serial.print("R= ");
  Serial.println(intensidadR);
  digitalWrite(LEDR, LOW);
  delay(250);

  digitalWrite(LEDV, HIGH);
  delay(250);
  resultado = analogRead(LEDFOTO);
  intensidadV = map(resultado, 0, 1023, 255, 0);
  Serial.print("G = ");
  Serial.println(intensidadV);
  digitalWrite(LEDV , LOW);
  delay(250);

  digitalWrite(LEDA, HIGH);
  delay(250);
  resultado = analogRead(LEDFOTO);
  intensidadA = map(resultado, 0, 1023, 255, 0);
  Serial.print("B= ");
  Serial.println(intensidadA);
  digitalWrite(LEDA, LOW);
  delay(150);

    

  /*if ((intensidadV >= 0 && intensidadV <= 128) && (intensidadR >= 124 && intensidadR <= 128) && (intensidadA >= 124 && intensidadA <= 128)) {
    servo.write(90);
    delay(100);
    servo.write(0);
*/
}

void caminar() {

  int tiempo = 1;
  int pos = 0;

  for(pos=0; pos <301; pos+=1){

  // PASO 1
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 2
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 3
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 4
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 5

    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 6
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 7
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 8
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);
  }
  for(pos=300; pos >=0; pos-=1){

  // PASO 1
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 2
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 3
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(tiempo);

    //PASO 4
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(1);

    //PASO 5

    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 6
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 7
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);

    //PASO 8
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(tiempo);
  }
  
  }
  
