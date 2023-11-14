#include "robotGraphics.h"

void left(Robot *robot);
void right(Robot *robot);
int atMarker(Robot robot);
int goingOutGrid(Robot robot);
int blockAhead(Robot robot);
int canMoveForward(Robot robot);
void forward(Robot *robot);
int atHome(Robot robot);
int isCarryingAMarker(Robot robot);
void pickUpMarker(Robot *robot);
void dropMarker(Robot *robot);
void recordMovement(Robot *robot);
void dodgeBlock(Robot *robot, int straight);
void resetBackMovesList();
void comingBackFromHome(Robot *robot);
void goHome(Robot *robot);
void markerToHomeAndBack(Robot *robot);
void checkMarker(Robot *robot);
void checkBlock(Robot *robot);
void sideTurn(Robot *robot, int leftSide);
void goToStart(Robot *robot);
void explore(Robot *robot);

