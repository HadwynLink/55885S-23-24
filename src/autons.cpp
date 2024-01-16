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
        cata_mtr.move(100);
        pros::delay(300);
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

void Auton1() //blue, goal side
{
    pros::lcd::set_text(1, "Auton 1 running!");

    //turn towards goal 
    DriveTrain(50,-50,50,-50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
    pros::delay(500);
    //turn towards elevation bar
    DriveTrain(-50,50,-50,50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
    pros::delay(500);
    //STOP GORDON
    DriveTrain(0,0,0,0);
}

void Auton2() //red, goal side
{
    pros::lcd::set_text(1, "Auton 2 running!");

    //turn towards goal 
    DriveTrain(-50,50,-50,50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
    pros::delay(500);
    //turn towards elevation bar
    DriveTrain(50,-50,50,-50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
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

    //second triball grabby and throwy here

    //turn towards elevation bar
    DriveTrain(50,-50,50,-50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
    pros::delay(500);
    //STOP GORDON
    DriveTrain(0,0,0,0);
}

void Auton4() //red, opposing side
{
    pros::lcd::set_text(1, "Auton 4 running!");

    AutoCatapult(1);

    //second triball grabby and throwy here

    //turn towards elevation bar
    DriveTrain-(50,50,-50,50);
    pros::delay(500);
    //move forwards
    DriveTrain(50,50,50,50);
    pros::delay(500);
    //STOP GORDON
    DriveTrain(0,0,0,0);
}



void AutonSkills()
{
    AutoCatapult(10);
}