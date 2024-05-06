#include "/public/read.h"
#include <chrono>
#include <thread>

using namespace std;

void wait1() {
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << endl;

}

int Lunchmain(){

	int x = 0;
	int y = 0;
	int z = 0;

	cout << "I'm Margret the lunch lady" << endl;
	wait1();
	while (x != 4){
		cout << endl;
		cout << "What do you want." << endl;
		wait1();
		cout << "1. Have you heard of any rumors lately?" << endl;
		cout << "2. What are you serving today?" << endl;
		cout << "3. Gnershk?" << endl;
		cout << "4. Goodbye!" << endl;
		cout << endl;
		cin >> x;
		if (x == 1) {
			//cout << "You said what?" << endl;
			wait1();
			cout << endl;
			cout << "1. About the warden?" << endl;
			cout << "2. About Bencarelli?" << endl;
			cout << "3. About Alcatraz?" << endl;
			cout << "4. Nevermind" << endl;
			cout << endl;
			wait1();
			int Input = 0;
			cin >> Input;
			//while (Input != 4) {
				if (Input == 1) {
					cout << "He didnt used to be bald..." << endl;
					cout << "Luscious long locks down to his shoulders. . . " << endl;
					wait1();
					cout << "I mean what ? " << endl;
					wait1();
					Input = 4;
				}
				if (Input == 2) {
					cout << "Heard he's an aspriring streamer. a2bird or something ?" << endl;
					cout << "He's been into writing riddles lately, no idea why " << endl;
					wait1();
					Input = 4;
			}
				if (Input == 3) {
					cout << "This place was built over 400 years ago. For prisoners from the coding revolution" << endl;
					wait1();
					Input = 4;
				}
				if (Input == 4) {
					wait1();
					wait1();
					return 0;
				}
			//}

		}
		if (x == 2) {
			cout << endl;
			cout << "SLOP !" << endl;
			cout << "And 1 raisin cookie." << endl;
			wait1();

		}

		if (x == 3) {
			cout << "You said what?" << endl;
			wait1();
			//cout << endl;
			//cout << "1.PLANKA!!" << endl;
			//cout << "2.eugh?" << endl;
			//cout << "3.Wa Wa." << endl;
			//cout << "4.Nevermind" << endl;

		}

		if (x == 4) {
			cout << "See ya later sweetie" << endl;
			wait1();
			return 0;

		}
	}


	return 0;
}
