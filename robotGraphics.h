#define EMPTY 0
#define MARKER 1
#define BLOCK 2
#define HOME 3
#define ROBOT 4

#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

static const int gridSize = 50 ;  // length of sqaures's edges
static const int waittime = 75 ; // wait between updates
static const int screenSize = 500;
static const int gridNumber = screenSize/gridSize; // calculating the number of grids
int grid[gridNumber][gridNumber];

typedef struct Robot
{
    int x, y, dir, hasMarker;
} Robot;

void setGrid();
void setMarkers();
void setBlocks();
void drawBackground();
void pickUpMarkerVisual(Robot *robot);
void update(Robot robot);
void finished();
