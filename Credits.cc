#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void Wait() {
	this_thread::sleep_for(chrono::milliseconds(500)); 
	cout << endl;

}

void Break() {
	for (int i = 0; i < 4; i++ ) cout << endl;
}
int main() {

for (int i = 0; i < 2; i++) Wait();
cout << "    _    _     ____    _  _____ ____      _     _____     _  _   _ " << endl;
cout << "   / \\  | |   / ___|  / \\|_   _|  _ \\    / \\   |__  /    | || | / |" << endl;
cout << "  / _ \\ | |  | |     / _ \\ | | | |_) |  / _ \\    / /_____| || |_| |" << endl;
cout << " / ___ \\| |__| |___ / ___ \\| | |  _ <  / ___ \\  / /|_____|__   _| |" << endl;
cout << "/_/   \\_\\_____\\____/_/   \\_\\_| |_| \\_\\/_/   \\_\\/____|       |_| |_|" << endl;

Break();

for (int i = 0; i < 5; i++) Wait();
cout << "\t\t        You escaped the prison!" << endl;
Wait();
Wait();
cout << "\t  You put your aquatic training and swam to shore. " << endl;
Wait();
Wait();
cout << "  You life the rest of your life undercover enjoying your freedom. " << endl;
Wait();
Wait();
for (int i = 0; i < 5; i++) Wait();

Break();

/*
cout << "A long time ago in a college far far away... " << endl;
cout << "It was a sad day. You were drunk driving home..." << endl;
cout << "A dog runs into the road.. You swereve out of the way and crash into a sign." << endl;
cout << "The sign falls onto the road and decimates a family of 4. "<< endl;
cout << "The sign causes an earthquake to destroy the white house and kill the president." << endl;
cout << "You have been thrown in Jail." << endl;
*/
cout << "\033[1m" << "\t\t               ROLES " << "\033[0m" <<endl;
Wait();
Wait();
cout << "\t\tProject Leader: Moehammed Moehammed" << endl;
Wait();
cout << "\t\t   JJK Curse Lord: Michael Moran " << endl;
Wait();
cout << "\t\t      Thread Lord: Kevin Viale " << endl;
Wait();
cout << "\t\t          DJ Bridges: None " << endl;
Wait();
cout << "\t      Inheritor of Suffering: Jerrick Wallace " << endl;
Wait();
cout << "\t\t     Socketroth: Jose Santiago " << endl;
Wait();
cout << "\t\t  Taste Tester: Stevie Sartarelli " << endl;
Wait();
cout << "\t\t         ISAD: Noah Brandis" << endl;
Wait();
cout << "\t\t         Screenwriter: None " << endl;
Wait();
cout << "\t\t        Ghost: Sandra Romero" << endl;
Wait();
Wait();
cout << "\033[1m" << "\t\t          Special Thanks " << "\033[0m" <<endl;
Wait();
Wait();
cout << "\t\t         Justis Mencarelli " << endl;
Wait();
cout << "\t\t          Julian Laxamana " << endl;
Wait();
cout << "\t\t                YOU!        " << endl;
Wait();
Wait();

cout << "\033[1m" << "\t\t         THANKS FOR PLAYING!" << "\033[0m" << endl;
for (int i = 0; i < 20; i++) Wait();


                                                                   


}
