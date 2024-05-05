// Noah Brandis Lock Puzzle
// Compile with g++ -lncurses 
//Password is 9 2 5 (Workin nine to five)

#include <iostream>
#include <ncurses.h>
using namespace std;

void exit() {
	endwin();
	//cout << "Exiting..." << endl;
	printw("Exiting...\n");
	exit(1);
}

int LockMain() {
	initscr(); // Initialize ncurses
	keypad(stdscr, TRUE); // Enable keypad

	int digit1 = 0, digit2 = 0, digit3 = 0;
	int currentDigit = 1; // To keep track of the currently selected digit (1, 2, or 3)
	int input;

	while (true) {
		clear(); // Clear the screen

		// Display the padlock
		printw("-----------\n");
		printw("| Padlock |\n");
		//if (digit1 == 9 && digit2 == 2 && digit3 == 5)  printw("|          \n");
		printw("-----------\n");
		printw(" %s%d", (currentDigit == 1 ? ">" : " "), digit1);
		printw(" %s%d ", (currentDigit == 2 ? ">" : " "), digit2);
		printw("%s%d", (currentDigit == 3 ? ">" : " "), digit3);
		printw("\n");
		printw("-----------\n");

		// Get user input
		input = getch();

		// Process user input
		switch (input) {
			case KEY_UP:
				if (currentDigit == 1)
					digit1 = (digit1 + 1) % 10;
				else if (currentDigit == 2)
					digit2 = (digit2 + 1) % 10;
				else
					digit3 = (digit3 + 1) % 10;
				break;
			case KEY_DOWN:
				if (currentDigit == 1)
					digit1 = (digit1 + 9) % 10;
				else if (currentDigit == 2)
					digit2 = (digit2 + 9) % 10;
				else
					digit3 = (digit3 + 9) % 10;
				break;
			case KEY_LEFT:
				if (currentDigit > 1) currentDigit--;
				break;
			case KEY_RIGHT:
				if (currentDigit < 3) currentDigit++;
				break;
			case 'q': exit();
			case 'Q': exit();
			case 10: // Enter key
				if (digit1 == 9 && digit2 == 2 && digit3 == 5) {
					printw("The padlock opens!\n");
					printw("Exiting...\n");
					refresh();
					getch(); // Wait for a key press
					//endwin(); // End ncurses mode
					//return 0;
					exit();
				} else {
					printw("Incorrect combination.\n");
					refresh();
					getch(); // Wait for a key press
				}
				break;
		}
	}

	endwin(); // End ncurses mode
	return 0;
}
