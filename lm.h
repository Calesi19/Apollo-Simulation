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

	double angle = 0;
	double fuel = 5000;
	double weight;
	double thrust;
	double xVelocity;
	double yVelocity;

public:

	Point position = Point(200, 350);

	double getX();

	double getY();

	double getAngle();

	void updateAngle(double value);

	double getThrust();

	double getXVelocity();

	double getYVelocity();

	void updateXVelocity(double value);

	void updateYVelocity(double value);

	void updateXPosition();

	void updateYPosition();

	double getFuel();

	void updateFuel();

};
