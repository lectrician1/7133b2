#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
/*
tray_control(void*) {
	pros::Controller master(CONTROLLER_MASTER);
	pros::Task tray_t(tray_pid);
	bool b_toggle = false;
	while (true) {
		if (master.get_digital(DIGITAL_Y)) {
			b_toggle = !b_toggle;

			if (b_toggle) {
				for(int i=0;i<1700;i=i+3) {
					set_tray_pid(i);
					pros::delay(5);
				}
			} else {
				set_tray_pid(0);
			}

			while (master.get_digital(DIGITAL_Y)) {
				pros::delay(1);
			}
		}

		pros::delay(20);
	}
}
*/
//Make the right paddle a shift key, making everything into a descore position.
/*
void
arm_control(void*) {
	pros::Controller master(CONTROLLER_MASTER);
	pros::Task arm_t(arm_pid);
	static int HIGH_POLE = 2450, LOW_POLE = 1000, DOWN = 0;
	int b_toggle = DOWN;
	while (true) {
		if (master.get_digital(DIGITAL_R1)) {
			if (b_toggle == DOWN || b_toggle == LOW_POLE) {
				b_toggle = HIGH_POLE;
			} else {
				b_toggle = DOWN;
			}
			set_arm_pid(b_toggle);
			while (master.get_digital(DIGITAL_R1)) {
				pros::delay(1);
			}
		}
		if (master.get_digital(DIGITAL_R2)) {
			if (b_toggle == DOWN || b_toggle == HIGH_POLE) {
				b_toggle = LOW_POLE;
			} else {
				b_toggle = DOWN;
			}
			set_arm_pid(b_toggle);
			while (master.get_digital(DIGITAL_R2)) {
				pros::delay(1);
			}
		}
		pros::delay(20);
	}
}
*/

//void
//roller_control(void*) {
//pros::Controller master(CONTROLLER_MASTER);
//	pros::Task rollers_t(roller_pid);
//	bool was_pid;
//___int_least16_t_defined	while (true) {
//		if (master.get_digital(DIGITAL_L2)){
//			set_
//		}
//
//		if (!was_pid) {
//				arm_t.suspend();

/* code */
void opcontrol()
{
	auto chassis = ChassisControllerBuilder()
					   .withMotors(-1, 2, -12, 11)
					   .withDimensions(AbstractMotor::gearset::green, {{4_in, 6.5_in}, imev5GreenTPR})
					   .build();

	auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
	Controller controller(ControllerId::master);

	ControllerButton IntakeIn(ControllerDigital::L2);
	ControllerButton IntakeOut(ControllerDigital::L1);
	ControllerButton Allroller(ControllerDigital::R2);
	while (true)
	{
		xModel->xArcade(
			controller.getAnalog(ControllerAnalog::rightX),
			controller.getAnalog(ControllerAnalog::leftY),
			controller.getAnalog(ControllerAnalog::leftX));
	}
}
/*  if (IntakeIn.changedToPressed()){
      set_intake(127);
      set_lower_roller(127);
      }
    else if (IntakeOut.changedToPressed()) {
      set_intake(-127);
      set_lower_roller(-127);
      }
    else {
      set_intake(0);
      set_lower_roller(0);}

    if (Allroller.changedToPressed()) {
      set_lower_roller(127);
      set_upper_roller(127);
    }
   }
   pros::delay(20);
  }



		//set_arm((master.get_digital(DIGITAL_R1)-master.get_digital(DIGITAL_R2))*127);

	/*
		if (master.get_digital(DIGITAL_L1)) {
			set_rollers(127);
		} else if (master.get_digital(DIGITAL_L2)) {
			set_rollers(-127);
		} else if (master.get_digital(DIGITAL_RIGHT)) {
			set_rollers(60);
		} else {
			set_rollers(0);
		}

		pros::delay(20);
	}
}
*/
