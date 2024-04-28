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

int main() {
	bool Complete = false; // Check if the puzzle is completed
	bool Failed = false; // Check if puzzle has been failed

	// Outputs the Board
	cout << "  ┌" << RESET << WireFull << "┐" << endl;
	cout << "1 |" << YELLOW << WireFull << RESET << "|" << endl;
	cout << "2 |" << RED << WireFull << RESET << "|" << endl;
	cout << "3 |" << YELLOW << WireFull << RESET << "|" << endl;
	cout << "4 |" << RED << WireFull << RESET << "|" << endl;
	cout << "5 |" << CYAN << WireFull << RESET << "|" << endl;
	cout << "6 |" << GREEN << WireFull << RESET << "|" << endl;
	cout << "7 |" << RED << WireFull << RESET << "|" << endl;
	cout << "8 |" << CYAN << WireFull << RESET << "|" << endl;
	cout << "9 |" << YELLOW << WireFull << RESET << "|" << endl;
	cout << "10|" << GREEN << WireFull << RESET << "|" << endl;
	cout << "  └" << RESET << WireFull << "┘" << endl;

	// Input Loop
	while (Complete == false and Failed == false) {
		while(true) {
		int WireInput = 0;
		cout << "Which wire would you like to cut?" << endl;
		try {
			cin >> WireInput;
			if (WireInput >= 1 and WireInput <= 10) {
				cout << "You entered: " << WireInput << endl;
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
