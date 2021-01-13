#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
Motor left_front(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor left_back (11, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor right_front(2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor right_back(12, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

pros::Motor upper_roller (1, MOTOR_GEARSET_36);
pros::Motor lower_roller (7, MOTOR_GEARSET_18);
pros::Motor left_intake (8, MOTOR_GEARSET_36, true);
pros::Motor right_intake(9, MOTOR_GEARSET_36);



//Math
/*
int
sgn(int input) {
  if (input>0)
    return 1;
  else if (input < 0)
    return -1;
  return 0;
}
int
clipnum(int input, int clip) {
  if (input > clip)
    return clip;
  else if (input < clip)
    return -clip;
  return input;
}
*/


void reset() {
  upper_roller.set_brake_mode(MOTOR_BRAKE_HOLD);
  lower_roller.set_brake_mode(MOTOR_BRAKE_HOLD);
  right_intake.set_brake_mode(MOTOR_BRAKE_HOLD);
  left_intake.set_brake_mode(MOTOR_BRAKE_HOLD);
}

//Set motors
//void
//et_tank(int input_l, int input_r) {

void set_intake(int input) {
  left_intake.move(input);
  right_intake.move(input);
}

void set_lower_roller(int input) {
  lower_roller.move(input);
}

void set_upper_roller(int input) {
  upper_roller.move(input);
}

void set_rollers(int input) {
  upper_roller.move(input);
  lower_roller.move(input);
}
