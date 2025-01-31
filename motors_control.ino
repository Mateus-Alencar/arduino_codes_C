void setup()
{Serial.begin(9600);
  pinMode(4, OUTPUT);  //motor1
  pinMode(5, OUTPUT);  //motor2
  pinMode(8, OUTPUT);  //motor4
  pinMode(13, OUTPUT); //motor3
  pinMode(9, INPUT);   //SW4
  pinMode(10, INPUT);  //SW3
  pinMode(11, INPUT);  //SW2
  pinMode(12, INPUT);  //SW1
}

void loop() {
  if (digitalRead(9) == HIGH) {
    right(); 
  }
  if (digitalRead(10) == HIGH) {
    left(); 
  }
  if (digitalRead(11) == HIGH) {
    forward();
  }
  if (digitalRead(12) == HIGH) {
    backward();
  } 
}
void right() { //sw4
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(13,LOW);
}
void left() { //sw3
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(13,HIGH); 
}
void forward() { //sw2
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  digitalWrite(13,HIGH);
}
void backward() { //sw1
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(13,LOW);
}