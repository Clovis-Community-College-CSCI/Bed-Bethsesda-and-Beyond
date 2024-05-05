#include "/public/read.h"

using namespace std;

int main() {

	string y;
	string x;
	bool win = false;

	cout << "Yo I'm Bencarelli, whats your name" << endl;
	cin >> y;
	cout << "Yeah I don't care" << endl;
	cout << "now solve this riddle" << endl;
	cout << endl;

	cout << "Without a key, I hold people tight, A place to stay for those who fight. My walls are high, my gates are strong, I keep the guilty in for long. What am I." << endl;
	cout << endl;
	cin >> x;
	if (x == "jail" || x == "prison" || x == "Prison" || x == "Jail") {
		cout << "Correct, here take this electricians manual" << endl;
		win = true;
		return 0;
	}
	else {
		cout << "WRONG now go away" << endl;
		return 0;
	}


}
