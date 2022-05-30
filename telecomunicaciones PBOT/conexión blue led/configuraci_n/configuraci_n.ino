/*
  Capitulo 24 de Arduino desde cero en Español.
  Programa que permite establecer una comunicacion con el modulo Bluetooth HC-05
  y configurarlo de manera tal que pueda ser vinculado mediante un telefono
  movil o dispositivo compatible.

  Autor: bitwiseAr  

*/

#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX

char DATO = 0;
int LED1 = 2;
int LED2 = 3;

void setup(){
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
}

void loop(){
if (miBT.available())       // si hay informacion disponible desde modulo
  
  DATO = miBT.read();
  
  if (DATO == '1')
  digitalWrite (LED1, HIGH);
  
   if (DATO == '2')
  digitalWrite (LED1, LOW);
   
   if (DATO == '3')
  digitalWrite (LED2, HIGH);
  
  if (DATO == '4')
  digitalWrite (LED2, LOW);
  

}
