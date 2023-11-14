#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "control.h"

int main(int argc, char const *argv[])
{
    int initialX = 4; //initializing with default values in case of no input running
    int initialY = 5;
    int initialDir = 1;
    int initialMarker = 0;

    if (argc == 3) // 3 arguments were typed
    {
        initialX = atoi(argv[1]);   // Get x value
        initialY = atoi(argv[2]);   // Get y value
    }

    Robot robot;
    robot.x = initialX;
    robot.y = initialY;
    robot.dir = initialDir;
    robot.hasMarker = initialMarker;

    //setting background
    setGrid();
    setMarkers();
    setBlocks();

    grid[initialY][initialX] = HOME; // setting home
    
    drawBackground(); //drawing all background objects
    goToStart(&robot);
    explore(&robot);
    goHome(&robot); //after every square is checked, go back to home to finish
    finished();
    return 0;
}