// Noah Brandis
// Role: ISAD
// Puzzles
#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define WireFull "———————"
#define WireCut  "——< >——"

bool Wire1, Wire2, Wire3, Wire4, Wire5, Wire6, Wire7, Wire8, Wire9, Wire10 = false; // False if uncut, True if cut

void DisplayBoard() {
	// Outputs the Board
	// If Wire = false, cout Uncut wire
	// If Wire = true, cout Cut wire
	cout << "  ┌" << RESET << WireFull << "┐" << endl;
	cout << "  │○     ○│" << endl;
	if (Wire1 == false) cout << "1 │" << YELLOW << WireFull << RESET << "│" << endl;
	if (Wire1 == true) cout << "1 │" << YELLOW << WireCut << RESET << "│" << endl;
	if (Wire2 == false) cout << "2 │" << RED << WireFull << RESET << "│" << endl;
	if (Wire2 == true) cout << "2 │" << RED << WireCut << RESET << "│" << endl;
	if (Wire3 == false) cout << "3 │" << YELLOW << WireFull << RESET << "│" << endl;
	if (Wire3 == true) cout << "3 │" << YELLOW << WireCut << RESET << "│" << endl;
	if (Wire4 == false) cout << "4 │" << RED << WireFull << RESET << "│" << endl;
	if (Wire4 == true) cout << "4 │" << RED << WireCut << RESET << "│" << endl;
	if (Wire5 == false) cout << "5 │" << CYAN << WireFull << RESET << "│" << endl;
	if (Wire5 == true) cout << "5 │" << CYAN << WireCut << RESET << "│" << endl;
	if (Wire6 == false) cout << "6 │" << GREEN << WireFull << RESET << "│" << endl;
	if (Wire6 == true) cout << "6 │" << GREEN << WireCut << RESET << "│" << endl;
	if (Wire7 == false) cout << "7 │" << RED << WireFull << RESET << "│" << endl;
	if (Wire7 == true) cout << "7 │" << RED << WireCut << RESET << "│" << endl;
	if (Wire8 == false) cout << "8 │" << CYAN << WireFull << RESET << "│" << endl;
	if (Wire8 == true) cout << "8 │" << CYAN << WireCut << RESET << "│" << endl;
	if (Wire9 == false) cout << "9 │" << YELLOW << WireFull << RESET << "│" << endl;
	if (Wire9 == true) cout << "9 │" << YELLOW << WireCut << RESET << "│" << endl;
	if (Wire10 == false) cout << "10│" << GREEN << WireFull << RESET << "│" << endl;
	if (Wire10 == true) cout << "10│" << GREEN << WireCut << RESET << "│" << endl;
	cout << "  │○     ○│" << endl;
	cout << "  └" << RESET << WireFull << "┘" << endl;
}

void Dupe() {cout << "You already cut that wire." << endl; } // Quick function for output

bool Complete = false; // Check if the puzzle is completed
bool Failed = false; // Check if puzzle has been failed


int CarMain() {

	// Input Loop
	while (Complete == false and Failed == false) { // Continue puzzle until completed or failed
		while(true) {
			if (Wire1 == true and Wire2 == true and Wire3 == false and Wire4 == false and Wire5 == true and 
				Wire6 == true and Wire7 == false and Wire8 == true and Wire9 == false and Wire10 == true) { // If all of the correct wires are cut
				cout << "You successfully completed the puzzle!" << endl;
				Complete = true;

				return 0;
			}
			if (Wire3 == true or Wire4 == true or Wire7 == true or Wire9 == true) {
				cout << "You cut the wrong wire!" << endl;
				cout << "The car exploded!" << endl;
				cout << "YOU LOSE!" << endl;
				Failed = true;
				break;
			}
			int WireInput = 0;
			DisplayBoard();
			cout << "Which wire would you like to cut? (Enter Q to exit)" << endl;
			try {
				string Input;
				cin >> Input;
				if (Input == "Q" or Input == "q") {
					cout << "Exiting..." << endl;
					return 0;
				}
				WireInput = stoi(Input);
				if (WireInput >= 1 and WireInput <= 10) { // Cut the wire if it is in the correct range
					cout << "You cut Wire " << WireInput << "." << endl;
					// Checks if wire is already cut
					if (WireInput == 1 and Wire1 == true) Dupe(); 
					if (WireInput == 2 and Wire2 == true) Dupe(); 
					if (WireInput == 3 and Wire3 == true) Dupe(); 
					if (WireInput == 4 and Wire4 == true) Dupe(); 
					if (WireInput == 5 and Wire5 == true) Dupe(); 
					if (WireInput == 6 and Wire6 == true) Dupe(); 
					if (WireInput == 7 and Wire7 == true) Dupe(); 
					if (WireInput == 8 and Wire8 == true) Dupe(); 
					if (WireInput == 9 and Wire9 == true) Dupe(); 
					if (WireInput == 10 and Wire10 == true) Dupe(); 
					// Sets wire to cut
					if (WireInput == 1) Wire1 = true; 
					if (WireInput == 2) Wire2 = true; 
					if (WireInput == 3) Wire3 = true; 
					if (WireInput == 4) Wire4 = true; 
					if (WireInput == 5) Wire5 = true; 
					if (WireInput == 6) Wire6 = true; 
					if (WireInput == 7) Wire7 = true; 
					if (WireInput == 8) Wire8 = true; 
					if (WireInput == 9) Wire9 = true; 
					if (WireInput == 10) Wire10 = true;
					break;
				} else {
					cout << "Invalid input. Try again." << endl;
				}
			} catch(...) {
				cout << "Invalid input. Try again." << endl;
			}
		}
	}
}
