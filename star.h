/***********************************************************************
 * Header File:
 *    Star : Represents the stars in the background of the lunar lander game
 * Author:
 *    Braxton Meyer
 * Summary:
 *    Where the star is located and what phase of blinking it is in
 ************************************************************************/

#pragma once
#include "point.h"   // for Point



class Star
{
public:
	// constructor
	Star(Point position);

	// setters
	void setPosition(Point newPosition) { this->position = newPosition; }
	void setPhase(int newPhase) { this->phase = newPhase; }

	// getters
	double getX()       const { return position.getX(); }
	double getY()       const { return position.getY(); }
	int getPhase();

	Point position;
	int phase;

private:

	void incrementPhase(int & phase);

};
