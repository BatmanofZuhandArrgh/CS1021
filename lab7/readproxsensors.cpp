#include <Zumo32U4.h>


Zumo32U4ProximitySensors proxSensors;
Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;






void setup() {
 proxSensors.initThreeSensors(); 
 Serial.begin(115200);
 
}

void loop() {
//int LEFTSPEED = 200;
//int RIGHTSPEED = 200;
//int Speed = 200;
//int MOVE_DURATION= 1000;
  // put your main code here, to run repeatedly:

   //Run the course
 //buttonA.waitForButton(); // Wait indefinitely for the user to press the A button
 //seekLine(); // Stop at line

 int rightprox = proxSensors.countsFrontWithRightLeds();
 int leftprox = proxSensors.countsFrontWithLeftLeds();
 
proxSensors.read(); // Updates proximity sensor buffer
 Serial.println(proxSensors.countsFrontWithRightLeds());
 Serial.println(proxSensors.countsFrontWithLeftLeds());

if ((rightprox >= 5)||(leftprox >= 5)){

  motors.setSpeeds(100, 100);
 }
 else{
motors.setSpeeds(0, 0);
  
 }
 
}
