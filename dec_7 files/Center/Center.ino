#include <SoftwareSerial.h>
SoftwareSerial s(2,3);
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
  Wire.onReceive(ReceiveEvent);
  Wire.onRequest(RequestEvent);
  s.begin(115200);
  Serial.begin(921600);
}
void RequestEvent()
{
  if(Serial.available())
  {
    Wire.write(1);
    Wire.write(Serial.read());
    Serial.print("tes");
  }
}
void ReceiveEvent()
{
  while(Wire.available())
  {
    Serial.write(Wire.read());
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  /*
  while(s.available())
  {
    uint8_t temp = s.read();
    Serial.println(temp);
  }
  */
}
