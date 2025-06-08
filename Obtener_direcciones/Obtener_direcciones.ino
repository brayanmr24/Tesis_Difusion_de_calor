#include <OneWire.h>
const int oneWireBus = 21;
int i;
byte direcciones[8];

OneWire primero(oneWireBus);

void setup(void) {
  Serial.begin(19200);
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