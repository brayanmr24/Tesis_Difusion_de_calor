#include <OneWire.h>
int bus=2;
int i;
byte direcciones[8];

OneWire primero(bus);

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  Serial.println("Direcciones:");
  while (primero.search(direcciones)) {  
    Serial.print("Direccion = ");
    for(i=0; i<8; i++) {
      Serial.print(" 0x");
      Serial.print(direcciones[i], HEX);
    }
    Serial.println();
  }
  primero.reset_search();
  delay(1000);
}