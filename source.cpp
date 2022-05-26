/**********************************************************************
* LAB 5: APOLLO 11 CODE COMPLETE
* BRAXTON MEYER AND CARLOS LESPIN
* 
* 
* 
* 
 * GL Game
 * Just a simple program to demonstrate how to create an Open GL window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "lm.h"
#include <stdlib.h> 
#include <vector>
#include <cstdlib>
#include <Windows.h>






using namespace std;


vector<Star> createStars(int amount) {
    /*************************************************************************
     * createStars function
     * This function creates an amount specified of stars in random positions.
     *************************************************************************/

    vector<Star> stars;
    int randX;
    int randY;

    for (int c = 0; c <= amount; c ++) {
        randX = rand() % 400 + 1;      //picks random x position
        randY = rand() % 400 + 200;    //picks random y position
        stars.push_back(Star(Point(randX, randY))); //creates star
    }
    return stars;
}


/*************************************************************************
 * Game Class
 * Initializes all actors and components used in the program
 *************************************************************************/
class Game
{
public:
    Game(const Point& ptUpperRight) :
        ground(ptUpperRight)
    {
    
    }

    LM ship;               //creates ship object
    vector<Star> stars = createStars(50); //creates all stars
    Point ptUpperRight;   // size of the screen
    Ground ground;        //creates ground object

};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    ogstream gout;
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Game* pGame = (Game*)p; //Game class initiates all actors

    // draw stars and updates their size in each frame
    for (int i = 0; i < pGame->stars.size(); i++) {
        gout.drawStar(pGame->stars[i].position, pGame->stars[i].getPhase());
    }

    // draw the ground
    pGame->ground.draw(gout);

    
    if (pGame->ship.getFuel() > 0) { //only takes player input if ship has fuel available

        // take input to steer ship
        if (pUI->isRight()) {
            pGame->ship.updateAngle(-0.1); // updates ship angle
        }
        if (pUI->isLeft()) {
            pGame->ship.updateAngle(0.1); // updates ship angle
        }

        if (pUI->isDown()) {
            // Break thrust into x and y components
            pGame->ship.updateYVelocity(.29 * cos(pGame->ship.getAngle()));
            pGame->ship.updateXVelocity(.29 * -sin(pGame->ship.getAngle()));
            pGame->ship.updateFuel(); //if ship is thrusting, deplete fuel reserve
        }
    }

    //update ship position based on ship velocity
    pGame->ship.updateYPosition(); 
    pGame->ship.updateXPosition(); 



    if (pGame->ship.getYVelocity() > -5 && pGame->ground.onPlatform(pGame->ship.position, 1)) {  //check if ship has landed successfully
        
        //Opens message box: indicating player landed successfully
        MessageBox(NULL, L"Succesful Landing", L"Info",
            MB_OK | MB_ICONEXCLAMATION);
       
        //close program
        Sleep(2000);
        exit(0);
        
    }
    else if (pGame->ground.hitGround(pGame->ship.position, 20)) { //check if ship hit ground
       
        //stop ship from moving if it hit ground
        pGame->ship.updateYVelocity(-pGame->ship.getYVelocity());
        pGame->ship.updateXVelocity(-pGame->ship.getXVelocity());

        //Opens message box: indicating player crashed
        MessageBox(NULL, L"Crash Landing", L"Info",
            MB_OK | MB_ICONEXCLAMATION);

        //Initializes the game again.
        Sleep(3000);
        Point ptUpperRight(400.0, 400.0);
        Interface ui(0, NULL,
            "Open GL Window",
            ptUpperRight);
        Game game(ptUpperRight);
        ui.run(callBack, &game);
        }

    //applies constant gravity to ship
    else {
        pGame->ship.updateYVelocity(-0.1625);
    }

    // draw the lander and its flames
    gout.drawLander(pGame->ship.position /*position*/, pGame->ship.getAngle() /*angle*/);
    gout.drawLanderFlames(pGame->ship.position, pGame->ship.getAngle(), /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());

    // draws game hud details
    gout.setPosition(Point(10.0, 380.0));
    gout << "Fuel: " << pGame->ship.getFuel() << "\nAltitude: " << pGame->ship.getY() << " meters\nSpeed: " << abs (pGame->ship.getYVelocity()) << " m/s";

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{   

    while (true) {
        // Initialize OpenGL
        Point ptUpperRight(400.0, 400.0);
        Interface ui(0, NULL,
            "Open GL Window",
            ptUpperRight);

        // Initialize the game class

        Game game(ptUpperRight);
        // set everything into action

        ui.run(callBack, &game);
    }
    

    return 0;
}
