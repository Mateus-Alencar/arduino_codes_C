#define ledVerde A3
#define ledAmarelo A4
#define ledVermelho A2
#define buzzer 4
#define pir 2

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin,OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
  
}
void setup()
{
  pinMode(A1, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if (digitalRead(A1) == HIGH) {
    if(0.01723 * readUltrasonicDistance(2,1) < 150 && 0.01723 * readUltrasonicDistance(2,1)>100){
    	digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledVerde, HIGH);
      	tone(buzzer,29,1000);
      delay(1000);
      noTone(buzzer);
      delay(600);
      
    }else{
    if(0.01723 * readUltrasonicDistance(2,1) < 100 && 0.01723 * readUltrasonicDistance(2,1)>30){
    	digitalWrite(ledAmarelo, HIGH);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledVerde, LOW);
      	tone(buzzer,29,1000);
      delay(1000);
      noTone(buzzer);
      delay(600);
      
    }else{
      if(0.01723 * readUltrasonicDistance(2,1) < 30 && 0.01723 * readUltrasonicDistance(2,1)>0){
    	digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, HIGH);
        digitalWrite(ledVerde, LOW);
      	tone(buzzer,29,1000);
      delay(1000);
      noTone(buzzer);
      delay(600);
      }
    }
    }
    }else{
      if (digitalRead(A1) == LOW){
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledVerde, LOW);
        noTone(4);
      }
     }
}
    
  
