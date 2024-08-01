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

motor intake = motor(PORT17, ratio18_1, true);

motor pull = motor(PORT7, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(front_left, mid_left, back_left);
motor_group RightDriveSmart = motor_group(front_right, mid_right, back_right);
inertial DrivetrainInertial = inertial(PORT19);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 190, 267, 89, mm, 1.33333333333);
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
//bool RemoteControlCodeEnabled = true;

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


bool vexcode_initial_drivetrain_calibration_completed = false;
void calibrateDrivetrain() {
  wait(200, msec);
  Brain.Screen.print("Calibrating");
  Brain.Screen.newLine();
  Brain.Screen.print("Inertial");
  DrivetrainInertial.calibrate();
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  vexcode_initial_drivetrain_calibration_completed = true;
  // Clears the screen and returns the cursor to row 1, column 1.
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
}
 void intakeon(){
 // Brain.Screen.print("on");
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

int main(){
//motor_group driveL(front_left, mid_left, back_left);
//motor_group driveR(front_right, mid_right, back_right);
/*const int wheelTravel = 190;
const int trackWidth = 267;
const int wheelBase = 89;*/
//drivetrain myDrivetrain(driveL, driveR, wheelTravel, gyro1, trackWidth, wheelBase, mm);
//Drivetrain.driveFor(forward, 200, mm);
//Drivetrain.driveFor(reverse, 200, mm);
Drivetrain.turnFor(right, 90, degrees);
}