#include "main.h"
#include "autons.h"

//Driver control features:
	//Change speed of chassis
	//look into smoother controls
	//
//Auton features
	//fulfill auton goal
	//score multiple points with actual auton
	//PID


int autonMode = 0;


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
		autonMode++;
		if (autonMode == 5)
		{
			autonMode = 0;
		}
		switch (autonMode)
		{
		case 0:
			pros::lcd::set_text(2, "Current Auton: Blue Offense");
			break;
		case 1:
			pros::lcd::set_text(2, "Current Auton: Red Offense");
			break;
		case 2:
			pros::lcd::set_text(2, "Current Auton: Blue Defense");
			break;
		case 3:
			pros::lcd::set_text(2, "Current Auton: Red Offense");
			break;
		case 4:
			pros::lcd::set_text(2, "Current Auton: Auton Skills");
			break;
		default:
			break;
		}
	} 
	else {
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
	pros::lcd::set_text(1, "strokama!");


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
void competition_initialize() 
{
		pros::lcd::initialize();
	pros::lcd::set_text(1, "Init Auton!");


	pros::lcd::register_btn1_cb(on_center_button);
}

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
	if (autonMode == 0)
	{
		Auton1();
	}
	else if (autonMode == 1)
	{
		Auton2();
	}
	else if (autonMode == 2)
	{
		Auton3();
	}
	else if (autonMode == 3)
	{
		Auton4();
	}
	else if (autonMode == 4)
	{
		AutonSkills();
	}
	

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
	pros::Motor left_mtr(9);
	pros::Motor right_mtr(8);
	pros::Motor left_mtr2(6);
	pros::Motor right_mtr2(7);

	pros::Motor lift_mtr(20);

	pros::Motor cata_mtr(10);

	pros::ADIDigitalOut piston('A');
	bool pistonState = false;
	float speedmod = 1;
	piston.set_value(pistonState);
	pistonState = !pistonState;

	while (true) {
				pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);



		int side = pow((master.get_analog(ANALOG_RIGHT_X)),1);
    	int forward = pow((master.get_analog(ANALOG_LEFT_Y)),1);
		int left = (forward - side) * speedmod;
		int right = (-forward - side) * speedmod;
		left_mtr.move(right); 
		right_mtr.move(left);
		left_mtr2.move(left);
		right_mtr2.move(right); //once again, need to retune the basic motor stuff
				
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			cata_mtr.move(-100);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			cata_mtr.move(100);
		}
		else
		{
			cata_mtr.move(0);
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
		{
			piston.set_value(pistonState);
			pistonState = !pistonState;
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			lift_mtr.move(100);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			lift_mtr.move(-100);
		}
		else
		{
			lift_mtr.move(0);
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
		{
			if(speedmod == 1)
			{
				speedmod = 0.5;
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
		{
			if(speedmod == 0.5)
			{
				speedmod = 1;
			}
		}


		pros::delay(20); 
	}
}