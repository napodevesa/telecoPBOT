/*
PBOT
*/

#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial miBT(8, 9);  // pin 8 como TX, pin 9 como RX

char dato = 0;      // variable para almacenar caracter recibido

//Pines de conexión del driver
int Pin_Motor_Der_A = 13;
int Pin_Motor_Der_B = 12;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 10;
int tiempo=0;

void setup(){
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps

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
