#include <OneWire.h>
#include <DallasTemperature.h>

OneWire primero(2);
DallasTemperature sensor1(&primero);

DeviceAddress dir1 = {0x28, 0x61, 0x64, 0x35, 0xC6, 0x1, 0xC1, 0xFF};
DeviceAddress dir2 = {0x28, 0x61, 0x64, 0x35, 0xC6, 0x0, 0xF2, 0x67};
DeviceAddress dir3 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x4F, 0x35, 0xD7};
DeviceAddress dir4 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x5D, 0x2C, 0xAB};
DeviceAddress dir5 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x4B, 0xDD, 0xC7};
DeviceAddress dir6 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x41, 0xD3, 0x3F};
DeviceAddress dir7 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x68, 0x3F, 0x6};
DeviceAddress dir8 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x44, 0x88, 0x3B};
DeviceAddress dir9 = {0x28, 0x61, 0x64, 0x35, 0xC1, 0x4C, 0x93, 0xF0};
DeviceAddress dir10 = {0x28, 0x61, 0x64, 0x35, 0xC7, 0x76, 0x97, 0x8A};

float temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
float err1, err2, err3, err4, err5, err6, err7, err8, err9, err10, prom;

void setup() {
  Serial.begin(9600);
  sensor1.begin();

  while(millis()<500){
    sensor1.requestTemperatures();
    temp1= sensor1.getTempC(dir1);
    temp2= sensor1.getTempC(dir2);
    temp3= sensor1.getTempC(dir3);
    temp4= sensor1.getTempC(dir4);
    temp5= sensor1.getTempC(dir5);
    temp6= sensor1.getTempC(dir6);
    temp7= sensor1.getTempC(dir7);
    temp8= sensor1.getTempC(dir8);
    temp9= sensor1.getTempC(dir9);
    temp10= sensor1.getTempC(dir10);
  }
  prom = (temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7 + temp8 + temp9 + temp10)/10;
  err1 = prom-temp1;
  err2 = prom-temp2;
  err3 = prom-temp3;
  err4 = prom-temp4;
  err5 = prom-temp5;
  err6 = prom-temp6;
  err7 = prom-temp7;
  err8 = prom-temp8;
  err9 = prom-temp9;
  err10 = prom-temp10;
}

void loop() {
  sensor1.requestTemperatures();
  Serial.print(sensor1.getTempC(dir1)+err1);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir2)+err2);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir3)+err3);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir4)+err4);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir5)+err5);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir6)+err6);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir7)+err7);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir8)+err8);
  Serial.print(", ");
  Serial.print(sensor1.getTempC(dir9)+err9);
  Serial.print(", ");
  Serial.println(sensor1.getTempC(dir10)+err10);
}
