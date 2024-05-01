#pragma once
#include <curses.h>
#include<vector>
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

static const char HERO = 'H';
static const char MONSTER = 'M'; 
static const char WALL = '#';
static const char WATER = '~';
static const char OPEN = '.';
static const char SHOP = 'S';
static const char TREASURE = 'T';
static const size_t SIZE = 100;
static const size_t DISPLAY = 30;
//Random map
void init_map() {
uniform_int_distribution<int>d100(1,100);
map.clear();
map.resize(SIZE); 
for (auto &v : map) v.resize(SIZE, '.'); //100 columns wide

for (size_t i =0; i < SIZE; i++) {
     for (size_t j=0; j< SIZE; j++) {
     if ( i == 0 or j == 0 or i == SIZE-1 or j == SIZE-1) 
     map.at(i).at(j) = WALL;
     else if (i == SIZE/2 and j == SIZE/2)
     map.at(i).at(j) = HERO;
     else {
     if (d100(gen) <= 7) {
     map.at(i).at(j) = MONSTER;
     }
     else if (d100(gen) <= 5) {
     map.at(i).at(j) = TREASURE;
     }
     else if (d100(gen) <= 3) {
     map.at(i).at(j) = SHOP;
     }
     else if (d100(gen) <=10) {
     map.at(i).at(j) = WALL;
     }
     else if (d100(gen) <= 3) {
     map.at(i).at(j) = WATER;
     }
     else if (d100(gen) <= 40) {
     if (map.at(i-1).at(j) == WATER or map.at(i+1) .at(j) == WATER or map.at(i).at(j-1) == WATER or map.at(i).at(j+1) == WATER)
     map.at(i).at(j) = WATER;
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
     mvaddch(i-start_y, j-start_x, 'H') ;
     attroff (A_UNDERLINE | A_BOLD);
     }
     else {
     int color = 1;
     if (map.at(i).at(j) == WALL) 
     color = 5;
     else if (map.at(i).at(j) == WATER)
     color = 2;
     else if (map.at(i).at(j) == HERO)
     color = 3;
     else if (map.at(i).at(j) == TREASURE)
     color = 4;
     else if (map.at(i).at(j) == MONSTER)
     color = 6;
     else if (map.at(i).at(j) == SHOP)
     color =7;

     attron(COLOR_PAIR(color));
     mvaddch(i-start_y, j-start_x, map.at(i).at(j));
     attroff(COLOR_PAIR(color));
     }
}
}
}
bool hasWater(int x, int y) {
    return map.at(y).at(x) == WATER;
    }

bool hasWall(int x, int y) {
    return map.at(y).at(x) == WALL;}
Map() {
init_map();
}
};
