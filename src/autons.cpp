#include "main.h"
#include "autons.h"

//where I'll put all the autons



//3 goals:
    //1. retrieve the match load from your corner -- we can't do this lmao
    //2. score your team triball in your goal
    //3. end the auton by touching the elevation bar

void Auton1()
{
    pros::lcd::set_text(1, "Auton 1 running!");

    pros::Motor left_mtr(11);
    pros::Motor right_mtr(15);
    pros::Motor left_mtr2(13);
    pros::Motor right_mtr2(20);

    pros::Motor cata_mtr(17);
    pros::Motor cata_mtr2(18);

    //turn towards goal 
    left_mtr.move(100); 
	right_mtr.move(100);
    left_mtr2.move(-100);
	right_mtr2.move(-100);
    pros::delay(500);
    //move forwards
    left_mtr.move(100); 
	right_mtr.move(100);
    left_mtr2.move(100);
	right_mtr2.move(100);
    pros::delay(500);
    //turn towards elevation bar
    left_mtr.move(-100); 
	right_mtr.move(-100);
    left_mtr2.move(100);
	right_mtr2.move(100);
    pros::delay(500);
    //move forwards
    left_mtr.move(100); 
	right_mtr.move(100);
    left_mtr2.move(100);
	right_mtr2.move(100);
    pros::delay(500);
    //STOP GORDON
    left_mtr.move(0); 
	right_mtr.move(0);
    left_mtr2.move(0);
	right_mtr2.move(0);
}

void Auton2()
{
    pros::lcd::set_text(1, "Auton 2 running!");
}

void AutoCatapult(int count)
{
    for (int i = 0; i < count; i++)
    {
        //start moving the motors
        //timer function
        //stop moving the motors
        //this should fire the catapult once then stop
    }
}

void AutonSkills()
{
    AutoCatapult(10);
}