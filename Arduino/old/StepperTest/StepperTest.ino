/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(60);  // 60 rpm = 1 rps 
  pinMode (LED_BUILTIN, OUTPUT); 
}

void loop() {
//  Serial.println("Single coil steps");
//  myMotor->step(100, FORWARD, SINGLE); 
//  myMotor->step(100, BACKWARD, SINGLE); 
//
//  Serial.println("Double coil steps");
//  myMotor->step(100, FORWARD, DOUBLE); 
//  myMotor->step(100, BACKWARD, DOUBLE);
//  
//  Serial.println("Interleave coil steps");
//  myMotor->step(100, FORWARD, INTERLEAVE); 
//  myMotor->step(100, BACKWARD, INTERLEAVE); 
//  
//  Serial.println("Microstep steps");
//  myMotor->step(50, FORWARD, MICROSTEP); 
//  myMotor->step(50, BACKWARD, MICROSTEP);

  Serial.println("forward");
  myMotor->step(100, FORWARD, DOUBLE); 
  myMotor->release();

  Serial.println("delay 2s");
   delayMicroseconds(1000000);

  
  Serial.println("backward");
  digitalWrite(LED_BUILTIN, HIGH);
  myMotor->step(100, BACKWARD, DOUBLE); 
  myMotor->release();

  Serial.println("delay 5s");
  digitalWrite(LED_BUILTIN, LOW);
  delayMicroseconds(1000000);
}
