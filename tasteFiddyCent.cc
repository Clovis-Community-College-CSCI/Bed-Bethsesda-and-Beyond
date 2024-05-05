#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <curses.h>
#include "Map.h"
using namespace std;


// NOTE: Alot of test cases are done in NCURSES> I tried my best to do individual test cases for the puzzles

/*
void displayWelcomeMessage() {
	cout << "Welcome!" << endl;
	cout << "You are about to embark on an adventure." << endl;
	cout << "Let's see how your taste testing skills fare in this journey!" endl;
}
*/

//void interactWithMap(Map& gameMap) {

	//gimme a sec

//}

//void playTicTacToe() {


	//thinking

//}

int TicTacToemain();

int main() {
	/*
	displayWelcomeMessage();

	Map gameMap;

	interactWithMap(gameMap);

	playTicTacToe();

	cout << "Thank you for playing!" << endl;
*/
	Map map;
	map.changeObject(15, (Map::SIZE / 2) - 7, Map::YOU);
	map.draw(Map::SIZE / 2, 15);

	if (map.isDoor((Map::SIZE / 2) - 2, 21)) {
		if (map.isKey(15, (Map::SIZE / 2) - 7, Map::BKEY)) {
			map.changeObject((Map::SIZE / 2) - 2, 21, Map::OPEN);
		} else {
			cout << "You need a key to open this door!" << endl;
		}
	} else {
		cout << "No door found at this location." << endl;
	}
	map.draw(Map::SIZE / 2, 15);

	cout << "Test Case 2: Tic Tac Toe Gameplay" << endl;
	TicTacToemain();

	return 0;
}
