#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "control.h"

int main(int argc, char const *argv[])
{
    int initialX = 3;
    int initialY = 4;
    int initialDir = 1;
    int initialMarker = 0;

    if (argc == 4) // Four arguments were typed
    {
        initialX = atoi(argv[1]);   // Get x value
        initialY = atoi(argv[2]);   // Get y value
        initialDir = atoi(argv[3]); // Get direction
    }
    Robot robot;
    robot.x = initialX;
    robot.y = initialY;
    robot.dir = initialDir;
    robot.hasMarker = initialMarker;
    setGrid();

    // setting home
    grid[initialY][initialX] = HOME;

    drawBackground();
    goToStart(&robot);
    explore(&robot);
    finished();
    return 0;
}