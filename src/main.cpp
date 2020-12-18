#include <Arduino.h>
#include <DHT.h>

int relayPin = 3;                   
int digitalTempPin = 7;
float triggerTemp = 29;

DHT _dht(digitalTempPin, DHT11);

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(115200);
  _dht.begin();
}

void loop() {
   
  float temperature = _dht.readTemperature();
  Serial.print("Temp:");
  Serial.print(temperature);
  Serial.print("\n");
  if(temperature < triggerTemp) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
  delay(5000);
}
