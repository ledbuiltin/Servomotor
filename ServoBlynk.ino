//Programa para llevar un servo a un angulo dado via puerto serie
//Basado en https://www.instructables.com/id/Servo-Motor-Controlled-With-BLYNK-Over-WiFi/
//        y https://www.instructables.com/id/Blynk-Arduino-Servo/
//***************************************************************************

//#define BLYNK_PRINT Serial  //Des-comentar si queremos tener info sobre el programa en el puerto serie
#include <Servo.h>  //Libreria del servo
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "ed8a6b64e7404342a0f42631f200db3e";  //Token de Blynk
char ssid[] = "UPC628450";    //Credenciales WiFi
char pass[] = "LXLKQLIA";

Servo miMotor;        //Creamos objeto de tipo servo al que llamamos miMotor
# define servoPin D1  //Pin al que tenemos conectado el motor GPIO5

BLYNK_WRITE(V1) {                 //Funcion para leer el valor del slider de Blynk (en el slider he seleccionado 9-177 ya que con esos valores barre de 0 a 180)
  miMotor.write(param.asInt());   //y ejecutarlo en el servo
}

void setup() {
Blynk.begin(auth, ssid, pass);   //Pues eso
miMotor.attach(servoPin);         //Indicamos donde esta conectado el servo
}
 
void loop() {
Blynk.run();       //Dale Blynk
}
  

