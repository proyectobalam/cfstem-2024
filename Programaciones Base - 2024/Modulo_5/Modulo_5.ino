/*
 **********PROYECTO BALAM 2024************
 *  Módulo #5
 *  Prueba de motores con control de PS4
 *  FASE CREA
 */
#include <ESP32Servo.h>
Servo myservo;
#include <PS4Controller.h>

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>

//Definir variables y pines del motor
//Motor A
#define PWMA 15
#define AIN1 5
#define AIN2 18 

//Motor A1
#define PWMA1 12
#define AIN11 33
#define AIN22 32

//Motor B
#define PWMB 2
#define BIN1 14
#define BIN2 27

//Motor B1
#define PWMB1 13
#define BIN11 25
#define BIN22 26

#define STBY 0
#define STBY1 22

// estas constantes se utilizan para permitirle realizar la configuración del motor
// alinearse con nombres de funciones como forward. El valor puede ser 1 o -1
const int offsetA = 1;
const int offsetB = 1;

const int offsetA1 = 1;
const int offsetB1 = 1;


// Inicializando motores. La biblioteca le permitirá los motores.
// Si está utilizando funciones como reenviar que toman 2 motores como argumentos puedes escribir nuevas funciones o
// llama a la función más de una vez.

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

Motor motor11 = Motor(AIN11, AIN22, PWMA1, offsetA1, STBY1,5000 ,8,4 );
Motor motor22 = Motor(BIN11, BIN22, PWMB1, offsetB1, STBY1,5000 ,8,5 );

void setup() {
  Serial.begin(115200); // Iniciar el monitor serial
  PS4.begin("ec:62:60:c3:2b:16"); // Dirección MAC, de la ESP32
  Serial.println("Ready."); 
  myservo.attach(4);
}

void loop() {
  // Establecer una conexión con el control
  if (PS4.isConnected()) {
    Serial.printf("Battery Level : %d\n", PS4.Battery());

    // Joystick derecho controla el motor derecho
    int LStickY = PS4.LStickY();
    if (LStickY != 0) {
      LStickY = map(LStickY, -128, 128, -255, 255); // Función map con el joystick conviertiendo con valores del motor
      Serial.printf("Left Stick y at %d\n", LStickY);
      motor1.drive(LStickY,10);
      motor22.drive(LStickY,10);
    }

    // Joystick izquierdo controla el motor izquierdo
    int RStickY = PS4.RStickY();
    if (RStickY != 0) {
      RStickY = map(RStickY, -128, 128, -255, 255); // Función map con el joystick convirtiendo con valores del motor
      Serial.printf("Right Stick y at %d\n", RStickY);
      motor2.drive(RStickY,10);
      motor11.drive(RStickY,10);
    }
            if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
      myservo.attach(4);
      //myservo.attached();
      myservo.write(180);
      Serial.println("Activado disparador");
      delay(10);
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
      myservo.attach(4);
      //myservo.attached();
      myservo.write(0);
      Serial.println("Activado subcionador");
      delay(10);
    }
    if (PS4.L1()){
      Serial.println("L1 Button");
      myservo.detach();
      Serial.println("Desactivado disparador");
      delay(10);
    }
       
}
  Serial.println("");
  delay(30);

}
