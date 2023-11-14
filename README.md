# CCoursework

## Graphics 
Robot is visualized as a man, markers are grocery bags, and home is a house.

## Description
Robot goes to the bottom-left corner of the grid. Then, starts moving in each row to check for markers. 
If it comes across a marker, it picks up the marker, retracks its movements, and goes back home to drop marker.
After dropping the marker, it retracks the movements back to where it came across the marker and continues to explore.
If it comes across a block during any movement, it moves around the block. These moves aren't recorded in anytime.   
Markers are positined in a way that checkes all edge cases (while going to start point, just before and after a block, during block dodge, just before and after turning on sides, at the very last position)

Completed 6 out of 6 stages. 

## Compile
gcc -o fileName main.c graphics.c control.c robotGraphics.c 

## Run
### No Input
./fileName | java -jar drawapp-3.0.jar
### Home Position Input
./fileName xValue yValue | java -jar drawapp-3.0.jar

While inputting the home position, avoid inputting the positions of markers or blocks and enter values in the range (0,9) inclusive to (0,9) inclusive.  
Marker positions are: (9,3) , (0,5) , (3,3) , (3,7) , (7,4) , (8,9) , (0,0)   
Block positions are: (5,1) , (2,3) , (4,7) , (8,5) 