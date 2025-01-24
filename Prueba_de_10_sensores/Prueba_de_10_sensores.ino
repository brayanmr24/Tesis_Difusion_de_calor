#include <OneWire.h>
#include <DallasTemperature.h>

OneWire primero(2);
DallasTemperature sensor1(&primero);

DeviceAddress dir1 = {0x28, 0x62, 0xBB, 0x5F, 0x0, 0x0, 0x0, 0xCE};
DeviceAddress dir2 = {0x28, 0x46, 0x34, 0x5E, 0x0, 0x0, 0x0, 0x8F};
DeviceAddress dir3 = {0x28, 0x6A, 0x5, 0x5E, 0x0, 0x0, 0x0, 0xD};
DeviceAddress dir4 = {0x28, 0xEB, 0x8F, 0x5E, 0x0, 0x0, 0x0, 0xA6};
DeviceAddress dir5 = {0x28, 0x6F, 0xAC, 0x5F, 0x0, 0x0, 0x0, 0xA9};
DeviceAddress dir6 = {0x28, 0x41, 0x8, 0x5F, 0x0, 0x0, 0x0, 0x20};
DeviceAddress dir7 = {0x28, 0x5C, 0x6E, 0x5E, 0x0, 0x0, 0x0, 0x33};
DeviceAddress dir8 = {0x28, 0x3C, 0x8, 0x5F, 0x0, 0x0, 0x0, 0xF2};
DeviceAddress dir9 = {0x28, 0x63, 0xAA, 0x5F, 0x0, 0x0, 0x0, 0x48};
DeviceAddress dir10 = {0x28, 0xA, 0x8A, 0x5F, 0x0, 0x0, 0x0, 0xE5};

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
