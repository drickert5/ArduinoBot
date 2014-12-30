#ifndef Constants_Header
#define Constants_Header

namespace ServoControl
{
	const int DIRECTION_STRAIGHT = 90;
	
      	class Heading
	{
	public:
          Heading()
          {
            servo.attach(10);//,650,1075);
            while(!servo.attached())
            {
               delay(5);
               Serial.print("Delaying not yet attached\n"); 
            }
//            Serial.print("Heading created\n");
          }
          
          ~Heading()
          {
            Invalidate();
            while(servo.attached())
            {
               delay(5);
               Serial.print("Delaying not yet detached\n"); 
            }
//            Serial.print("Heading destroyed\n");
          }
                    
          bool IsValid()
          {
             return servo.attached();
          }
          
          void Invalidate()
          {
            servo.detach();
          }
          
          int GetServoHeading()
          {
            if(!IsValid())
              return -1;
              
            return servo.read();
          }
          
          void SetServoHeading(int heading, int lengthDelay=0)
          {
            int movementDelay =  abs(GetServoHeading() - heading) * 4;
            servo.write(heading);
            
            int myDelay = 0 == lengthDelay ? movementDelay : lengthDelay;
            delay(myDelay);
          }
          
          
          Servo servo;
	};

}
#endif
