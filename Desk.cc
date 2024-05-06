#include "/public/read.h"
#include "unistd.h"

using namespace std;

bool deskWin = false;

void desk() {
	cout << " __________________________________________________________________________" << endl;
	cout << "│  ______________      ______________________________      ______________  │" << endl;
	cout << "│ │1             │    │2                             │    │3             │ │" << endl;
	cout << "│ │              │    │                              │    │              │ │" << endl;
	cout << "│ │     {__}     │    │             {__}             │    │     {__}     │ │" << endl;
	cout << "│ │              │    │______________________________│    │              │ │" << endl;
	cout << "│ │______________│                                        │______________│ │" << endl;
	cout << "│  ________________________   ________________   ________________________  │" << endl;
	cout << "│ │4                       │ │                │ │5                       │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │          {__}          │ │                │ │          {__}          │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │                        │ │                │ │                        │ │" << endl;
	cout << "│ │________________________│ │                │ │________________________│ │" << endl;
	cout << "│____________________________│                │____________________________│" << endl;
}

int deskMain() {

	int chances = 3;
	int drawer = 0;
	char x;

	desk();
	cout << endl;
	cout << "Choose a Drawer" << endl;
	while (chances != 0 || drawer == 3 || deskWin == false) {
		cin >> drawer;
		cout << endl;

		if (drawer == 1){
			while (x != 'q') {
				cout << "You see" << endl;
				cout << endl;
				cout << "1.Pen" << endl;
				cout << "2.Toy Car" << endl;
				cout << "3.Magazine" << endl;
				cout << "4.Family Photo" << endl;
				cout << endl;
				cout << "Choose 1-4 or enter q to go back" << endl;
				cout << endl;
				cin >> x;
				if (x == '1'){
					cout << endl;
					cout << "Looks expensive." << endl;
					cout << endl;
				}
				if (x == '2'){
					cout << endl;
					cout << "Kachow" << endl;
					cout << endl;
				}
				if (x == '3'){
					cout << endl;
					cout << "Its filled with models. Its sticky :(" << endl;
					cout << endl;
				}
				if (x == '4'){
					cout << endl;
					cout << "A father, mother, son, and daughter." << endl;
					cout << endl;
				}
				if (x == 'q'){
					cout << endl;
					cout << " " << endl;
				}
			}
			x = '0';
		} else
		if (drawer == 2){
			while (x != 'q') {
				cout << "You see" << endl;
				cout << endl;
				cout << "1.Hair Growth Oil" << endl;
				cout << "2.Book \"How to Grow Hair\"" << endl;
				cout << "3.Book \"Sad and Bald\"" << endl;
				cout << "4.Wardens Old License" << endl;
				cout << endl;
				cout << "Choose 1-4 or enter q to go back" << endl;
				cout << endl;
				cin >> x;
				if (x == '1'){
					cout << endl;
					cout << "Speaks for itself." << endl;
					cout << endl;
				}
				if (x == '2'){
					cout << endl;
					cout << "How to Grow Hair is an essential guide for anyone looking to understand the science behind hair growth and to achieve healthier, stronger, and more vibrant hair. Whether you're struggling with hair loss, seeking to improve the quality of your hair, or simply curious about the factors influencing hair growth, this book provides practical tips, expert advice, and scientific insights to help you on your journey to better hair health." << endl;
					cout << endl;
				}
				if (x == '3'){
					cout << endl;
					cout << "Sad and Bald is a poignant and candid memoir that explores one individual's emotional and physical journey through hair loss. Told with raw honesty and humor, this book delves into the personal struggles, societal pressures, and emotional turmoil experienced by those grappling with hair loss." << endl;
					cout << endl;
				}
				if (x == '4'){
					cout << endl;
					cout << "He used to have hair." << endl;
					cout << endl;
				}
				if (x == 'q'){
					cout << endl;
					cout << " " << endl;
				}
			}
			x = '0';
		} else
		if (drawer == 3){
			while (x != 'q') {
				cout << "You see" << endl;
				cout << endl;
				cout << "1.Marker" << endl;
				cout << "2.Fortune Cookie" << endl;
				cout << "3.Straw" << endl;
				cout << "4.**Strange Book**" << endl;
				cout << endl;
				cout << "Choose 1-4 or enter q to go back" << endl;
				cout << endl;
				cin >> x;
				if (x == '1'){
					cout << endl;
					cout << "Marks things." << endl;
					cout << endl;
				}
				if (x == '2'){
					cout << endl;
					cout << "Serenity is not freedom from the storm, but peace amid the storm." << endl;
					cout << endl;
				}
				if (x == '3'){
					cout << endl;
					cout << "Looks like its from McDonalds." << endl;
					cout << endl;
				}
				if (x == '4'){
					cout << endl;
					cout << "A manual on wire cutting!" << endl;
					cout << endl;
					x = 'q';
					deskWin = true;
				}
				if (x == 'q'){
					cout << endl;
					cout << " " << endl;
				}
			}
			x = '0';
		} else
		if (drawer == 4){
			while (x != 'q') {
				cout << "You see" << endl;
				cout << endl;
				cout << "1.Donut" << endl;
				cout << "2.Beef Jerky" << endl;
				cout << "3.Empty Soda Can" << endl;
				cout << "4.Twinkie" << endl;
				cout << endl;
				cout << "Choose 1-4 or enter q to go back" << endl;
				cout << endl;
				cin >> x;
				if (x == '1'){
					cout << endl;
					cout << "The guards favorite snack." << endl;
					cout << endl;
				}
				if (x == '2'){
					cout << endl;
					cout << "It says 10 grams of protein on it." << endl;
					cout << endl;
				}
				if (x == '3'){
					cout << endl;
					cout << "Who knows how long thats been there for." << endl;
					cout << endl;
				}
				if (x == '4'){
					cout << endl;
					cout << "Makes you fat." << endl;
					cout << endl;
				}
				if (x == 'q'){
					cout << endl;
					cout << " " << endl;
				}
			}
			x = '0';
		} else
		if (drawer == 5){
			while (x != 'q') {
				cout << "You see" << endl;
				cout << endl;
				cout << "1.Inmate Files" << endl;
				cout << "2.Guard Check Book" << endl;
				cout << "3.Lunch Lady's Number" << endl;
				cout << "4.Love Letter From Lunch Lady" << endl;
				cout << endl;
				cout << "Choose 1-4 or enter q to go back" << endl;
				cout << endl;
				cin >> x;
				if (x == '1'){
					cout << endl;
					cout << "You see your file. You're not getting out anytime soon." << endl;
					cout << endl;
				}
				if (x == '2'){
					cout << endl;
					cout << "I wish I could cash all of these out." << endl;
					cout << endl;
				}
				if (x == '3'){
					cout << endl;
					cout << "678-368-7508 DO NOT CALL THIS NUMBER" << endl;
					cout << endl;
				}
				if (x == '4'){
					cout << endl;
					cout << "Its marked with lip stick." << endl;
					cout << endl;
				}
				if (x == 'q'){
					cout << endl;
					cout << " " << endl;
				}
			}
			x = '0';
		}
		else { cout << "You see nothing" << endl;
		}
		if (deskWin == true) {
			cout << "You found what you were looking for!" << endl;
			sleep(3);
			return 0;
		}
		if (chances == 3) {
			cout << "You can hear the guards coming" << endl;
		}
		if (chances == 2) {
			cout << "They are getting closer..." << endl;
		}
		if (chances == 1) {
			cout << "You've Been Caught!" << endl;
			sleep(3);
			break;

		}
		chances--;
	}

return 0;

}
