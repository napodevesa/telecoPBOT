/*
PBOT
*/

#include <Servo.h>      // incluye libreria de Servo
#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial miBT(8, 9);  // pin 8 como TX, pin 9 como RX
Servo servo1;     // crea objeto servo1
Servo servo2;     // crea objeto servo2

int PINSERVO = 2;   // pin 2 conectado a señal del servo
int PINSERVO1 = 3;   // pin 3 conectado a señal del servo2
int PULSOMIN = 1000;    // pulso minimo en microsegundos
int PULSOMAX = 2000;    // pulso maximo en microsegundos

char dato = 0;      // variable para almacenar caracter recibido

//Pines de conexión del driver
int Pin_Motor_Der_A = 13;
int Pin_Motor_Der_B = 12;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 10;
int tiempo=0;

void setup(){
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);  // inicializacion de servo
  servo2.attach(PINSERVO1, PULSOMIN, PULSOMAX);  // inicializacion de servo

// configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
}

void loop(){
if (miBT.available()) {      // si hay informacion disponible desde modulo
  
  dato = miBT.read();   // almacena en DATO el caracter recibido desde modulo

  if( dato == '1' ){
    Mover_Adelante();
        tiempo=0;
  }

  if( dato == '4' ){
    Mover_Retroceso();
        tiempo=0;
  }

  if( dato == '2' ){
    Mover_Izquierda();
        tiempo=0;
  }

  if( dato == '3' ){
      Mover_Derecha();
        tiempo=0;
    }

  if( dato == '5' ){
      Mover_Stop();
        tiempo=0;
    }

  if (dato=='a') // Si el carácter recibido es a
      { 
      int a = servo1.read() + 30   ;  
        servo1.write(a);    
      }

  if (dato=='b') // Si el carácter recibido es b
      { 
      int a = servo1.read() - 30  ;   
        servo1.write(a);    // ubica el servo a 0 grados
      }
  if (dato=='c') // Si el carácter recibido es c
      { 
       int a = servo2.read() + 30   ;  
       servo2.write(a);    
      }

  if (dato=='d')
      { 
      int a = servo2.read() - 30  ;   
      servo2.write(a);    // ubica el servo a 0 grados
      }

 if(tiempo<200) // 100 cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
  }
  
  delay(1); //pasusa de 1ms por ciclo

  }
}
void Mover_Adelante()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}

void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Izquierda()
{
  digitalWrite (Pin_Motor_Der_A,HIGH);
  digitalWrite (Pin_Motor_Der_B,LOW);
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
