#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <mutex>

using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            cerr << "Usage: client <host> <port>\n";
            return EXIT_FAILURE;
        }

        boost::asio::io_context io_context;
        tcp::iostream stream(argv[1], argv[2]);
        
        if (!stream) {
            cerr << "Failed to connect to server: " << stream.error().message() << endl;
            return EXIT_FAILURE;
        }

        cout << "Connected to server" << endl;
        
        thread([&stream] {
            string message;
            while (getline(stream, message)) {
                cout << "Server: " << message << endl;
            }
        }).detach();

        string input;
        while (getline(cin, input)) {
            stream << input << endl;
            if (!stream) {
                cerr << "Error sending message to server" << endl;
                break;
            }
        }

    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return 0;
}




/*#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <mutex>

using namespace std;
using boost::asio::ip::tcp;


int main(int arg, char * argv[]){
	try{
		tcp::iostream stream("localhost","2101");
		if(!stream){
			cout<<"Aye bruh this connection no bueno: "<<stream.error().message()<<endl;
			return EXIT_FAILURE;
		}
		while(true){
			string  input;
//			cin<<input;
			stream>>input;

			if(!stream) break;
			cout<<"server said: "<<input<<endl;
			stream<<"hey its me, the client!"<<endl;
		}
	}
	catch(exception& e){
		cout<<"exception:"<<e.what()<<endl;}
}
*/
