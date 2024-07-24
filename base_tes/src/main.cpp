#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS

digital_out pneumatic = digital_out(Brain.ThreeWirePort.H);
// Robot configuration code.
motor front_left = motor(PORT10, ratio6_1, true);

motor mid_left = motor(PORT2, ratio6_1, true);

motor back_left = motor(PORT11, ratio6_1, true);

motor front_right = motor(PORT3, ratio6_1, false);

motor mid_right = motor(PORT5, ratio6_1, false);

motor back_right = motor(PORT20, ratio6_1, false);

controller Controller1 = controller(primary);

motor intake = motor(PORT7, ratio18_1, true);
motor pull = motor(PORT8, ratio6_1, false);

// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Jacob Juneau                                              */
/*    Created:      07/24/24                                                  */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
 void intakeon(){
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
  Brain.Screen.print("down");
}
void pneumatics_up(){
  pneumatic.set(false);
  Brain.Screen.print("up");
}
int main() {
const int wheelTravel = 320;
const int trackWidth = 320;
const int wheelBase = 130;
motor_group driveL(front_left, mid_left, back_left);
motor_group driveR(front_right, mid_right, back_right);
drivetrain myDrivetrain(driveL, driveR, wheelTravel, trackWidth, wheelBase, mm);
while (true) {
  Controller1.ButtonL1.pressed(pneumatics_down);
  Controller1.ButtonR1.pressed(pneumatics_up);
  Controller1.ButtonA.pressed(intakeon);
  Controller1.ButtonB.pressed(intakeoff);
  if (Controller1.ButtonX.pressing()){
    pull.setVelocity(200, rpm);
    pull.spin(forward);
  } else {pull.stop();}

  driveL.setVelocity(Controller1.Axis3.position(),percent);

  driveR.setVelocity(Controller1.Axis2.position(),percent);
  driveR.spin(forward);
  driveL.spin(forward);
  
}



}
