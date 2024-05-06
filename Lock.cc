#include "/public/read.h"
#include <thread>
#include <chrono>

using namespace std;

bool lockWin = false;

void L(int x,int xa,int xb,int y,int ya,int yb,int z,int za,int zb) {
	cout << " ___________" << endl;
	cout << "│           │" << endl;
	cout << "│  PadLock  │" << endl;
	cout << "│___________│" << endl;
	cout << "│           │" << endl;
	cout << "│   " << xa << "|" << ya << "|" << za << "   │" << endl;
	cout << "│-----------│" << endl;
	cout << "│-> " << x << "|" << y << "|" << z << " <-│" << endl;
	cout << "│-----------│" << endl;
	cout << "│   " << xb << "|" << yb << "|" << zb << "   │" << endl;
	cout << "│___________│" << endl;
	cout << endl;
}

void wait(int x) {
	this_thread::sleep_for(chrono::milliseconds(x));
}

bool isnum (const string &str) {
	for (char c : str) {
		if (!isdigit(c) || c == '0') {
			return false;
		}
	}
	return true;

}

int LockMain() {

	string code;
	int xb = 5, yb = 8, zb = 2;
	int x = 4, y = 7, z = 1;
	int xa = 3, ya = 6, za = 9;
	int time = 0;
	int w = 0;


	L(x, xa, xb, y, ya, yb, z, za, zb);

	while (true) {
		cout << "Enter a 3 digit code (1-9) or 'q' to exit." << endl;
		cout << endl;
		cin >> code;
		cout << endl;
		wait(time = 1000);
		
		if (code[0] == 'q' && code.length() == 1) {
			cout << "Goodbye!" << endl;
			wait(time = 2000);
			return 0;
		}
		else if (code.size() != 3 || isnum(code) == false) {
			cout << "That doesn't work for a 3 digit lock silly." << endl;
			wait(time = 2000);
			w = 1;
		}
		else {
			char x1 = code[0];
			char y1 = code[1];
			char z1 = code[2];
			x = x1 - '0';
			y = y1 - '0';
			z = z1 - '0';

			if (x == 9) { xa = 1; }
			else { xa = x + 1; }

			if (y == 9) { ya = 1; }
			else { ya = y + 1; }

			if (z == 9) { za = 1; }
			else { za = z + 1; }

			if (x == 1) { xa = 1; }
			else { xb = x - 1; }

			if (y == 1) { ya = 1; }
			else { yb = y - 1; }

			if (z == 1) { za = 1; }
			else { zb = z - 1; }
		}

		L(x, xa, xb, y, ya, yb, z, za, zb);

		if (x == 9 && y == 2 && z == 5){
			cout << "That's correct!!" << endl;
			cout << endl;
			wait(time = 2000);
			cout << "Woohoo!" << endl;
			wait(time = 1000);
			lockWin = true;
			return 0;
		}
		if (x != 9 || y != 2 || z != 5) {
			if (w == 1) {
				cout << "Try Again" << endl;
				cout << endl;
				w = 0;
			}
			else {
				cout << "WRONG" << endl;
				cout << endl;
			}
		}
	}

	return 0;
}
