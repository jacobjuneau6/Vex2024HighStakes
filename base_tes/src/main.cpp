#pragma region VEXcode Generated Robot Configuration

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "vex.h"
using namespace vex;
brain Brain;
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)



//port setup
digital_out pneumatic_sys = digital_out(Brain.ThreeWirePort.H);                  /*  pneumatics are connected to 3-wire port H  */
motor front_left_motor = motor(PORT10, ratio6_1, true);                          /*  front left motor connected to port 10      */
motor mid_left_motor = motor(PORT2, ratio6_1, true);                             /*  middle left motor connected to port 2      */
motor back_left_motor = motor(PORT11, ratio6_1, true);                           /*  back left motor connected to port 11       */
motor front_right_motor = motor(PORT3, ratio6_1, false);                         /*  front right motor connected to port 3      */
motor mid_right_motor = motor(PORT5, ratio6_1, false);                           /*  middle right motor connected to port 5     */
motor back_right_motor = motor(PORT20, ratio6_1, false);                         /*  back right motor connected to port 20      */
controller Controller1 = controller(primary);                                    /*  controller radio connected to port 21      */
motor intake = motor(PORT7, ratio18_1, true);                                    /*  intake motor connected to port 7           */
motor move = motor(PORT8, ratio6_1, false);                                      /*  donut pulling motor connected to port 8    */



void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Jacob Juneau                                              */
/*    Created:      07/24/24                                                  */
/*    Description:  Driving code for 3050Z                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
void up(){
  move.spin(forward);
}

 void intake_on(){
  intake.setVelocity(200, percent);
  intake.spin(forward);
 } 

void intake_off(){
  intake.setVelocity(0, percent);
}

void move_donut_up(){
  move.spin(forward);
}

void down(){
  move.stop();
}

using namespace vex;

void pneumatics_down(){
  pneumatic_sys.set(true);
}

void pneumatics_up(){
  pneumatic_sys.set(false);
}

int main() {
motor_group driveL(front_left_motor, mid_left_motor, back_left_motor);

motor_group driveR(front_right_motor, mid_right_motor, back_right_motor);

while (true) {

  Controller1.ButtonL1.pressed(pneumatics_down);

  Controller1.ButtonR1.pressed(pneumatics_up);

  Controller1.ButtonLeft.pressed(up);

  //Controller1.ButtonA.pressed(intake_on);
  //Controller1.ButtonUp.pressed(intake_on);

  Controller1.ButtonB.pressed(intake_off);

  if (Controller1.ButtonUp.pressing()){
    Brain.Screen.print("up pressed");
  }
   // Brain.Screen.print('up pressed');
    //move.setVelocity(200, rpm); //200rpm is best for reliability
   // move.spin(forward); //make the motor spin
  

  if (Controller1.ButtonDown.pressing()){
    move.setVelocity(200, rpm); //200rpm is best for reliability
    move.spin(reverse); //make the motor spin
  } 

  else {
    move.stop();
  }
  driveL.setVelocity(Controller1.Axis3.position(),percent);
  driveR.setVelocity(Controller1.Axis2.position(),percent);
  driveR.spin(forward);
  driveL.spin(forward);
}
}
