#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "control.h"

int main(int argc, char const *argv[])
{
    int initialX = 7;
    int initialY = 5;
    int initialDir = 1;
    int initialMarker = 0;

    if (argc == 3) // Four arguments were typed
    {
        initialX = atoi(argv[1]);   // Get x value
        initialY = atoi(argv[2]);   // Get y value
    }
    Robot robot;
    robot.x = initialX;
    robot.y = initialY;
    robot.dir = initialDir;
    robot.hasMarker = initialMarker;
    setGrid();
    setMarkers();
    setBlocks();
    // setting home
    grid[initialY][initialX] = HOME;
    
    drawBackground();
    goToStart(&robot);
    explore(&robot);
    finished();
    return 0;
}