#include "lm.h"
#include <iostream>
#include "point.h"



double LM::getX() { //Returns the ship's x coordinate on screen
	return this->position.getX();
}

double LM::getY() { //Returns the ship's y coordinate on screen
	return this->position.getY();
}

double LM::getAngle() { //Returns the ship's current steering angle
	return this->angle;
}

void LM::updateAngle(double value) { //Steers the ship by a specified amount
	this->angle += value;
}

double LM::getThrust() {  //Returns ship's thrust power value
	return thrust;
}

double LM::getXVelocity() { //Returns ship's current velocity in horizontal direction
	return this->xVelocity;
}

double LM::getYVelocity() { //Returns ship's current velocity in vertical direction
	return this->yVelocity;
}

double LM::getFuel() {  //Returns the amount of available fuel in the ship
	return this->fuel;
}

void LM::updateXPosition() {       //Updates the ship's x coordinate to a new position on the screen
	this->position.addX(this->xVelocity);
}

void LM::updateYPosition() {        //Updates the ship's y coordinate to a new position on the screen
	this->position.addY(this->yVelocity);
}

void LM::updateFuel() {            //Decreases the ship's fuel reserve by a fixed amount
	this->fuel -= 10;
}

void LM::updateXVelocity(double value) {      //Inreases/Decreases ship's velocity in horizontal direction by a specified amount   
	this->xVelocity += value;
}

void LM::updateYVelocity(double value) {     //Inreases/Decreases ship's velocity in vertical direction by a specified amount
	this->yVelocity += value;
}




