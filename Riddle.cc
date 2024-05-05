#include "/public/read.h"

using namespace std;

int main() {

	string x;
	bool win = false

	cout << "Without a key, I hold people tight, A place to stay for those who fight. My walls are high, my gates are strong, I keep the guilty in for long. What am I." << endl;
	cout << endl;
	cin >> x;
	if (x == "jail" || x == "prison") {
		cout << "Correct heres a electricians manual" << endl;
		win == true;
		return 0;
	}
	else {
		cout << "WRONG now go away" << endl;
		return 0;
	}


}
