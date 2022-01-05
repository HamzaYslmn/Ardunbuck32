#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Blynk";

char ssid[] = "wifiadı";
char pass[] = "şifre";

const int ledPin = 16;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

BLYNK_WRITE(V0)
{
  int dutyCycle = param.asInt();
  ledcWrite(ledChannel, dutyCycle);
}

void setup()
{
  ledcAttachPin(ledPin, ledChannel);
  ledcSetup(ledChannel, freq, resolution);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
