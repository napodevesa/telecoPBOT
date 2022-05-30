
#include <Servo.h>      // incluye libreria de Servo

Servo servo1;     // crea objeto
Servo servo2;     // crea objeto

char entrada; // Variable para guardar el valor del carácter enviado
int PINSERVO = 2;   // pin 2 conectado a señal del servo
int PINSERVO1 = 3;   // pin 2 conectado a señal del servo
int PULSOMIN = 1000;    // pulso minimo en microsegundos
int PULSOMAX = 2000;    // pulso maximo en microsegundos


void setup()
{
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);  // inicializacion de servo
  servo2.attach(PINSERVO1, PULSOMIN, PULSOMAX);  // inicializacion de servo
  Serial.begin(9600); // Velocidad de comunicación en baudios.
}

void loop()
{

  if (Serial.available() > 0) // Si se recibe un carácter...
    {
      
   entrada = Serial.read(); // Guardamos el valor del carácter en la variable entrada.
      if ((entrada=='a')||(entrada=='A')) // Si el carácter recibido es "D" o "d"
      { 
        int a = servo1.read() + 30   ;  
        servo1.write(a);    // ubica el servo a 0 grados
      }

     if ((entrada=='b')||(entrada=='B')) // Si el carácter recibido es "D" o "d"
      { 
        int a = servo1.read() - 30  ;   
        servo1.write(a);    // ubica el servo a 0 grados
      }
      

       if ((entrada=='c')||(entrada=='C')) // Si el carácter recibido es "D" o "d"
      { 
        int a = servo2.read() + 30   ;  
        servo2.write(a);    // ubica el servo a 0 grados
      }

     if ((entrada=='d')||(entrada=='D')) // Si el carácter recibido es "D" o "d"
      { 
        int a = servo2.read() - 30  ;   
        servo2.write(a);    // ubica el servo a 0 grados
      }
      
    }

}
