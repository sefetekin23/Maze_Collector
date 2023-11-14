#include "graphics.h"
#include "robotGraphics.h"
#include <stdlib.h>

void setGrid()
{
    for (int i = 0; i < gridNumber; i++) //itirates over the rows of the grid
    {
        for (int j = 0; j < gridNumber; j++) //itirates over the column of the grid
        {
            grid[i][j] = EMPTY;  //sets everything to be EMPTY at first
        }
    }
    //sets all the markers
    grid[0][4] = MARKER;
    grid[3][9] = MARKER;
    grid[5][2] = MARKER;
    grid[7][1] = MARKER;
    grid[4][7] = MARKER;
    grid[9][8] = MARKER;
    //sets all the blocks
    grid[1][5] = BLOCK;
    grid[3][2] = BLOCK;
    grid[7][4] = BLOCK;
    grid[5][8] = BLOCK;
}
void drawBackground()
{
    setWindowSize(screenSize, screenSize);
    background();
    setColour(black);
    for (int y = 0; y < gridNumber; y++)
    {
        for (int x = 0; x < gridNumber; x++)
        {
            if (grid[y][x] == MARKER)
                displayImage("images/grocery_bag.png", x * gridSize, y * gridSize);
            else if (grid[y][x] == BLOCK)
                fillRect(x * gridSize, y * gridSize, gridSize, gridSize); //creates a black block representing the BLOCK
            else if (grid[y][x] == HOME)
                displayImage("images/house.png", x * gridSize, y * gridSize);
            drawRect(x * gridSize, y * gridSize, gridSize, gridSize);
        }
    }
        foreground();
}

// Update the foreground layer to display the square in a new position
void update(Robot robot)
{
    foreground();
    clear();
    if (robot.hasMarker == 1)
        displayImage("images/grocery_bag.png", robot.x * gridSize, robot.y * gridSize);
    switch (robot.dir)
    {
    case EAST:
        displayImage("images/east.png", robot.x * gridSize, robot.y * gridSize);
        break;
    case SOUTH:
        displayImage("images/south.png", robot.x * gridSize, robot.y * gridSize);
        break;
    case WEST:
        displayImage("images/west.png", robot.x * gridSize, robot.y * gridSize);
        break;
    case NORTH:
        displayImage("images/north.png", robot.x * gridSize, robot.y * gridSize);
        break;
    default:
        break;
    }
    sleep(waittime); //has a delay to enable it to be seen
}

void pickUpMarkerVisual(Robot *robot)  //empties the square that the marker was
{
    background();
    setColour(white);
    fillRect(robot->x * gridSize, robot->y * gridSize, gridSize, gridSize);
    setColour(black);
    drawRect(robot->x * gridSize, robot->y * gridSize, gridSize, gridSize);
    foreground();
    update(*robot);
}

void finished()
{
    displayImage("images/success.png", gridSize * 2 - 5, gridSize * 4);
}