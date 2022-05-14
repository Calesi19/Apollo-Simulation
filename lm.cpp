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
	return this->getVelocity() * sin(this->getAngle());
}

double LM::getYVelocity() {
	return this->getVelocity() * cos(this->getAngle());
}

double LM::getVelocity() {
	return this->velocity;
}

double LM::getFuel() {
	return this->fuel;
}

void LM::updateXPosition(double value) {
	this->position.addX(value);
}

void LM::updateYPosition(double value) {
	this->position.addY(value);
}

void LM::updateFuel() {
	this->fuel -= 1;
}

void LM::updateVelocity() {

}

