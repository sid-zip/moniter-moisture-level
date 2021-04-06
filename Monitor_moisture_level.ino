
#define ANA A0
#define DIGI D5
#define POMPOUT D6
#define BLYNK_PRINT Serial //Blynk
#define PIN_UPTIME V1 //Blynk

#include <ESP8266WiFi.h>//Blynk
#include <BlynkSimpleEsp8266.h> //Blynk - You will need to install the Blynk library - See README.md

double analogValue = 0.0;
int digitalValue = 0;
double analogVolts = 0.0;
double sensorData = 0.0;
unsigned long timeHolder = 0;

char auth[] = "YOUR APP ID SENT BY BLYNK GOES HERE"; //Blynk
char ssid[] = "YOUR WIFI SSID"; //Blynk
char pass[] = "YOUR WIFI PASSWORD"; //Blynk

void setup() {

  pinMode(ANA, INPUT);
  pinMode(DIGI, INPUT);
  pinMode(POMPOUT, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass); //Blynk - pass in your Blynk app ID, wifi ssid, and password
}
void loop() {
  analogValue = analogRead(ANA);
  digitalValue = digitalRead(DIGI);
  Blynk.run(); //Blynk 
  Blynk.virtualWrite(V1, analogValue); //Blynk - Pass in the virtual port number (Configured on the Blynk app) and the value to display on the gauge
  
  // Serial data
  Serial.print("Moisture Reading: ");
  Serial.println(analogValue);
  Serial.print("Digital raw: ");
  Serial.println(digitalValue);
  Serial.println(" ");
   
  if (analogValue <= 650) {
    digitalWrite(POMPOUT, false);
  } else {
        Serial.println("PUMPIN");
      digitalWrite(POMPOUT, true);
  }
  delay(500);
}
