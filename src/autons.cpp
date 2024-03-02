#include "main.h"
#include "autons.h"

//where I'll put all the autons
//TODO:
    //Drivetrain function - check
    //PID
    //2 autons - check?
    //auton skills auton
    //auton picker improvement - uhhhh 


//3 goals:
    //1. retrieve the match load from your corner -- we can't do this lmao
    //2. score your team triball in your goal
    //3. end the auton by touching the elevation bar

    pros::Motor left_mtr(11);
    pros::Motor right_mtr(15);
    pros::Motor left_mtr2(13);
    pros::Motor right_mtr2(20);

    pros::Motor cata_mtr(17);

void AutoCatapult(int count)
{
    for (int i = 0; i < count; i++)
    {
        cata_mtr.move(-100);
        pros::delay(1250);
        cata_mtr.move(0);
        pros::delay(100);
    }
}
void DriveTrain(double LF, double RF, double LB, double RB)
{
    left_mtr.move(LF);
	right_mtr.move(RF);
    left_mtr2.move(LB);
	right_mtr2.move(RB);
}
void DriveRot(float degrees, double speed)
{
    left_mtr.move_relative(degrees, speed);
	right_mtr.move_relative(degrees, speed);
    left_mtr2.move_relative(degrees, speed);
	right_mtr2.move_relative(degrees, speed);
}

void Auton0() //Calibration Auton
{
    //Move 1 tile back
    DriveTrain(50,-50,50,-50);
    pros::delay(600);
    DriveTrain(0,0,0,0);
    pros::delay(500);
    //Move 1 tile forward
    DriveTrain(-50,50,-50,50);
    pros::delay(600);
    DriveTrain(0,0,0,0);
    pros::delay(500);
    //90 degree turn
    DriveRot((90*5), 50);
    pros::delay(700);
    //DriveTrain(0,0,0,0);
    pros::delay(500);
    //180 degree turn
    DriveRot(-(90*5), 50);
    pros::delay(1400);
    DriveTrain(0,0,0,0);
    pros::delay(500);
}

void Auton1() //blue, goal side
{
    pros::lcd::set_text(1, "Auton 1 running!");

    //forward 1 tile
    DriveTrain(-127,127,-127,127);
    pros::delay(500);
    //STOP GORDON
    DriveTrain(0,0,0,0);

    //propel blue triball towards goal with intake
    //turn 45 degrees to the left
    //move 2 squares
    //turn 45 degrees
    //move half a tile
    //grab triball
    //turn 135 degrees right
    //propel triball towards goal
    //turn 180 degrees, move forward 1 tile, and grab the other triball
    //turn another 180 and propel triball
    
}

void Auton2() //red, goal side
{
    pros::lcd::set_text(1, "Auton 2 running!");

    //forward 1 tile
    DriveTrain(-127,127,-127,127);
    pros::delay(500);
    //STOP GORDON
    DriveTrain(0,0,0,0);

    //push alliance triball into goal beside you
    //back up and grab second triball
    //drop second triball into the general field
    //move to elevation bar
}

void Auton3() //blue, opposing side
{
    pros::lcd::set_text(1, "Auton 3 running!");

    AutoCatapult(1);
}

void Auton4() //red, opposing side
{
    pros::lcd::set_text(1, "Auton 4 running!");

    AutoCatapult(1);
}



void AutonSkills()
{
    AutoCatapult(10);
}