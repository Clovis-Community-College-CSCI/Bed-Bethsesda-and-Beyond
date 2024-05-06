#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void IntroWait() {
	this_thread::sleep_for(chrono::milliseconds(500)); 
	cout << endl;

}

void IntroBreak() {
	for (int i = 0; i < 5; i++ ) cout << endl;
}
int IntroMain() {

for (int i = 0; i < 3; i++) IntroWait();
cout << "    _    _     ____    _  _____ ____      _     _____     _  _   _ " << endl;
cout << "   / \\  | |   / ___|  / \\|_   _|  _ \\    / \\   |__  /    | || | / |" << endl;
cout << "  / _ \\ | |  | |     / _ \\ | | | |_) |  / _ \\    / /_____| || |_| |" << endl;
cout << " / ___ \\| |__| |___ / ___ \\| | |  _ <  / ___ \\  / /|_____|__   _| |" << endl;
cout << "/_/   \\_\\_____\\____/_/   \\_\\_| |_| \\_\\/_/   \\_\\/____|       |_| |_|" << endl;

IntroBreak();

for (int i = 0; i < 3; i++) IntroWait();

/*
cout << "A long time ago in a college far far away... " << endl;
cout << "It was a sad day. You were drunk driving home..." << endl;
cout << "A dog runs into the road.. You swereve out of the way and crash into a sign." << endl;
cout << "The sign falls onto the road and decimates a family of 4. "<< endl;
cout << "The sign causes an earthquake to destroy the white house and kill the president." << endl;
cout << "You have been thrown in Jail." << endl;
*/
//cout << " " << endl;
cout << "\t          You have one job. Escape." << endl;
IntroWait();
cout << "\t  They took away your freedom. GET IT BACK" << endl;
IntroWait();
cout << "\t\t\t Good luck." << endl;

for (int i = 0; i < 10; i++) IntroWait();
return 0;


                                                                   


}
