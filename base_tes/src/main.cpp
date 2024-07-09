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


// Robot configuration code.
motor front_left = motor(PORT1, ratio6_1, false);

motor mid_left = motor(PORT2, ratio6_1, false);

motor back_left = motor(PORT11, ratio6_1, false);

motor front_right = motor(PORT3, ratio6_1, false);

motor mid_right = motor(PORT4, ratio6_1, false);

motor back_right = motor(PORT20, ratio6_1, false);

controller Controller1 = controller(primary);



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
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int main() {
  //front_left.spin(forward);
  //mid_left.spin(forward);
  //back_left.spin(forward);
  //front_right.spin(forward);
  //mid_right.spin(forward);
 //back_right.spin(forward);
 const int wheelTravel = 320;
const int trackWidth = 320;
const int wheelBase = 130;
motor_group driveL(front_left, mid_left, back_left);
motor_group driveR(front_right, mid_left, back_right);
//drivetrain myDrivetrain(driveL, driveR, wheelTravel, trackWidth, wheelBase, mm);
while (true) {
  driveL.setVelocity(Controller1.Axis3.position(),percent);
  driveR.setVelocity(Controller1.Axis2.position(),percent);
  
}



}
