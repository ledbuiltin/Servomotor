//Programa para hacer barridos continuamente
//Funciona bien pero si reinicio el arduino el motor no vuelve al bucle
//***************************************************************************

#include <Servo.h>   //Libreria del servo
Servo miMotor;       //Creamos objeto de tipo servo al que llamamos miMotor
int minAngulo=10;    //Angulo minimo del motor alque llega sin vibrar
int maxAngulo=170;   //Angulo Maximo del motor alque llega sin vibrar
 
void setup() {
  Serial.begin(9600);
  while (!Serial) {} // Le damos tiempo a la Leonardo a que conecte (necesario en Leonardo)
  //  --->  OJO, si reiniciamos la placa necesitamos reiniciar también el puerto serie.
  Serial.println("Conexion establecida");
  miMotor.attach(7);  //Indicamos el pin al que conectamos el motor
  miMotor.write(90);   //Inicamos el motor en posicion central 90º
//Recordemos que el motor permite 0-180 aunque en realidad funcionará bien de 10  170
}
 
void loop() {
  Serial.println("Giro a la izda");
  for (int i = minAngulo; i < maxAngulo; i++) { // Al angulo maximo llegara durante el giro en sentido contrario
  miMotor.write(i);
  delay(25);    // Pausa para alcanzar la posicion
  }
  Serial.println("Giro a la dcha");
  for (int i = maxAngulo; i > minAngulo; i--) {
  miMotor.write(i);
  delay(25);    // Pausa para alcanzar la posicion
  }
}
