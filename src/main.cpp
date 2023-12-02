#include "main.h"

//TODO
//---------------------------------------------------------------------
//Auton selector for competition
//Autons in general
//**this will be a lot cleaner looking if we make a couple functions(like catapult stuff) to call during auton
//**additionally we'll want to use a separate file for auton stuff
//**look into sensors for things like odom and whatnot, so we can make our bot track better
//**Grant once again pulls through with a few videos on basic auton
//PID control loop stuff, there's a video on grant's website explaining them
//


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
{




}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//gotta move a lot of this stuff to initialize() function, and also use proper #define for the port numbers
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(3);
	pros::Motor right_mtr(5);
	pros::Motor left_mtr2(6);
	pros::Motor right_mtr2(8);

	//pneumatic pistons out
	pros::ADIDigitalOut piston('A');

	piston.set_value(true);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		pros::lcd::print(0, "Isaac is dead and we have killed him");
		int forward = master.get_analog(ANALOG_LEFT_X);
    	int side = master.get_analog(ANALOG_LEFT_Y);
		int left = forward + side;
		int right = forward - side;
		left_mtr.move(left);
		right_mtr.move(left);
		left_mtr2.move(right);
		right_mtr2.move(right); //once again, need to retune the basic motor stuff
				
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			//When pistons are activated, the catapult should tilt back
			//Deactivating the pistons == the rubber bands snap the catapult into shooting
			piston.set_value(false);
			pros::delay(1000); //fine tune this later
			piston.set_value(true); //I shudder to think what kind of horrors keeping these pistons on for the majority of a match will cause, but I guess we're going to find out
		}


		pros::delay(20);
	}
}