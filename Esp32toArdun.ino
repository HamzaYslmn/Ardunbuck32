#define BLYNK_TEMPLATE_ID "TMPLDT1B0WZY"
#define BLYNK_DEVICE_NAME "ESP32"
#define BLYNK_AUTH_TOKEN "ApRjoPbsVcxVnq13bUfReZIlQWlsEnNW"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "ApRjoPbsVcxVnq13bUfReZIlQWlsEnNW";

char ssid[] = "Hamza";
char pass[] = "1234567899";

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
