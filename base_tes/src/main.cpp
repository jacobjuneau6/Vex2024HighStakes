//#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
//#include "drive.h"

#include "vex.h"

using namespace vex;

brain Brain;



#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)


digital_out pneumatic = digital_out(Brain.ThreeWirePort.H);


motor front_left = motor(PORT10, ratio6_1, true);

motor mid_left = motor(PORT2, ratio6_1, true);

motor back_left = motor(PORT11, ratio6_1, true);

motor front_right = motor(PORT3, ratio6_1, false);

motor mid_right = motor(PORT5, ratio6_1, false);

motor back_right = motor(PORT20, ratio6_1, false);

controller Controller1 = controller(primary);

controller Controller2 = controller(partner);
motor intake = motor(PORT9, ratio18_1, true);

motor pull_left = motor(PORT7, ratio36_1, true);
//motor pull_right = motor(PORT14, ratio36_1, false); depracted we switched back to one motor
motor_group pull = motor_group(pull_left);// i downt feel like fixing this just leave it


void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
//#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Jacob Juneau                                              */
/*    Created:      07/24/24                                                  */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library

 void intakeon(){
  //Brain.Screen.print('on');
  intake.setVelocity(200, percent);
  intake.spin(forward);
 } 


void intakeoff(){
  intake.setVelocity(0, percent);
}


void up(){
  pull.spin(forward);
}


void down(){
  pull.stop();
}
// Allows for easier use of the VEX Library
using namespace vex;

void pneumatics_down(){
  pneumatic.set(true);
 // Brain.Screen.print("down");
}


void pneumatics_up(){
  pneumatic.set(false);
  //Brain.Screen.print("up");
}


int main() {

motor_group driveL(front_left, mid_left, back_left);
motor_group driveR(front_right, mid_right, back_right);
Controller1.Screen.print("DRIVE & GOAL");
Controller2.Screen.print("INTAKE & SCORING");
Controller1.rumble("------------------------");
Controller2.rumble("------------------------");
while (true) {
  //check controller buttons and do actions based on them
  Controller1.ButtonL1.pressed(pneumatics_down);

  Controller1.ButtonR1.pressed(pneumatics_up);

  Controller2.ButtonA.pressed(intakeon);

  Controller2.ButtonB.pressed(intakeoff);

  if (Controller2.ButtonX.pressing()){
    pull.setVelocity(800, rpm);
   // pull.setVelocity(100,percent);
    pull.spin(forward);
  } else if (Controller2.ButtonY.pressing()) {
    pull.spin(reverse);
    }
    else {pull.stop();}
//get thumbstick 

  driveL.setVelocity(Controller1.Axis3.position(),percent);

  driveR.setVelocity(Controller1.Axis2.position(),percent);
//spin the motors using that position 
  driveR.spin(forward);

  driveL.spin(forward);
  
}

}
