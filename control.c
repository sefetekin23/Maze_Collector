#include "robotGraphics.h"

int moves[200]; 
int backMoves[200];
int backMoveNumber = 0;
int moveNumber = 0;

void left(Robot *robot)
{
    if ((robot->dir) == EAST)
        robot->dir += 3;
    else
        robot->dir -= 1;
}

void right(Robot *robot)
{
    if ((robot->dir) == NORTH)
        robot->dir -= 3;
    else
        robot->dir += 1;
}

int atMarker(Robot robot)
{
    return grid[robot.y][robot.x] == MARKER;
}
int goingOutGrid(Robot robot)
{
    return  (robot.x - 1 < 0 && robot.dir == WEST) ||
            (robot.y - 1 < 0 && robot.dir == NORTH) ||
            (robot.x + 1 >= gridNumber && robot.dir == EAST) ||
            (robot.y + 1 >= gridNumber && robot.dir == SOUTH);
}
int blockAhead(Robot robot)
{
    switch (robot.dir)
    {
    case 1:
        return grid[robot.y][robot.x + 1] == BLOCK;
    case 2:
        return grid[robot.y + 1][robot.x] == BLOCK;
    case 3:
        return grid[robot.y][robot.x - 1] == BLOCK;
    case 4:
        return grid[robot.y - 1][robot.x] == BLOCK;
    default:
        return 0;
    }
}

int atHome(Robot robot)
{
    return grid[robot.y][robot.x] == HOME;
}

void forward(Robot *robot)
{
    if (!goingOutGrid(*robot) && !blockAhead(*robot))
    {
        switch (robot->dir)
        {
        case EAST:
            robot->x += 1;
            break;
        case SOUTH:
            robot->y += 1;
            break;
        case WEST:
            robot->x -= 1;
            break;
        case NORTH:
            robot->y -= 1;
            break;
        }
    }
    update(*robot);
}

void pickUpMarker(Robot *robot)
{
    if (robot->hasMarker == 0 && atMarker(*robot))
    {
        grid[robot->y][robot->x] = EMPTY;
        robot->hasMarker = 1;
        pickUpMarkerVisual(robot);
    }
}

void dropMarker(Robot *robot)
{
    if (robot->hasMarker == 1 && atHome(*robot))
    {
        robot->hasMarker = 0;
        update(*robot);
    }
}
void recordMovement(Robot *robot)
{
    moves[moveNumber] = robot->dir;
    moveNumber++;
}
void dodgeBlock(Robot *robot, int straight)
{
    switch (robot->dir)
    {
    case EAST:
        left(robot);
        forward(robot);
        right(robot);
        forward(robot);
        forward(robot);
        right(robot);
        forward(robot);
        left(robot);
        break;
    case WEST:
        right(robot);
        forward(robot);
        left(robot);
        forward(robot);
        forward(robot);
        left(robot);
        forward(robot);
        right(robot);
        break;
    default:
        break;
    }
}

int isCarryingAMarker(Robot robot)
{
    return robot.hasMarker;
}


void resetBackMovesList()
{
    for (int m = 0; m < backMoveNumber; m++)
        backMoves[m] = 10;
    backMoveNumber = 0;
}
void comingBackFromHome(Robot *robot)
{
    for (int k = backMoveNumber - 1; k >= 0; k--) //itirates over backmovelist from the end to retrack all moves back to where it stopped
    {
        robot->dir = backMoves[k];
        if (blockAhead(*robot))
            dodgeBlock(robot, 1);
        forward(robot);
    }
    resetBackMovesList();
    robot->dir = moves[moveNumber - 1]; // sets the robot's direction to the last direction when it stopped
}
void goHome(Robot *robot)
{
    for (int l = moveNumber - 1; l >= 0; l--) //itirates over movelist from the end to retrack all moves back to home
    {
        switch (moves[l])
        {
        case EAST:
            robot->dir = WEST;
            break;
        case SOUTH:
            robot->dir = NORTH;
            break;
        case WEST:
            robot->dir = EAST;
            break;
        case NORTH:
            robot->dir = SOUTH;
            break;
        default:
            break;
        }
        forward(robot);
        if (blockAhead(*robot))
            dodgeBlock(robot, 0);
        
        backMoves[backMoveNumber] = moves[l]; //stores the going back home moves 
        backMoveNumber++; //stores them in order to be able to continue searching from where he stopped
    }
}
void markerToHomeAndBack(Robot *robot)
{
    pickUpMarker(robot);
    goHome(robot);
    dropMarker(robot);
    comingBackFromHome(robot);
}
void checkMarker(Robot *robot)
{
    if (atMarker(*robot))
        markerToHomeAndBack(robot);
    
}
void checkBlock(Robot *robot)
{
    if (blockAhead(*robot))
    {
        dodgeBlock(robot, 1);
        if (atMarker(*robot))
            markerToHomeAndBack(robot);
    }
}
void turnOnSides(Robot *robot, int leftSide)
{
    if (leftSide)
    {
        right(robot);
        recordMovement(robot);
        forward(robot);
        checkMarker(robot);
        right(robot);
        recordMovement(robot);
    }
    else
    {
        left(robot);
        recordMovement(robot);
        forward(robot);
        checkMarker(robot);
        left(robot);
        recordMovement(robot);
    }
}

void goToStart(Robot *robot)
{
    for (int i = 0; i < 3; i++)
    {
        while (!goingOutGrid(*robot))
        {
            recordMovement(robot);
            forward(robot);
            checkMarker(robot);
            checkBlock(robot);
        }
        right(robot);
    }
    right(robot);
}


void explore(Robot *robot)
{
    for (int i = 0; i <= gridNumber; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            
            if (!goingOutGrid(*robot))
            {
                recordMovement(robot);
                forward(robot);
                checkMarker(robot);
                checkBlock(robot);
            }
        }
        if (i % 2 == 1)
            turnOnSides(robot,1);
        else
            turnOnSides(robot,0);
    }
}