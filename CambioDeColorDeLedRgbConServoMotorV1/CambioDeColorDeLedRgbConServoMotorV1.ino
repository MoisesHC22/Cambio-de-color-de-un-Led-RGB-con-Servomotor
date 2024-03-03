
// Incorporar librerías.
#include <Servo.h>

// Declarar variables.

int led_verde = 5;
int led_azul = 6;
int led_rojo = 7;

// Configuraciones de servo.
int pin_servo = 9;
Servo servo;
int angulo = 0;


void setup()
{
 // Nos sirve para configurar el pin de salida.
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  servo.attach(pin_servo);
  Serial.begin(9600);
}


void loop()
{
  
  /*
       Hacemos un ciclo for en donde, la variable "ángulo" aumentara cada vez que se ejecute
       el bucle aumentando de "0" hasta llegar a "180", se realizara una validación con if en
       donde si ángulo es menor que "90" cambiara el color del led rgb y si no cumple con la 
       condición cambiará de otro color el led.
  */
  
  for(angulo = 0;angulo <= 180; angulo += 1)
  {
   
   /* 
     Con esta sentencia hacemos que el servo se vaya moviendo conforme al valor
     de ángulo cada 50 segundos. 
   */
    servo.write(angulo);
    delay(50);
    
      if(angulo < 90){
        
        // Led rgb con color amarillo.
          digitalWrite(led_verde, 255);
          digitalWrite(led_azul, 0);
          digitalWrite(led_rojo, 255);
        
      }else{
        
        // Led rbg con color azul.
          digitalWrite(led_verde, 255);
          digitalWrite(led_azul, 255);
          digitalWrite(led_rojo, 0);
      
      }
   }
  
  
  
  
  /*
         Hacemos otro ciclo for en donde ahora si el valor anterior de ángulo es "180"
         decrementara 1 cada que se ejecuta, hasta llegar a "0".
  */
   
  for(angulo = 180; angulo >= 0; angulo -=1)
  {
   
   /* 
     Con esta sentencia hacemos que el servo se vaya moviendo conforme al valor
     de ángulo cada 50 segundos. 
   */
     servo.write(angulo);
     delay(50);
  }
  
}
