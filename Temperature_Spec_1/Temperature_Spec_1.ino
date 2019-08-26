#include<OneWire.h>

OneWire ds(2);

  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Temp;
  //int period=1000;
  unsigned long time_now=millis();

  if (!ds.search(addr)) {
    ds.reset_search();
    return;
  }
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end
  delay(2000);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad
  unsigned long last_time=millis();

  for (i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }

  Temp=(data[1]<<8)+data[0];
  Temp=Temp/16;
  
  // Celsius
   Serial.print("\n");
  Serial.print(" C =");
  Serial.print(Temp);
  Serial.print(", ");

  last_time=last_time-time_now;
  Serial.print("Time =");
 Serial.print(last_time);


 
/*
  // Convert "Celsius" to "Fahrenheit"
  Temp=Temp*1.8+32;

  // Celsius
  Serial.print("F=");
  Serial.print(Temp);
  Serial.println(" ");  
  
  */
}
