/*
 PROGRAMACIÓN MÓDULO 1 
 PROYECTO BALAM 2024 
  
 */

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>

//Definir variables y pines del motor
//Motor A
#define PWMA 15
#define AIN1 18
#define AIN2 5

//Motor B
#define PWMB 2
#define BIN1 27
#define BIN2 14

//Definir variables y pines del lanzador
//Motor A1
#define PWMA1 12
#define AIN11 32
#define AIN22 33

//Motor B1
#define PWMB1 13
#define BIN11 25
#define BIN22 26

//Definiciones necesarias para la libreria del motor
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


void setup(){
  Serial.begin(115200);
}

void loop(){
    //Uso de la función drive que toma como argumento la velocidad y el timpo es opcional. 
    //La velocidad puede ser de -255 a 255.
     motor1.drive(255,1000);
     motor1.drive(-255,1000);    //Valores negativos hara que cambie la dirección
     motor1.brake();
     Serial.println("Motor 1 en acción");
     delay(1000);
  
     motor2.drive(255,1000);
     motor2.drive(-255,1000);
     motor2.brake();
     Serial.println("Motor 2 en acción");
     delay(1000);

     motor11.drive(255,1000);
     motor11.drive(-255,1000);    //Valores negativos hara que cambie la dirección
     motor11.brake();
     Serial.println("Lanzador 1 en acción");
     delay(1000);
  
     motor22.drive(255,1000);
     motor22.drive(-255,1000);    //Valores negativos hara que cambie la dirección
     motor22.brake();
     Serial.println("Lanzador 2 en acción");
     delay(1000);

     //Función "forward" de la libreria para avanzar hacía adelante
     forward(motor1, motor2, 200);
     Serial.println("Adelante");
     delay(1000);

     forward(motor11, motor22, 200);
     Serial.println("Lanzador activo");
     delay(1000);
     
     //Función "back" de la libreria para avanzar hacía atrás
     back(motor1, motor2, -150);
     Serial.println("Atrás");
     delay(1000);

     //Función "brake" de la libreria para avanzar detener motores
     brake(motor1, motor2);
     Serial.println("Detener");
     delay(1000);

    //Uso de las funciones izquierda y derecha que toman como argumentos dos
    //motores y una velocidad. Esta función hace que ambos motores se muevan la dirección adecuada.
     left(motor1, motor2, 200);//Izquierda
     Serial.println("Izquierda");
     delay(1000);
     right(motor1, motor2, 200);//Derecha
     Serial.println("Derecha");
     delay(1000);


     //Función "brake" de la libreria para avanzar detener motores
     brake(motor1, motor2);
     Serial.println("Detener");
     brake(motor11, motor22);
     Serial.println("Lanzador Detenido");
     delay(1000);
}
