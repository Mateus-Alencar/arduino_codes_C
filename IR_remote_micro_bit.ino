#include <IRremote.h>
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h> 
Servo motor;
#define ledVermelho 6
int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
decode_results results;
int seconds = 0;
Adafruit_LiquidCrystal lcd_1(0);
#define pir 8
#define PIN_POTENTIOMETER A2
#define PIN_PWM 13

const int motorPin = 13;
const int buttonPin = 7;
int buttonState = 0;
int motorState = 0;

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
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(4, OUTPUT);
  lcd_1.begin(16, 2);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  pinMode(ledVermelho, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  motor.attach(PIN_PWM);
}
void loop(){
  
  int potValue = analogRead(PIN_POTENTIOMETER);
  int speed = map(potValue, 0, 1023, 0, 180);
  
 
  
  if (digitalRead(5) == HIGH) {
  if( speed==90) motor.write(LOW);
   
  delay(30);
  motor.write(speed);
  
  delay(300);
    
    
    
    if(0.01723 * readUltrasonicDistance(8,9) < 150 && 0.01723 * readUltrasonicDistance(8,9)>100){
    digitalWrite(ledVermelho, HIGH);
      
    
    }else {digitalWrite(ledVermelho, LOW);}
  
  }
  
  if(irrecv.decode(&results)){             
  Serial.println(results.value, HEX);
    switch(results.value){
    case 0xFD08F7:
      digitalWrite(4, HIGH);
    }
  
  if(digitalRead(2) == LOW){
  lcd_1.setCursor(4, 1);
  lcd_1.print("RADIO FM ");
    lcd_1.print(seconds);
  delay(2);
  seconds += 1;
  }
  if(digitalRead(3) == LOW){
  lcd_1.setCursor(4, 1);
  lcd_1.print("RADIO FM ");
    lcd_1.print(seconds);
  delay(2);
  seconds -= 1;
  }

  }

  
  
}