#pragma once
#include <iostream>
#include "point.h"
#include <string>
using namespace std;
/***********************************************************************
 * Header File:
 *    LM class: This class represents the LM ship that will be flying in the program.
 * Author:
 *    Braxton Meyer and Carlos Lespin
 * Summary:
 *    This class will hold all the information and values associated with the ship; like fuel, position,
 * velocity, etc...
 ************************************************************************/


class LM {

private:

	double angle = 0;              //ship's steering angle
	double fuel = 5000;            //ship's fuel reserve
	double weight;                 //ship's weight - constant value
	double thrust;                 //ship's thrust power - constant value
	double xVelocity;              //ship's velocity in horizontal direction
	double yVelocity;              //ship's velocity in vertical direction

public:

	Point position = Point(200, 350);            //Point class tracks ship's position on screen

	double getX();                //Returns the ship's x coordinate on screen

	double getY();                //Returns the ship's y coordinate on screen

	double getAngle();            //Returns the ship's current steering angle

	void updateAngle(double value);           //Steers the ship by a specified amount

	double getThrust();                     //Returns ship's thrust power value

	double getXVelocity();                  //Returns ship's current velocity in horizontal direction

	double getYVelocity();                  //Returns ship's current velocity in vertical direction

	void updateXVelocity(double value);     //Inreases/Decreases ship's velocity in horizontal direction by a specified amount

	void updateYVelocity(double value);     //Inreases/Decreases ship's velocity in vertical direction by a specified amount

	void updateXPosition();                 //Updates the ship's x coordinate to a new position on the screen

	void updateYPosition();                 //Updates the ship's y coordinate to a new position on the screen

	double getFuel();                       //Returns the amount of available fuel in the ship

	void updateFuel();                      //Decreases the ship's fuel reserve by a fixed amount

};
