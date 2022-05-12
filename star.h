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

{
	class star
	{
	public:
		void setPosition();

		int getX();

		int getY();

		int getPhase();

	private:
		point position;

		int phase;

		void incrementPhase();

	};
}