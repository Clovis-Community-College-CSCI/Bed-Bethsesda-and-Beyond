#include "Map.h"
#include <unistd.h>
#include <vector>

const int MAX_FPS = 90;
const unsigned int TIMEOUT = 10;

const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;


void turn_on_ncurses() {
    initscr(); //Starts NCURSES and creates a screen.
    start_color(); //Turns on color function if available on system

//Creates colored pairs using 3 inputs: Pair ID, Foreground Color, Background Color
init_pair(1, COLOR_WHITE, COLOR_BLACK);
init_pair(2, COLOR_CYAN, COLOR_BLACK);
init_pair(3, COLOR_BLUE, COLOR_BLACK);
init_pair(4, COLOR_YELLOW, COLOR_BLACK);
init_pair(5, COLOR_RED, COLOR_BLACK);
init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
init_pair(7, COLOR_GREEN, COLOR_BLACK);

clear(); //Clears anything from NCURSES window

noecho(); //Prevents user input from being output on the screen as text.

cbreak(); // Allows CTRL + C to be used to exit NCURSES.

timeout(TIMEOUT); //Timeout for user input
}

void turn_off_ncurses() {
	clear(); //Clears NCURSES
	endwin(); //Ends NCURSES 

if (system("clear")) {} //Clears the terminal
}

int main() {

int x,y; // x and y coords. Used to display current player pos and check boundaries.

printf("Hello World! X: %i Y: %i\n", x, y); //Prints this after NCURSES ends, allows determination of NCURSES state.

turn_on_ncurses(); //Runs function in main

Map map; //Creates map instance from Map class in Map.h

x = Map :: SIZE /2, y = 1;//Starts player at the top of the map

int old_x = -1, old_y = -1;

while (true) {
int ch = getch(); //Wait for the user to input and has TIMEOUT delay

//Allows user to exit the game by pressing Q at any time.
if (ch == 'q' or ch == 'Q') {
	break;
}

//Player input for Right Arrow Key, checks if x coord is not a door or wall.
//Only allows movement if current positio3n + 1 is not a door or wall.
else if (ch == RIGHT){

	if (!map.isDoor(x+1, y) and  !map.hasWall(x+1,y)){
		x++;
		//The :: is used to access the SIZE member of the Map class to check x coord
		if (x>= Map :: SIZE) {
			x = Map :: SIZE -1;
		}
	} 
}

//Player input for Left Arrow Key, checks if x coord is not a door or wall.
//Only allows movement if current position - 1 is not a door or wall.
else if (ch == LEFT) {
    
	if (!map.isDoor(x-1, y) and  !map.hasWall(x-1, y)) {
		x--;
		//Checks if x coord would leave map min value and sets the x coord back to 0 if so.
		if ( x < 0) {
			x = 0;
		}
	}
}

//Player input for Up Arrow Key, checks if x coord is not a door or wall.
//Only allows movement if current position + 1 is not a door or wall.
else if (ch == UP) {
    if(!map.isDoor(x, y-1) and !map.hasWall(x, y-1)) {
		y--;
		if (y <0) {
			y = 0;
		}
	}
}

//Player input for DOWN Arrow Key, checks if x coord is not a door or wall.
//Only allows movement if current position + 1 is not a door or wall.
else if (ch == DOWN) {
    if(!map.isDoor(x, y+1) and !map.hasWall(x,y+1) ){
		y++;
		if (y >= Map :: SIZE) y= Map :: SIZE -1;
}}
else if (ch == ERR) { //If the player presses nothing, nothing will happen.
;
}

if (x != old_x or y != old_y) { // Stop flickering by only redrawing on change to x or y coord

	if (map.isKey(x , y , Map::BKEY)) { //Runs isKey function from Map.h
		for (size_t i = 0; i < Map::SIZE; i++) {
			for(size_t j = 0; j < Map::SIZE; j++) {
				if (map.objectLocation(j,i) == Map::BDOOR) { //Retrieves the location of every instance of BDOOR
					map.changeObject(j, i, Map::OPEN); //Changes every instance of BDOOR to OPEN after player touches BKEY
				}
			}
		}
	}

	if (map.isKey(x , y , Map::GKEY)) { //Runs isKey function from Map.h
		for (size_t i = 0; i < Map::SIZE; i++) {
			for(size_t j = 0; j < Map::SIZE; j++) {
				if (map.objectLocation(j,i) == Map::GDOOR) { //Retrieves the location of every instance of BDOOR
					map.changeObject(j, i, Map::OPEN); //Changes every instance of BDOOR to OPEN after player touches BKEY
				}
			}
		}
	}


map.draw(x,y); //Creates the map using the draw function from Map Class everytime there is a change to x or y coord

mvprintw(Map :: DISPLAY+1,0, "X: %i Y: %i\n", x,y); //Displays player's current position.

refresh(); //Refreshes map after player input or TIMEOUT

}

//Sets old value to new position of x or y to be ready to be checked again
old_x = x; 
old_y = y;

usleep(1'000'000/MAX_FPS); //Determines max framerate for the game.

//End of Loop
}

//Ends NCURSES once while loop no longer == True
turn_off_ncurses();
}


