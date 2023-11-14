#include "robotGraphics.h"

void left(Robot *robot);
void right(Robot *robot);
int atMarker(Robot robot);
int goingOutGrid(Robot robot);
int canMoveForward(Robot robot);
int atHome(Robot robot);
void forward(Robot *robot);
void pickUpMarker(Robot *robot);
void recordMovement(Robot *robot);
void dropMarker(Robot *robot);
void dodgeBlock(Robot *robot, int straight);
int isCarryingAMarker(Robot robot);
void resetBackMovesList();
void comingBackFromHome(Robot *robot);
void goHome(Robot *robot);
void markerToHomeAndBack(Robot *robot);
void turnOnSides(Robot *robot, int leftSide);
void goToStart(Robot *robot);
void explore(Robot *robot);

