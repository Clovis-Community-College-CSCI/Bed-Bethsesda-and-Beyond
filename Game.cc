#include "Map.h"
#include <ncurses.h>
#include <unistd.h>
#include "WireCutting.cc"
#include "TicTacToe.cc"
#include "Desk.cc"
#include "Credits.cc"
#include "Lock.cc"
#include "Riddle.cc"
#include <vector>

const int MAX_FPS = 90;
const unsigned int TIMEOUT = 10;

const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;

bool cellKey = false;
bool greenKey = false;
bool magentaKey = false;
bool manual = false;

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

def_prog_mode();
}

void turn_off_ncurses() {
	clear(); //Clears NCURSES
	endwin(); //Ends NCURSES 

if (system("clear")) {} //Clears the terminal
}

int main() {

int x,y; // x and y coords. Used to display current player pos and check boundaries.

printf("Game Over\n"); //Prints this after NCURSES ends, allows determination of NCURSES state.

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

	if (!map.isDoor(x+1, y) and  !map.hasWall(x+1,y) and !map.isInmate(x+1,y)){
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
    
	if (!map.isDoor(x-1, y) and  !map.hasWall(x-1, y) and !map.isInmate(x-1,y)) {
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
    if(!map.isDoor(x, y-1) and !map.hasWall(x, y-1) and !map.isInmate(x,y-1)) {
		y--;
		if (y <0) {
			y = 0;
		}
	}
}

//Player input for DOWN Arrow Key, checks if x coord is not a door or wall.
//Only allows movement if current position + 1 is not a door or wall.
else if (ch == DOWN) {
    if(!map.isDoor(x, y+1) and !map.hasWall(x,y+1) and !map.isInmate(x,y+1)){
		y++;
		if (y >= Map :: SIZE) y= Map :: SIZE -1;
}}
else if (ch == ERR) { //If the player presses nothing, nothing will happen.
;
}


//Map refresh and player movement conditions
if (x != old_x or y != old_y) { // Stop flickering by only redrawing on change to x or y coord

if (map.isBen(x , y)) {
	turn_off_ncurses();
	riddleMain();
	if (riddleWin == true) {
		magentaKey = true;
	}
}

if (map.isLock(x, y)) {
	turn_off_ncurses();
	LockMain();
	turn_on_ncurses();
//	lockWin = true;
	if (lockWin == true) {
		for (size_t i = 0; i < Map::SIZE; i++) {
			for(size_t j = 0; j < Map::SIZE; j++) {
				if (map.objectLocation(j,i) == Map::CDOOR) { 
					map.changeObject(j, i, Map::OPEN); 					
				}
				if (map.objectLocation(j,i) == Map::LOCK) {
					map.changeObject(j, i, Map::OPEN);
				}

			}
		}	

	}

}

//Tic Tac Toe Puzzle
if (map.isNPC(x , y)) { //Runs isInmate function from Map.h
		turn_off_ncurses();
		char choice;
		cout << "Want to play a game?" << endl;
		cout << "If you beat me, I'll give you a Green Key!"<<endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;
		while (choice != '1' && choice != '2') {
			cout << "You're talking nonsense, do you want to play or not?"<<endl;
			cin >> choice;
		}
		if (choice == '2') {
			cout <<"I'll be here when you change your mind."<<endl;
			sleep(2);
			
		}
		if (choice == '1') {
			TicTacToemain();
			
			if (playerWin == true){
				cout << "You played well, here's the Green Key as promised!" <<endl;
				sleep (3);
				for (size_t i = 0; i < Map::SIZE; i++) {
					for(size_t j = 0; j < Map::SIZE; j++) {
						if (map.objectLocation(j,i) == Map::GDOOR) { 
						map.changeObject(j, i, Map::OPEN); 					
						}
						if (map.objectLocation(j,i) == Map::NPC) {
							map.changeObject(j, i, Map::OPEN);
						}

					}
				}
			}
		}
		greenKey = true;
		turn_on_ncurses();
	}//End of Tic Tac Toe Puzzle

//Desk Puzzle	
if (map.isDesk(x , y)) { //Runs isDesk function from Map.h
		turn_off_ncurses();
		
		cout << "You happen upon the Warden's Desk." << endl;
		cout << "You only have a few minutes before the warden!"<< endl;
		cout << "HURRY BEFORE YOU ARE CAUGHT!!!" <<endl;
		sleep (1);
		
		deskMain();

		if (deskWin == true){
				
				for (size_t i = 0; i < Map::SIZE; i++) {
					for(size_t j = 0; j < Map::SIZE; j++) {
						if (map.objectLocation(j,i) == Map::MDOOR) { 
						map.changeObject(j, i, Map::OPEN); 					
						}
						if (map.objectLocation(j,i) == Map::DESK) {
							map.changeObject(j, i, Map::OPEN);
						}

					}
				}
			}
		manual = true;
		turn_on_ncurses();
	}

	if (map.isKey(x , y , Map::BKEY)) { //Runs isKey function from Map.h
		for (size_t i = 0; i < Map::SIZE; i++) {
			for(size_t j = 0; j < Map::SIZE; j++) {
				if (map.objectLocation(j,i) == Map::BDOOR) { //Retrieves the location of every instance of BDOOR
					map.changeObject(j, i, Map::OPEN); //Changes every instance of BDOOR to OPEN after player touches BKEY
				}
				if (map.objectLocation(j,i) == Map::BKEY) {
					map.changeObject(j, i, Map::OPEN);
				}
			}
		}
		cellKey = true;
	}

//Final Gate Puzzle

	if (map.isBox(x, y)) {
		turn_off_ncurses();
		CarMain();
		turn_on_ncurses();

		// Opens Door if Player Wins Puzzle
		if (Complete == true){
			for (size_t i = 0; i < Map::SIZE; i++) {
				for(size_t j = 0; j < Map::SIZE; j++) {
					if (map.objectLocation(j,i) == Map::YDOOR) { 
						map.changeObject(j, i, Map::OPEN); 			
					}
					if (map.objectLocation(j,i) == Map::BOX) {
						map.changeObject(j, i, Map::OPEN);
					}
				}
			}
		}


	} //End of Puzzle Function
	

	if (map.isEscape(x, y)) {
		turn_off_ncurses();
		creditsMain();
	}

map.draw(x,y); //Creates the map using the draw function from Map Class everytime there is a change to x or y coord

mvprintw(15 , Map::DISPLAY+14, "X: %i Y: %i\n", x,y); //Displays player's current position.

//Inventory Box
//Top
//mvprintw(25 , Map::DISPLAY+2, "—————————————————————————————————");
mvprintw(25 , Map::DISPLAY+2, "--------------------------------");

//Left side
mvprintw(25 , Map::DISPLAY+1, "|");
mvprintw(26 , Map::DISPLAY+1, "|");
mvprintw(27 , Map::DISPLAY+1, "|");
mvprintw(28 , Map::DISPLAY+1, "|");
mvprintw(29 , Map::DISPLAY+1, "|");
mvprintw(30 , Map::DISPLAY+1, "|");
mvprintw(31 , Map::DISPLAY+1, "|");
mvprintw(32 , Map::DISPLAY+1, "|");
mvprintw(33 , Map::DISPLAY+1, "|");
mvprintw(34 , Map::DISPLAY+1, "|");
mvprintw(35 , Map::DISPLAY+1, "|");

//Bottom
mvprintw(35 , Map::DISPLAY+2, "--------------------------------");
//mvprintw(35 , Map::DISPLAY+2, "—————————————————————————————————");

//Right side
mvprintw(25 , Map::DISPLAY+34, "|");
mvprintw(26 , Map::DISPLAY+34, "|");
mvprintw(27 , Map::DISPLAY+34, "|");
mvprintw(28 , Map::DISPLAY+34, "|");
mvprintw(29 , Map::DISPLAY+34, "|");
mvprintw(30 , Map::DISPLAY+34, "|");
mvprintw(31 , Map::DISPLAY+34, "|");
mvprintw(32 , Map::DISPLAY+34, "|");
mvprintw(33 , Map::DISPLAY+34, "|");
mvprintw(34 , Map::DISPLAY+34, "|");
mvprintw(35 , Map::DISPLAY+34, "|");

if (cellKey == true) {
	
mvprintw(26 , Map::DISPLAY+3, "Cell Key");

}

if (manual == true) {

mvprintw(32 , Map::DISPLAY+3, "Wire Order: '1 2 5 6 8 10'");
}

if (greenKey == true) {
	
mvprintw(28 , Map::DISPLAY+3, "Green Key");

}

if (magentaKey == true) {
	
mvprintw(30 , Map::DISPLAY+3, "Note - '9 2 5'");

}

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


