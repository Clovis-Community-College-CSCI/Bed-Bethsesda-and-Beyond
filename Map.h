#pragma once
#include <curses.h>
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <ncurses.h>
using namespace std;

class Map {
vector<vector<char>> map;
public:
// Need to write a function to save the map and reload the map, and getter/setter to get and set character in map

//Characters and objects
static const char YOU = '@';
static const char INMATE = '0'; 
static const char WALL = '#';
static const char BDOOR = '=';
static const char GDOOR = '-';
static const char YDOOR = '_';
static const char OPEN = ' ';
static const char GUARD = 'G';
static const char BKEY = 'K';
static const char NPC = 'O';
static const size_t SIZE = 400;
static const size_t DISPLAY = 40;

//Function to initialize the map
void init_map() {
    map.clear(); //Clears the map

    map.resize(SIZE); //Resizes the map to size defined in SIZE

	//For loop that resizes each row to have a length of SIZE and initializes every element to '.'
	//Effectively creates baseline for map size allowing the '.' to be changed later.
    for (auto &v : map) {
		v.resize(SIZE, ' '); //Amount of dots determined by SIZE x SIZE
	}

    for (size_t i = 0; i < SIZE; i++) { //For loop for rows of the map
        for (size_t j = 0; j < SIZE; j++) { //For loop for columns of the map
			
			//Defines WALL Locations around the map.
            if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1)
                map.at(i).at(j) = WALL;	
        }
    }
	//Map Creation/Customization
	/*for (size_t i = Start Row; i < End Row; i++) {
		for(size_t i = Start Column; i < End Column; i++ {
		map.at(i).at(j) = Object;
		}
	  }*/

	//map.at(down row).at(right column) = Object

	//Prison Cell Block A - Player's Cell
	for (size_t i = 1; i < 21; i++){ //Left Wall
		map.at(i).at((SIZE/2)- 23) = WALL;
	}
 	for (size_t i = 1; i < 21; i++){ //Right Wall
		map.at(i).at((SIZE/2)+ 23) = WALL;
	}   
	for (size_t i = (SIZE/2) - 23; i <= (SIZE/2) + 23; i++){ //Bottom Wall
		map.at(21).at(i) = WALL;
	}
	for (size_t i = (SIZE/2) - 2; i <= (SIZE/2) + 2; i++){ //Player's Cell Door
		map.at(21).at(i) = BDOOR;
	}
	//map.at(14).at((SIZE/2)-5) = GKEY;
	map.at(15).at((SIZE/2)-7) = BKEY;

	//Left and Right corridor outside Player Cell		
	for (size_t i = 22; i < 150; i++) {
		map.at(i).at(187) = WALL;
	}
	for (size_t i = 22; i <= 100; i++) {
		map.at(i).at(213) = WALL;
	}

	//Mess Hall Border
	for (size_t i = 214; i <= 264; i++) {//Top
		map.at(99).at(i) = WALL;
	}
	for (size_t i = 188; i <=264; i++) {//Bottom
		map.at(149).at(i) = WALL;
	}
	for (size_t i = 100; i < 123; i++) {//Top Left
		map.at(i).at(213) = WALL;
	}
	for (size_t i = 128; i < 150; i++) {//Bottom Left
		map.at(i).at(213) = WALL;
	}
	for (size_t i = 100; i < 150; i++) {//Top Left
		map.at(i).at(263) = WALL;
	}

	//Mess Hall Tables
	//Top Table
	for (size_t i = 230; i <= 250; i++) {//Top Layer
		map.at(105).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Middle Layer
		map.at(106).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Bottom Layer
		map.at(107).at(i) = WALL;
	}
	
	//Middle Table
	for (size_t i = 230; i <= 250; i++) {//Top Layer
		map.at(124).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Middle Layer
		map.at(125).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Bottom Layer
		map.at(126).at(i) = WALL;
	}
	
	//Bottom Table
	for (size_t i = 230; i <= 250; i++) {//Top Layer
		map.at(141).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Middle Layer
		map.at(142).at(i) = WALL;
	}
	for (size_t i = 230; i <= 250; i++) {//Bottom Layer
		map.at(143).at(i) = WALL;
	}
	
	//Inmates at Tables
	map.at(108).at(232) = INMATE;
	map.at(108).at(235) = INMATE;
	map.at(108).at(238) = NPC;
	map.at(108).at(241) = INMATE;
	map.at(108).at(244) = INMATE;
	map.at(108).at(247) = INMATE;
	map.at(104).at(232) = INMATE;
	map.at(104).at(235) = INMATE;
	map.at(104).at(238) = INMATE;
	map.at(104).at(241) = INMATE;
	map.at(104).at(244) = NPC;
	map.at(104).at(247) = INMATE;












} // End of init_map

//Drawing display tiles around (x,y)
//Effectively determines the Render Distance for the player
void draw(int x, int y) {
int start_x = x - DISPLAY/2;
int end_x = x + DISPLAY/2;
int start_y = y - DISPLAY/2;
int end_y = y +DISPLAY/2;

//Bounds check for edges of the world map.
//Makes it so it stops displaying at the edge of the map so the
//player can't see past the defined world.
if (start_x < 0) {
end_x = end_x-start_x;
start_x = 0;
}

if (end_x > SIZE-1) {
start_x = start_x - (end_x -(SIZE-1));
end_x = SIZE-1;
}

if (start_y<0) {
end_y = end_y - start_y;
start_y = 0;
}

if (end_y > SIZE-1) {
start_y = start_y - (end_y - (SIZE-1));
end_y = SIZE-1;
}

for (size_t i = start_y; i <= end_y; i++) { //Total rows displayed on screen
     for (size_t j = start_x; j <= end_x; j++) { //Total columns displayed on screen

	//Creates player icon. 
     if (i == y && j == x) {
     attron(A_UNDERLINE | A_BOLD);
     mvaddch(i-start_y, j-start_x, '@') ;
     attroff (A_UNDERLINE | A_BOLD);
     }

     else {
     	int color = 1;
     	if (map.at(i).at(j) == WALL) 
     	color = 5;
     	else if (map.at(i).at(j) == BDOOR)
     	color = 2;
 	 	else if (map.at(i).at(j) == GDOOR)
     	color = 7;
	 	else if (map.at(i).at(j) == YDOOR)
     	color = 4;
     	else if (map.at(i).at(j) == YOU)
     	color = 3;
     	else if (map.at(i).at(j) == BKEY)
     	color = 2;
     	else if (map.at(i).at(j) == NPC)
     	color = 4;
     	else if (map.at(i).at(j) == INMATE)
     	color = 3;
     	else if (map.at(i).at(j) == GUARD)
     	color = 5;

     	attron(COLOR_PAIR(color));
     	mvaddch(i-start_y, j-start_x, map.at(i).at(j));
     	attroff(COLOR_PAIR(color));
     }
}
}
}


char objectLocation(int x, int y) {
	return map.at(y).at(x);
	}

void changeObject(int x, int y, char object) {
	map.at(y).at(x) = object;

}
//Checks for doors, prevents players from moving past doors
bool isDoor(int x, int y) {
    return map.at(y).at(x) == BDOOR ||
		map.at(y).at(x) == GDOOR ||
		map.at(y).at(x) == YDOOR;
    }

//Check for Inmates, prevents player from interacting with non NPC Inmates
bool isInmate(int x, int y) { 
    return map.at(y).at(x) == INMATE;
	}
//Checks if player touches NPC
bool isNPC(int x, int y) { 
    return map.at(y).at(x) == NPC;
	}
//Check for walls, prevents player from moving past wall
bool hasWall(int x, int y) { 
    return map.at(y).at(x) == WALL;
	}

//Checks if player touches a key
bool isKey(int x, int y, char keyColor) {
	return map.at(y).at(x) == keyColor;
}

void removeMap() {
	map.clear();

}

void refreshMap() {
	refresh();
}



Map() {
init_map();
}
};
