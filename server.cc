#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <unistd.h>

using namespace std;
using boost::asio::ip::tcp;

string make_daytime_strong(){
using namespace std;
	time_t now = time (0);
return ctime(&now);
}
int main(){
	try {
boost::asio::io_context io_context;
    tcp::endpoint endpoint(tcp::v4(), 2101); //Change this port to whatever you want
    tcp::acceptor acceptor(io_context, endpoint);
    tcp::iostream stream;
    boost::system::error_code ec;
    cout << "Waiting for the connection with the client, such a nice day to go for a walk"<<endl;
    acceptor.accept(stream.socket(), ec);
    cout << "Godot has arrived"<<endl;

    if (!ec) {
        while (true) {
            stream << "Ping!" << endl;
            string s;
            stream >> s;
            if (!stream) break;
            cout << "Read: " << s << endl;
            usleep(333'333);
        }
    } else {
        cout << "Sadge.\n";
    }
} catch (exception& e) {
    cerr << e.what() << endl;
}

}
