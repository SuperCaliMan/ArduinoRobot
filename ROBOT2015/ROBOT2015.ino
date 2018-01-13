/* Autore: Caliman Alberto Copyright 2015
 * Titolo: Arduino roboto Visual Basic 
 * 
 * Description: 
 *  
*/
// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9; 

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10; 

void setup() {  
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(dir1PinB,OUTPUT);
pinMode(dir2PinB,OUTPUT);
pinMode(speedPinB,OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
  int inByte = Serial.read();
  
  switch (inByte) { //DECODE DATA FROM BLUETOOTH
    case '1': //forward
    analogWrite(speedPinA, 255);//Set speed variable via PWM 
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    analogWrite(speedPinB, 255);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    break;
    
    case '2': //stop
    analogWrite(speedPinA, 0);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    analogWrite(speedPinB, 0);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    break;
    
    case '3': //backword
    analogWrite(speedPinA, 255);
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    analogWrite(speedPinB, 255);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
    break;
    
    case '4' : //right
    analogWrite(speedPinA, 200);
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    analogWrite(speedPinB, 200);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    break;
    
    case '5' : //left
    analogWrite(speedPinA, 200);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    analogWrite(speedPinB, 200);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
    break;

  default:
    // turn all the connections off if an unmapped key is pressed:
    for (int thisPin = 2; thisPin < 11; thisPin++) {
    digitalWrite(thisPin, LOW);
  }
   }
  }}


  
 


