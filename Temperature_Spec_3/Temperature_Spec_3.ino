#include <OneWire.h>  
#include <DallasTemperature.h>

OneWire oneWire(2);
DallasTemperature sensors(&oneWire);
DeviceAddress tempSensor = {0x28, 0x8C, 0x43, 0x40, 0x0B, 0x00, 0x00, 0x0F};

float Temp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.setResolution(tempSensor, 12);
  Serial.print("Sensor Resolution : ");
  Serial.print(sensors.getResolution(tempSensor), DEC);
  Serial.println();
  
  sensors.requestTemperaturesByAddress(tempSensor);
  Temp = sensors.getTempC(tempSensor);
  
  Serial.print("Temp C: ");
  Serial.println(Temp, 5);
  delay(500);
  Serial.println();
}
