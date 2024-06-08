/*
 **********PROYECTO BALAM 2024************
 *  Módulo #4
 *  Prueba de motores con Dabble Joystick
 *  FASE CREA
 */

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>

//Incluir libreria del Dabble
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

//Definir variables

//Motor A
#define PWMA 15
#define AIN1 18
#define AIN2 5

//Motor A1
#define PWMA1 12
#define AIN11 32
#define AIN22 33

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
  // put your setup code here, to run once:
  Serial.begin(115200); // Iniciar el monitor serial 
  Dabble.begin("Pruebas-Balam");  //Nombre del BT
}

void loop() {
  
  Dabble.processInput();    // Esperando conexión por BT  
  Serial.print("KeyPressed: ");

  int angle = GamePad.getAngle();
  int radius = GamePad.getRadius();

  //Prints de los valores obtenidos en la lectura.+
  // Función del map con el radio del joystick
  int speed = map(radius, 0, 7, 50, 150);
  // Iniciar los motores en freno
  brake(motor1, motor2);

  // Hacia la derecha
  if (angle >= 0 && angle < 45) {
    right(motor1, motor2, speed);
    Serial.println("Derecha");
    delay(10);
  }

  // Hacia adelante
  if (angle > 45 && angle < 135) {
    forward(motor1, motor2, speed);
    Serial.println("Adelante");
    delay(10);
  }
  
  // Hacia la izquierda
  if (angle > 135 && angle < 225) {
    left(motor1, motor2, speed);
    Serial.println("Izquierda");
    delay(10);
  }

  // Hacia la atrás
  if (angle > 255 && angle < 315) {
    back(motor1, motor2, speed);
    Serial.println("Atrás");
    delay(10);
  }

   //Bóton "X" para detener
  if (GamePad.isCrossPressed()) {
    Serial.print("Cross");
    brake(motor1, motor2);
    Serial.println("Detener");
    delay(1000);
  }

}
