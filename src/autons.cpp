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

	pros::Motor left_mtr(9);
	pros::Motor right_mtr(8);
	pros::Motor left_mtr2(6);
	pros::Motor right_mtr2(7);

	pros::Motor lift_mtr(20);

	pros::Motor cata_mtr(10);

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
    DriveTrain(100,-100,-100,100);
    pros::delay(600);
    DriveTrain(0,0,0,0);
    pros::delay(500);
    //Move 1 tile forward
    DriveTrain(-100,100,100,-100);
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

void Auton1() //blue, goal side: 10 points
{
    pros::lcd::set_text(1, "Offense running!");

    //forward 1 tile
    cata_mtr.move(-127);
    pros::delay(500);
    //DriveTrain(-100,100,100,-100);
    cata_mtr.move(0);
    DriveTrain(100,-100,-100,100);
    pros::delay(200);
    DriveTrain(0,0,0,0);
    pros::delay(500);
    DriveTrain(-100,100,100,-100);
    pros::delay(1000);
    DriveTrain(100,100,100,100);
    pros::delay(500);
    DriveTrain(-100,100,100,-100);
    cata_mtr.move(127);
    pros::delay(1500);
    DriveTrain(100,-100,-100,100);
    pros::delay(500);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,-100,-100,-100);
    pros::delay(650);
    DriveTrain(0,0,0,0);
    cata_mtr.move(-127);

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
    pros::delay(500);
    DriveTrain(0,0,0,0);
    cata_mtr.move(0);
}

void Auton2() //red, goal side: 10 points
{
    pros::lcd::set_text(1, "Red Offense running!");

    //forward 1 tile
    cata_mtr.move(-127);
    pros::delay(500);
    //DriveTrain(-100,100,100,-100);
    cata_mtr.move(0);
    DriveTrain(100,-100,-100,100);
    pros::delay(200);
    DriveTrain(0,0,0,0);
    pros::delay(500);
    DriveTrain(-100,100,100,-100);
    pros::delay(1000);
    DriveTrain(100,100,100,100);
    pros::delay(500);
    DriveTrain(-100,100,100,-100);
    cata_mtr.move(127);
    pros::delay(1500);
    DriveTrain(100,-100,-100,100);
    pros::delay(500);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,-100,-100,-100);
    pros::delay(650);
    DriveTrain(0,0,0,0);
    cata_mtr.move(-127);

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
    pros::delay(500);
    DriveTrain(0,0,0,0);
    cata_mtr.move(0);
}

void Auton3() //blue, opposing side: 7 points
{
    pros::lcd::set_text(1, "Defense running!");
    cata_mtr.move(-127);
    pros::delay(500);
    //DriveTrain(-100,100,100,-100);
    cata_mtr.move(0);
    DriveTrain(100,-100,-100,100);
    pros::delay(200);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,-100,-100,-100);
    pros::delay(500);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,100,100,-100);
    cata_mtr.move(-127);
    pros::delay(1000);
    DriveTrain(0,0,0,0);
    cata_mtr.move(0);
}

void Auton4() //red, opposing side: 7 points
{
    pros::lcd::set_text(1, "Red defense running!");
    cata_mtr.move(-127);
    pros::delay(500);
    //DriveTrain(-100,100,100,-100);
    cata_mtr.move(0);
    DriveTrain(100,-100,-100,100);
    pros::delay(200);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,-100,-100,-100);
    pros::delay(500);
    DriveTrain(0,0,0,0);
    pros::delay(100);
    DriveTrain(-100,100,100,-100);
    cata_mtr.move(-127);
    pros::delay(1000);
    DriveTrain(0,0,0,0);
    cata_mtr.move(0);
}



void AutonSkills()
{
    pros::lcd::set_text(1, "Auton Skills running!");

    DriveTrain(100,-100,-100,100);
    pros::delay(300);
    DriveTrain(0,0,0,0);
    lift_mtr.move(100);
    pros::delay(1750);
    lift_mtr.move(0);
    cata_mtr.move(127);
    pros::delay(90000);
    cata_mtr.move(0);
    //DriveTrain(-100,100,100,-100);
    pros::delay(3000);
    DriveTrain(0,0,0,0);
    cata_mtr.move(0);
}