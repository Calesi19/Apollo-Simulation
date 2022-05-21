#include "lm.h"
#include <iostream>
#include "point.h"



double LM::getX() {
	return this->position.getX();
}

double LM::getY() {
	return this->position.getY();
}

double LM::getAngle() {
	return this->angle;
}

void LM::updateAngle(double value) {
	this->angle += value;
}

double LM::getThrust() {
	return thrust;
}

double LM::getXVelocity() {
	return this->xVelocity;
}

double LM::getYVelocity() {
	return this->yVelocity;
}

double LM::getFuel() {
	return this->fuel;
}

void LM::updateXPosition() {
	this->position.addX(this->xVelocity);
}

void LM::updateYPosition() {
	this->position.addY(this->yVelocity);
}

void LM::updateFuel() {
	this->fuel -= 10;
}

void LM::updateXVelocity(double value) {
	this->xVelocity += value;
}

void LM::updateYVelocity(double value) {
	this->yVelocity += value;
}




