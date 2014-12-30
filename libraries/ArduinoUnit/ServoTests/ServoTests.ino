#include <Servo.h>
#include <ArduinoUnit.h>
#include "ServoConstants.h"
//          C:\srcArduino\ArduinoBot\libraries\ArduinoUnit\ServoTests\ServoTests.ino
//#include "C:\srcArduino\ArduinoBot\oddWiresRoboticsKit_MotorShield\ServoConstants.h"
using namespace ServoControl;

void loop()
{
  Test::run();
}

void setup()
{
  Serial.begin(9600);   
}

test(CanAttachServo)
{
  Heading servoHeading;
  assertTrue(servoHeading.IsValid());
}

test(ReadingReturnsNegativeOneWhenHeadingInvalid)
{
  Heading servoHeading;
  servoHeading.Invalidate();
  assertEqual(servoHeading.GetServoHeading(), -1);
}

test(CanCreateMultipleValidHeadings)
{
  Heading servoHeading;
  Heading servoHeading2;
  assertTrue(servoHeading.IsValid());
  assertTrue(servoHeading2.IsValid());
}

test(MultipleServoInstancesOnSamePinDoNotInvalidateEachOther)
{
  Heading servoHeading;
  Heading servoHeading2;
  
  assertTrue(servoHeading.IsValid());
  assertTrue(servoHeading2.IsValid());
  
  servoHeading.Invalidate();    
  
  assertFalse(servoHeading.IsValid());
  assertTrue(servoHeading2.IsValid());
}

test(CanSetHeadingFarRight)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(180, 500);
  assertEqual(servoHeading.GetServoHeading(), 180);
}

test(CanYouSwivelLeftAndRight)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(0);
  servoHeading.SetServoHeading(90);
  servoHeading.SetServoHeading(180);
  servoHeading.SetServoHeading(90);
  assertEqual(servoHeading.GetServoHeading(), 90);
}

test(CanSetHeadingStraight)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(90);  
  assertEqual(servoHeading.GetServoHeading(), 90);
}

test(CanSetHeadingSlightLeft)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(80);
  assertEqual(servoHeading.GetServoHeading(), 80);
}

test(CanSetHeadingSlightRight)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(100);
  assertEqual(servoHeading.GetServoHeading(), 100);
}

test(CanSetHeadingFarLeft)
{
  Heading servoHeading;
  servoHeading.SetServoHeading(0);
  assertEqual(servoHeading.GetServoHeading(), 0);
}

