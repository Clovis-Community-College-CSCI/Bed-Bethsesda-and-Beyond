#include "thread.h"

using namespace std;


int main() {

	jthread t1(&threads::mouser);
	jthread t2(&threads::keyboard_commands);
	jthread t3(&threads::network_commands);
	while (1) {
		//Parsing the commands
		while (tsq.size()) {
			string next_command = tsq.pop();
			cout << "Executing command: " << next_command << endl;
		}
	}
}
