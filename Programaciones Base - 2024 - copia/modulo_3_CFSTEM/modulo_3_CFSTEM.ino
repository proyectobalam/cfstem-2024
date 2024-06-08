/*
 **********PROYECTO BALAM 2024************
 *  Módulo #3
 *  Prueba de motores con Dabble D-Pad
 *  FASE CREA
 */
#include <ESP32Servo.h>
Servo myservo;

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>
//Incluir libreria del Dabble
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

//Motor A
#define PWMA 15
#define AIN1 18
#define AIN2 5

//Motor A1
#define PWMA1 12
#define AIN11 33
#define AIN22 32

//Motor B
#define PWMB 2
#define BIN1 27
#define BIN2 14

//Motor B1
#define PWMB1 13
#define BIN11 25
#define BIN22 26

#define STBY 0
#define STBY1 22

const int offsetA = 1;
const int offsetB = 1;

const int offsetA1 = 1;
const int offsetB1 = 1;

//Iniciar motores
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

//Iniciar motores
Motor motor11 = Motor(AIN11, AIN22, PWMA1, offsetA1, STBY1,5000 ,8,4 );
Motor motor22 = Motor(BIN11, BIN22, PWMB1, offsetB1, STBY1,5000 ,8,5 );

void setup() {
  Serial.begin(115200);   // Iniciar el monitor serial  
  Dabble.begin("Balam2");       //Nombre del BT
  myservo.attach(4);
}

void loop() {

  Dabble.processInput(); // Esperando conexión por BT            
  Serial.println("KeyPressed: ");
  
  //Utilización de la XPAD (cruzeta) del control por DABBLE
  if (GamePad.isUpPressed())
  {
    back(motor1, motor2, 255);
    forward(motor11, motor22, 255);
    Serial.println("Adelante");
    delay(10);
  }

  if (GamePad.isDownPressed())
  {
     forward(motor1, motor2, 255);
     back(motor11, motor22, 255);
     Serial.println("Atrás");
     delay(10);
     
  }

  if (GamePad.isLeftPressed())
  {
     forward(motor1, motor11, 255);
     back(motor2, motor22, 255);
     Serial.println("Atrás");
     Serial.println("Izquierda");
     delay(10);
    
  }
  if (GamePad.isRightPressed())
  {
     forward(motor2, motor22, 255);
     back(motor1, motor11, 255);
     Serial.println("Derecha");
     delay(10);
  }
  //Bóton "X" para detener
  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
     brake(motor1, motor2);
     brake(motor11, motor22);
     Serial.println("Detener");
     delay(10);
  }


  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");  
      myservo.write(90); 
  }
  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    myservo.write(0);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    myservo.write(180);
  }
  

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
}
 
