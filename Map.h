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
default_random_engine gen;
public:
// Need to write a function to save the map and reload the map, and getter/setter to get and set character in map

static const char YOU = '@';
static const char INMATE = 'O'; 
static const char WALL = '#';
static const char DOOR = '~';
static const char OPEN = '.';
static const char GUARD = 'G';
static const char KEY = 'K';
static const size_t SIZE = 25;
static const size_t DISPLAY = 24;

void init_map() {
    map.clear();
    map.resize(SIZE);
    for (auto &v : map) v.resize(SIZE, '.'); // 100 columns wide

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1)
                map.at(i).at(j) = WALL;
            else if (i == SIZE / 2 && j == SIZE / 2)
                map.at(i).at(j) = YOU;
            else {
                if (i == 10 && j == 10) {       
					map.at(i).at(j) = INMATE;
                } 
				else if (i == 20 && j == 20) { 
                	map.at(i).at(j) = KEY;
                } 
				else if (i == 30 && j == 30) { 
                    map.at(i).at(j) = GUARD;
                } 
				else if (i == 40 && j == 40) { 
                    map.at(i).at(j) = WALL;
                } 
				else if (i == 50 && j == 50) { 
                    map.at(i).at(j) = DOOR;
                } 
				else if (i == 60 && j == 60) { 
                    if (map.at(i - 1).at(j) == DOOR || map.at(i + 1).at(j) == DOOR 
						|| map.at(i).at(j - 1) == DOOR || map.at(i).at(j + 1) == DOOR)
                        map.at(i).at(j) = DOOR;
                }
            }
        }
    }
}

//Drawing display tiles aeound (x,y)

void draw(int x, int y) {
int start_x = x - DISPLAY/2;
int end_x = x + DISPLAY/2;
int start_y = y - DISPLAY/2;
int end_y = y +DISPLAY/2;

//Bounds check for edges of the map

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

for (size_t i = start_y; i <= end_y; i++) {
     for (size_t j = start_x; j <= end_x; j++) {
     if (i == y && j == x) {
     attron(A_UNDERLINE | A_BOLD);
     mvaddch(i-start_y, j-start_x, '@') ;
     attroff (A_UNDERLINE | A_BOLD);
     }
     else {
     int color = 1;
     if (map.at(i).at(j) == WALL) 
     color = 5;
     else if (map.at(i).at(j) == DOOR)
     color = 2;
     else if (map.at(i).at(j) == YOU)
     color = 3;
     else if (map.at(i).at(j) == KEY)
     color = 4;
     else if (map.at(i).at(j) == GUARD)
     color = 6;
     else if (map.at(i).at(j) == GUARD)
     color =7;

     attron(COLOR_PAIR(color));
     mvaddch(i-start_y, j-start_x, map.at(i).at(j));
     attroff(COLOR_PAIR(color));
     }
}
}
}
bool isDoor(int x, int y) {
    return map.at(y).at(x) == DOOR;
    }

bool hasWall(int x, int y) {
    return map.at(y).at(x) == WALL;}
Map() {
init_map();
}
};
