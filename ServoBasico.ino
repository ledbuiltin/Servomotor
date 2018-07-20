//Programa para llevar un servo a un angulo dado
//***************************************************************************

#include <Servo.h>  //Libreria del servo

Servo miMotor;    //Creamos objeto de tipo servo al que llamamos miMotor
int angulo=90;    //Angulo al que llevamos el motor

void setup() {

  miMotor.attach(7);  //Indicamos el pin al que conectamos el motor

}
 
void loop() {
  
miMotor.write(angulo);   //Inicamos el motor en posicion central 90º
 
}
  

