/*  TITULO: Control de un LED a través del Monitor Serie
 
    AUTOR:
   
    MARIANO DEL CAMPO GARCÍA (@2015) --> INGENIERO TÉCNICO INDUSTRIAL ESPECIALIDAD ELECTRÓNICA
    - FACEBOOK: https://www.facebook.com/mariano.delcampogarcia
    - TWITTER: https://twitter.com/MarianoCampoGa
    - CORREO: marianodc83@gmail.com
   
   
    DESCRIPCIÓN DEL PROGRAMA
   
    Este programa controla un LED mediante el envío de carácteres a través del monitor serie.
    - Si mandamos "D" o "d" --> El LED se enciende.
    - Si mandamos "I" o "i" --> El LED se apaga.
   
   
    ESQUEMA DE CONEXION
   
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |    
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |    
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |  
         | [ ]IOREF                 MISO/12[ ] |  
         | [ ]RST                   MOSI/11[ ]~|  
         | [ ]3V3    +---+               10[ ]~|  
         | [ ]5v    -| A |-               9[ ]~|  
         | [ ]GND   -| R |-               8[ ] |  
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |  
         |          -| I |-               6[ ]~|  
         | [ ]A0    -| N |-               5[ ]~|   LED(+)
         | [ ]A1    -| O |-               4[ ] |  
         | [ ]A2     +---+           INT1/3[ ]~|  
         | [ ]A3                     INT0/2[ ] |  
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |  
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |  
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
 
  NOTAS:
 
   - Cátodo(-) del LED (pata más corta) a GND a través de una R=220 ohms.
 
*/
 
  int LED = 5; // Pin digital para el LED
  char entrada; // Variable para guardar el valor del carácter enviado
   
  void setup()
  {
    pinMode(LED, OUTPUT); // Pin digital del LED como salida.
    Serial.begin(9600); // Velocidad de comunicación en baudios.
  }
   
  void loop()
  {
    if (Serial.available() > 0) // Si se recibe un carácter...
    {
      entrada = Serial.read(); // Guardamos el valor del carácter en la variable entrada.
   
      if ((entrada=='D')||(entrada=='d')) // Si el carácter recibido es "D" o "d"
      {      
        digitalWrite(LED, HIGH); // Se enciende el LED
        Serial.print("Se ha enviado una "); // Mostramos valores a través del monitor serie
        Serial.write(entrada);
        Serial.print(" --> LED ENCENDIDO!!!");
        Serial.print("\n");
      }
      else if ((entrada=='I')||(entrada=='i')) // Si el carácter recibido es "I" o "i"    
      {
        digitalWrite(LED, LOW); // Se apaga el LED
        Serial.print("Se ha enviado una "); // Mostramos valores a través del monitor serie
        Serial.write(entrada);
        Serial.print(" --> LED APAGADO!!!");
        Serial.print("\n");
      }
    }
  }
