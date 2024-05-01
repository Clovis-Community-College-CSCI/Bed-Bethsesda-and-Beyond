#include "Map.h"
#include <unistd.h>
const int MAX_FPS = 90;
const unsigned int TIMEOUT = 10;
const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;


void turn_on_ncurses() {
    initscr(); 
    start_color();
init_pair(1, COLOR_WHITE, COLOR_BLACK);
init_pair(2, COLOR_CYAN, COLOR_BLACK);
init_pair(3, COLOR_BLUE, COLOR_BLACK);
init_pair(4, COLOR_YELLOW, COLOR_BLACK);
init_pair(5, COLOR_RED, COLOR_BLACK);
init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
init_pair(7, COLOR_GREEN, COLOR_BLACK);
clear();
noecho();
cbreak();
timeout(TIMEOUT);
}

void turn_off_ncurses() {
    clear();
endwin();
if (system("clear")) {}
}

int main() {
    int x,y;
printf("Hello World! X: %i Y: %i\n", x, y);

turn_on_ncurses();
Map map;
 x = Map :: SIZE /2, y = Map:: SIZE / 2;//Start in middle of the world
    int old_x = -1, old_y = -1;
while (true) {
int ch = getch(); //Wait for the user to input and has TIMEOUT delay
if (ch == 'q' or ch == 'Q') break;
else if (ch == RIGHT){
if (!map.hasWater(x+1, y) and  !map.hasWall(x+1,y)){
x++;
if (x>= Map :: SIZE) x = Map :: SIZE -1;
} }
else if (ch == LEFT) {
    if (!map.hasWater(x-1, y) and  !map.hasWall(x-1, y)) {
x--;
if ( x < 0) x = 0;}
} else if (ch == UP) {
    if(!map.hasWater(x, y-1) and !map.hasWall(x, y-1)) {
y--;
if (y <0) y = 0;
}}
else if (ch == DOWN) {
    if(!map.hasWater(x, y+1) and !map.hasWall(x,y+1) ){
y++;
if (y >= Map :: SIZE) y= Map :: SIZE -1;
}}
else if (ch == ERR) {
;
    }
if (x != old_x or y != old_y) { // Stop flickering by only redrawing on a change
/* still need to make changes
if (map.get(x,y) == Map :: TREASURE) {
map.set(x,y, Map :: OPEN) ;
money++;
    } ellse if (map.get(x,y) == Map :: WALL) {
x = old_x;
y = old_y;
    }
*/
map.draw(x,y);
mvprintw(Map :: DISPLAY+1,0, "X: %i Y: %i\n", x,y);
refresh();
    }
old_x = x;
old_y = y;
usleep(1'000'000/MAX_FPS);
}
turn_off_ncurses();
}

