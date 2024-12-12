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
limit  intake_sense1 = limit(Brain.ThreeWirePort.C);
limit  intake_sense2 = limit(Brain.ThreeWirePort.E);
limit pull_sense = limit(Brain.ThreeWirePort.B);
line pull_sense2 = line(Brain.ThreeWirePort.F);
motor front_left = motor(PORT10, ratio6_1, true);

motor mid_left = motor(PORT2, ratio6_1, true);

motor back_left = motor(PORT11, ratio6_1, true);

motor front_right = motor(PORT3, ratio6_1, false);

motor mid_right = motor(PORT5, ratio6_1, false);

motor back_right = motor(PORT20, ratio6_1, false);

controller Controller1 = controller(primary);

motor intake = motor(PORT17, ratio18_1, true);

motor pull_left = motor(PORT7, ratio36_1, false);


motor_group LeftDriveSmart = motor_group(front_left, mid_left, back_left);
motor_group RightDriveSmart = motor_group(front_right, mid_right, back_right);
inertial DrivetrainInertial = inertial(PORT13);
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
  intake.setVelocity(180, percent);
  intake.spin(forward);
 } 


void intakeoff(){
  intake.setVelocity(0, percent);
}


void up(){
  pull_left.setVelocity(30, percent);
  pull_left.spin(forward);
  waitUntil (pull_sense);{ 
    pull_left.setVelocity(100, percent);
  }
 /* waitUntil (pull_sense2);{
    pull_left.setVelocity(0,percent);
  }*/
}


void down(){
  pull_left.stop();
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
 calibrateDrivetrain()
const int wheelBase = 89;*/
//drivetrain myDrivetrain(driveL, driveR, wheelTravel, gyro1, trackWidth, wheelBase, mm);
 /*calibrateDrivetrain();
Drivetrain.setDriveVelocity(50, percent);
Drivetrain.setTurnVelocity(15, percent);
Drivetrain.setStopping(hold);
Drivetrain.setHeading(0, degrees);
Drivetrain.driveFor(forward, 200, mm);
//Drivetrain.turnFor(90,degrees);
//intakeon();
//pull.spin(forward);
//wait(20, seconds);
//Drivetrain.turnFor(-90, degrees);
//Drivetrain.driveFor(reverse, 280, mm);
Drivetrain.setHeading(0, degrees);
Drivetrain.turnToHeading(90, degrees);
wait(5, seconds);
Drivetrain.turnToHeading(0, degrees);
Drivetrain.driveFor(reverse, 200, mm);-
//intakeon();
//pull.setVelocity(80, rpm);
//pull.spin(forward
*/
/*intakeon();
wait(1, seconds);
Brain.Screen.print("ready");
while (true) {
  if (intake_sense1 or intake_sense2) {
    wait(0.5, seconds);
  intakeoff();
  up();
  intakeon();
} }*/
  while(true) {
    // Clear the screen and set the cursor to top left corner on each loop
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("Reflectivity: %d", pull_sense2.reflectivity(percent));
    Brain.Screen.newLine();

    // A brief delay to allow text to be printed without distortion or tearing
    wait(20, msec);
  }

}