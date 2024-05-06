#include "/public/read.h"
#include "unistd.h"
#include <thread>
#include <chrono>

using namespace std;

void wait() {
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << endl;

}

bool riddleWin = false;

int riddleMain() {

	string y;
	string x;


	cout << "Yo I'm Bencarelli, whats your name" << endl;
	cin >> y;
	wait();
	cout << "Yeah I don't care" << endl;
	wait();
	cout << "now solve this riddle" << endl;
	cout << endl;
	wait();

	cout << "Without a key, I hold people tight, A place to stay for those who fight. My walls are high, my gates are strong, I keep the guilty in for long. What am I." << endl;
	cout << endl;
	cin >> x;
	if (x == "jail" || x == "prison" || x == "Prison" || x == "Jail") {
		cout << "Correct, here take this Note!" << endl;
		riddleWin = true;
		sleep(3);
		return 0;
	}
	else {
		cout << "WRONG now go away" << endl;
		sleep(2);
		return 0;
	}


}
