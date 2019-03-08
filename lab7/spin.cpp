#include <Zumo32U4.h>
Zumo32U4Motors motors;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
//int LEFTSPEED = 200;
//int RIGHTSPEED = 200;
//int Speed = 200;
//int MOVE_DURATION= 1000;
  // put your main code here, to run repeatedly:
 motors.setSpeeds(100, -100);
 delay(1000);
 motors.setSpeeds(0, 0);



 motors.setSpeeds(-100, 100);
 delay(1000);
 motors.setSpeeds(0,0);
}
