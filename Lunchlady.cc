#include "/public/read.h"
#include <chrono>
#include <thread>

using namespace std;

void wait() {
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << endl;

}

int main(){

	int x = 0;
	int y = 0;
	int z = 0;

	cout << "I'm Margret the lunch lady" << endl;
	wait();
	while (x != 4){
		cout << endl;
		cout << "What do you want." << endl;
		wait();
		cout << "1.Have you heard of any rumors lately?" << endl;
		cout << "2.What are you serving today?" << endl;
		cout << "3.Gnershk?" << endl;
		cout << "4.Nevermind" << endl;
		cout << endl;
		cin >> x;
		if (x == 1) {
			cout << "You said what?" << endl;
			wait();
			cout << endl;
			cout << "1.PLANKA!!" << endl;
			cout << "2.eugh?" << endl;
			cout << "3.Wa Wa." << endl;
			cout << "4.Nevermind" << endl;
			cout << endl;

		}
		if (x == 2) {
			cout << "" << endl;

		}

		if (x == 3) {
			cout << "You said what?" << endl;
			wait();
			cout << endl;
			cout << "1.PLANKA!!" << endl;
			cout << "2.eugh?" << endl;
			cout << "3.Wa Wa." << endl;
			cout << "4.Nevermind" << endl;

		}

		if (x == 4) {
			cout << "See ya later sweetie" << endl;
			wait();
			return 0;

		}
	}


	return 0;
}
