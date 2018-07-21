//Programa para llevar un servo a un angulo dado via puerto serie
//Basado en https://www.youtube.com/watch?v=fE4m7TyLd8M&t=1299s
//***************************************************************************

#include <Servo.h>  //Libreria del servo

Servo miMotor;    //Creamos objeto de tipo servo al que llamamos miMotor
int angulo=90;    //Angulo al que llevamos el motor
int servoDelay=25;
# define servoPin D1   //Para NodeMCU
//int servoPin=12;     //Para Arduino
int maxAngulo=177;
int minAngulo=9;
//He usado este mismo programa para determinar los valores max y minimos de mi motor MG9996R
//Entre estos valores el motor no tiembla y hace un barrido de 180 grados


void setup() {
Serial.begin(9600);
//while(!Serial){}  //Descomentar con Leonardo: esperamos a que la conexion esté establecida.
Serial.println("Conexion serie establecida");
miMotor.attach(servoPin);  //Indicamos el pin al que conectamos el motor

}
 
void loop() {

Serial.print("Introduce el angulo al que quieras ir entre " ); Serial.print(minAngulo); Serial.print(" y "); Serial.println(maxAngulo);
while (Serial.available()==0) {}  //Esperamos aqui hasta que se introduzca algo en el puerto serie
angulo=Serial.parseInt();         //Leemos la entrada de usuario. Ojo, no usar Serial.read() para evitar problema de lectura en ASCII

  if((angulo>=minAngulo)&&(angulo<=maxAngulo)){  //Comprobamos que el agulo está dentro del rango del motor
  miMotor.write(angulo);            //LLevamos el motor a esa posicion
  Serial.print("Motor en posicion ");
  Serial.println(angulo);
  }
  else Serial.println("Valor fuera del rango");
}
  

