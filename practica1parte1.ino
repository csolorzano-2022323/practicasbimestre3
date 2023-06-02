/*
   Fundacion KinaL
   Centro educativo tecnico LaboraL KinaL
   Quinto perito
   Quinto eLectronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: TaLLer de eLectronica digitaL y reparacion de computadoras I
   Proyecto: Contador
   aLumno:Christian SoLorzano
   Fecha: 1/06/2023
*/

#define btn_up  2     //pin 2 utiLizado para una interrupción externa por rising
#define btn_down 3     //pih 3 utiLizado para una interrupción externa por faLLing 
#define A 4
#define B 5
#define C 6
#define D 7
#define AA 11
#define AB 10
#define AC 9
#define AD 8
#define DWH(pin)  digitaLWrite(pin,HIGH)
#define DWL(pin)  digitaLWrite(pin,LOW)
void asendente (void);
void desendente(void);
int contadorB = 0;
int contadorA = 0;



void setup() {

  Serial.begin(9600); //Inicio La comunicación seriaL
  pinMode(btn_up, INPUT);  //pin 2 como entrada
  pinMode(btn_down, INPUT); //pin 3 como entrada
  attachInterrupt(digitalPinToInterrupt(btn_up), asendente, RISING);
  attachInterrupt(digitalPinToInterrupt(btn_down), desendente, RISING);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
  pinMode(AC, OUTPUT);
  pinMode(AD, OUTPUT);
}

void loop() {
if ((contadorB > 0) && (contadorA == 5)) {
    contadorB = 0;
    contadorA = 0;
  }
  if ((contadorB < 0) && (contadorA == 0)) {
    contadorB = 0;
    contadorA = 5;
  }

//asendente
  if (contadorB > 9) {
    contadorB = 0;
    contadorA = contadorA + 1;
  }
//desendente
  if (contadorB < 0) {
    contadorB = 9;
    contadorA = contadorA - 1;
  }

  


    switch (contadorB) {

    case (0):
      {
        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, LOW);
        digitalWrite(AC, LOW);
        digitalWrite(AD, LOW);
        break;
      }

    case (1):
      {

        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, LOW);
        digitalWrite(AC, LOW);
        digitalWrite(AD, HIGH);
        break;
      }

    case (2):
      {

        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, LOW);
        digitalWrite(AC, HIGH);
        digitalWrite(AD, LOW);
        break;
      }
    case (3):
      {

        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, LOW);
        digitalWrite(AC, HIGH);
        digitalWrite(AD, HIGH);
        break;
      }

    case (4):
      {

        digitalWrite(AA, LOW);
        digitalWrite(AB, HIGH);
        digitalWrite(AC, LOW);
        digitalWrite(AD, LOW);
        break;
      }

    case (5):
      {


        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, HIGH);
        digitalWrite(AC, LOW);
        digitalWrite(AD, HIGH);
        break;
      }
    case (6):
      {


        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, HIGH);
        digitalWrite(AC, HIGH);
        digitalWrite(AD, HIGH);
        break;
      }

    case (7):
      {


        // DISPLAY 2
        digitalWrite(AA, LOW);
        digitalWrite(AB, HIGH);
        digitalWrite(AC, HIGH);
        digitalWrite(AD, HIGH);
        break;
      }

    case (8):
      {


        // DISPLAY 2
        digitalWrite(AA, HIGH);
        digitalWrite(AB, LOW);
        digitalWrite(AC, LOW);
        digitalWrite(AD, LOW);
      }
    case (9):
      {

        // DISPLAY 2
        digitalWrite(AA, HIGH);
        digitalWrite(AB, LOW);
        digitalWrite(AC, LOW);
        digitalWrite(AD, HIGH);
      }
  }


  switch (contadorA) {

    case (0):
      {
        // DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        break;
      }

    case (1):
      {

        // DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        break;
      }

    case (2):
      {

        // DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        break;
      }
    case (3):
      {

        // DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        break;
      }

    case (4):
      {
        //DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        break;
      }

    case (5):
      {
        // DISPLAY 1
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        break;
      }
  }


}


//Funciones asendentes y desendentes
void asendente (void)
{
  contadorB++;
}

void desendente(void)
{
  contadorB--;
}
