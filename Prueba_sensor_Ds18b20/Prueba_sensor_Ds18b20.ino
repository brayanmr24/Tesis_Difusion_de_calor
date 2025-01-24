#include <OneWire.h>
#include <DallasTemperature.h>

OneWire primero(2);
DallasTemperature sensor1(&primero);
float temperatura;

void setup() {
  Serial.begin(9600);
  sensor1.begin();
}

void loop() {
  sensor1.requestTemperatures();
  temperatura = sensor1.getTempCByIndex(0);
  Serial.print("Temperatura 1: ");
  Serial.println(temperatura);
  delay(500);
}
