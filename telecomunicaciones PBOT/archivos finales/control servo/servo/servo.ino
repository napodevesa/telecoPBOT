
#include <Servo.h>      // incluye libreria de Servo

Servo servo1;     // crea objeto

char entrada; // Variable para guardar el valor del carácter enviado
int PINSERVO = 2;   // pin 2 conectado a señal del servo
int PULSOMIN = 1000;    // pulso minimo en microsegundos
int PULSOMAX = 2000;    // pulso maximo en microsegundos


void setup()
{
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);  // inicializacion de servo
      Serial.begin(9600); // Velocidad de comunicación en baudios.

}

void loop()
{

  if (Serial.available() > 0) // Si se recibe un carácter...
    {
   entrada = Serial.read(); // Guardamos el valor del carácter en la variable entrada.
      if ((entrada=='C')||(entrada=='c')) // Si el carácter recibido es "D" o "d"
      {      
        servo1.write(0);    // ubica el servo a 0 grados
      }
      if ((entrada=='N')||(entrada=='n')) // Si el carácter recibido es "I" o "i"    
      {
        servo1.write(90);    // ubica el servo a 0 grados
      }

      if ((entrada=='O')||(entrada=='o')) // Si el carácter recibido es "I" o "i"    
      {
        servo1.write(180);    // ubica el servo a 0 grados
      }
      
    }

 
}
