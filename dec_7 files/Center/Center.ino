#include <SoftwareSerial.h>
SoftwareSerial s(2,3);
#include <Wire.h>

//stepper motor
#include <Stepper.h>
const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
// for your motor

//set up motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 7, 9,8, 10);
int startLocation = 1;
int CW = 0;
int CCW = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
  Wire.onReceive(ReceiveEvent);
  Wire.onRequest(RequestEvent);
  s.begin(115200);
  Serial.begin(921600);

  //set up motor speed
  myStepper.setSpeed(20);
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

void motorCW()
{
    // step one revolution  in one direction:
    Serial.println("clockwise");
    CW = (stepsPerRevolution);
    myStepper.step(CW);
    delay(1000);
    Serial.println("at location A");

}

void motorCCW()
{
  // step one revolution  in the other direction:
    Serial.println("counterclockwise");
    CCW = (-stepsPerRevolution);
    myStepper.step(CCW);
    delay(1000);
    Serial.println("at location B");
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
