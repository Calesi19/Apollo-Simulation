/***********************************************************************
 * Header File:
 *    Star : Represents the stars in the background of the lunar lander game
 * Author:
 *    Braxton Meyer and Carlos Lespin
 * Summary:
 *    Where the star is located and what phase of blinking it is in
 ************************************************************************/

#include <stdlib.h> 
#include "star.h"

 /******************************************
  * STAR : CONSTRUCTOR WITH POINT
  * Initialize the star at the passed position
  *****************************************/
Star::Star(Point newPosition)
{
	// Sets the phase to a random state so all the stars blink at different times
	this->phase = rand() % 207 +1;
	// Likewise, the position is randomized so the sky can be filled with an unpatterned array of stars
	this->position = newPosition;
}

void Star::incrementPhase(int& phase)
{
	phase++;
}

int Star::getPhase()
{
	this->phase += 1;
	return this->phase;
}
