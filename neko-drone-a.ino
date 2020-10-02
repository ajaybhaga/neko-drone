/*
 * Flight controller code for Neko Drone A
 * 
 * By Ajay Bhaga
 */

/* Get all possible data from MPU6050
 * Accelerometer values are given as multiple of the gravity [1g = 9.81 m/s²]
 * Gyro values are given in deg/s
 * Angles are given in degrees
 * Note that X and Y are tilt angles and not pitch/roll.
 *
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>
#include <Servo.h>


Servo escA;     // create servo object to control the ESC (~3)
Servo escB;     // create servo object to control the ESC (~5)
Servo escC;     // create servo object to control the ESC (~6)
Servo escD;     // create servo object to control the ESC (~9)

MPU6050 mpu(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();

// (pin, min pulse width, max pulse width in microseconds)
  escA.attach(3,4000,8000);  // attaches the servo on pin 3 to the servo object
  escB.attach(5,4000,8000);  // attaches the servo on pin 5 to the servo object
  escC.attach(6,4000,8000);  // attaches the servo on pin 6 to the servo object
  escD.attach(9,4000,8000);  // attaches the servo on pin 9 to the servo object
  Serial.println(F("Welcome to Neko Drone A Flight Controller"));


  
  Serial.println(F("Calculating gyro offset, do not move MPU6050"));
  delay(1000);
  mpu.calcGyroOffsets();
  Serial.println("Done!\n");
  
}

int val = 64;
void loop() {
  mpu.update();

    //val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

// escA - Bottom-Left
// escB - Top-Left

// escC - Bottom-Right
// escD - Top-Right
/*    escD.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escD.write(0);                  // sets the servo position according to the scaled value
    delay(100);
*/
/*  
    escA.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escA.write(0);                  // sets the servo position according to the scaled value
    delay(100);

    escB.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escB.write(0);                  // sets the servo position according to the scaled value
    delay(100);
    
    escC.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escC.write(0);                  // sets the servo position according to the scaled value
    delay(100);
 
    escD.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escD.write(0);                  // sets the servo position according to the scaled value
    delay(100);

  
*/
     
    //escA.write(val);                  // sets the servo position according to the scaled value
    //escB.write(val);                  // sets the servo position according to the scaled value
    escC.write(val);                  // sets the servo position according to the scaled value
    escD.write(val);                  // sets the servo position according to the scaled value
    delay(1000);
    escA.write(0);                  // sets the servo position according to the scaled value
    escB.write(0);                  // sets the servo position according to the scaled value
    escC.write(0);                  // sets the servo position according to the scaled value
    escD.write(0);                  // sets the servo position according to the scaled value
    delay(100);

 
   // servoB.write(val);                  // sets the servo position according to the scaled value
  //  servoC.write(val);                  // sets the servo position according to the scaled value
 //   servoD.write(val);                  // sets the servo position according to the scaled value


  if(millis() - timer > 1000){ // print data every second
    Serial.print(F("TEMPERATURE  : "));Serial.println(mpu.getTemp());
    Serial.print(F("ACCELERO   X : "));Serial.print(mpu.getAccX());
    Serial.print("\tY : ");Serial.print(mpu.getAccY());
    Serial.print("\tZ : ");Serial.println(mpu.getAccZ());
  
    Serial.print(F("GYRO       X : "));Serial.print(mpu.getGyroX());
    Serial.print("\tY : ");Serial.print(mpu.getGyroY());
    Serial.print("\tZ : ");Serial.println(mpu.getGyroZ());
  
    Serial.print(F("ACC ANGLE  X : "));Serial.print(mpu.getAccAngleX());
    Serial.print("\tY : ");Serial.println(mpu.getAccAngleY());
    
    Serial.print(F("ANGLE      X : "));Serial.print(mpu.getAngleX());
    Serial.print("\tY : ");Serial.print(mpu.getAngleY());
    Serial.print("\tZ : ");Serial.println(mpu.getAngleZ());
    Serial.println(F("=======================================================\n"));
    timer = millis();
  }

}
