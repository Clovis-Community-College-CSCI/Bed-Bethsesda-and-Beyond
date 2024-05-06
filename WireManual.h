#include <string>
#include <iostream>
using namespace std;

int ManualMain() {
	cout << "WIRE MANUAL (q to exit)" << endl;
	cout << "If there are 3 yellow wires, cut the wire in the 10th position." << endl;
	cout << "If there are 3 red wires, cut the first red wire." << endl; 
	cout << "If the total number of blue wires is even, cut the last blue wire." << endl;
	cout << "Always cut the first green wire. Unless there is 3 or more green wires, then cut none of them." << endl; 
	cout << "If there are less than 3 yellow wires, cut the wire in the 3rd position. " << endl;//X 
	cout << "If there is 1 yellow wire, cut every green wire." << endl; //X
	cout << "If the total number of red wires is odd, cut the wire in the 5th position." << endl;
	cout << "If there is a red wire in the 3rd position, cut the wire in the 1st position." << endl;// X
	cout << "If there is 1 blue wire total, cut it. " << endl;//X
	cout << "If all of the blue and green wires on the board are cut, cut the wire in the 1st position." << endl;
	cout << "If all of the red wires on the board are cut, cut all wires on the board. " << endl;//X
	cout << "If all yellow wires on the board are uncut, cut the first green wire." << endl; //X

	while (true) {
		try {
			string Input;
			cin >> Input;
			if (Input == "Q" or Input == "q") {
				cout << "Exiting..." << endl;
				return 0;
			}


		} catch(...) {
			cout << "Invalid input. Try again." << endl;
		}
	}
}

//Answer: 1 2 5 6 8 10
