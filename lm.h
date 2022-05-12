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
	Point position;
	double angle;
	double fuel;
	double weight;
	double thrust;
	double velocity;

public:
	double getX();

	double getY();

	double getAngle();

	void updateAngle(string userInput);

	double getThrust();

	double getXVelocity();

	double getYVelocity();

	double getVelocity();

	void updatePosition();

	void updateFuel();

	void updateVelocity();

};
