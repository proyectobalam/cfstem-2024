
//Motor A
int PWMA = 15; //Speed control 
int AIN1 = 18; //Direction
int AIN2 = 5; //Direction

//Motor A1
int PWMA1 = 12; //Speed control 
int AIN11 = 32; //Direction
int AIN22 = 33; //Direction

//Motor B
int PWMB = 2; //Speed control
int BIN1 = 27; //Direction
int BIN2 = 14; //Direction

//Motor B1
int PWMB1 = 13; //Speed control
int BIN11 = 25; //Direction
int BIN22 = 26; //Direction

void setup(){
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  
  pinMode(PWMA1, OUTPUT);
  pinMode(AIN11, OUTPUT);
  pinMode(AIN22, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  pinMode(PWMB1, OUTPUT);
  pinMode(BIN11, OUTPUT);
  pinMode(BIN22, OUTPUT);

  Serial.begin(115200);
}

void loop(){
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);

  digitalWrite(PWMA1, HIGH);
  digitalWrite(PWMB1, HIGH);
  
    //Hacia adelante
  analogWrite(AIN1, 250);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 250);
  analogWrite(BIN2, 0);

  analogWrite(AIN11, 250);
  analogWrite(AIN22, 0);
  analogWrite(BIN11, 250);
  analogWrite(BIN22, 0);
  
  Serial.println("Adelante");
  delay(5000);
  
  //Hacia atrás
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 250);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 250);

  analogWrite(AIN11, 0);
  analogWrite(AIN22, 250);
  analogWrite(BIN11, 0);
  analogWrite(BIN22, 250);
  
  Serial.println("Atrás");
  delay(2000);
  
      //Hacia derecha
  analogWrite(AIN1, 250);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 250);

  analogWrite(AIN11, 250);
  analogWrite(AIN22, 0);
  analogWrite(BIN11, 0);
  analogWrite(BIN22, 250);
  
  Serial.println("Derecha");
  delay(2000);
  
  //Hacia izquierdo
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 250);
  analogWrite(BIN1, 250);
  analogWrite(BIN2, 0);

  analogWrite(AIN11, 0);
  analogWrite(AIN22, 250);
  analogWrite(BIN11, 250);
  analogWrite(BIN22, 0);
    
  Serial.println("Izquierda");
  delay(2000);
}
