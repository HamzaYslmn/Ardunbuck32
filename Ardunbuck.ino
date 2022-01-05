#include <PWM.h>

double channel;
int PWM_PIN = 3;
int pwmval = 0;
int32_t frequency = 1200;

void setup() {

  pinMode(2,INPUT);
  
  InitTimersSafe();
  
  bool success = SetPinFrequencySafe(PWM_PIN, frequency);
  
  Serial.begin(9600);
  pinMode(PWM_PIN,OUTPUT);
}

void loop() {
     channel = pulseIn(2,HIGH);
     analogWrite(PWM_PIN,  channel);
     Serial.println(PWM_PIN);
  }
