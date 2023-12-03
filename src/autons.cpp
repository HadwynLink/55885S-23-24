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

    //turn towards goal 
    //move forwards
    //turn towards other side of the field
    //start loop: rapid-fire match loading
    //turn towards elevation bar
    //move forwards
}

void Auton2()
{
    pros::lcd::set_text(1, "Auton 2 running!");
}