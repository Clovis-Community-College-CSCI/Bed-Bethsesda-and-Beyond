#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <unistd.h>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "../Map.h" // Include the Map class header file

using namespace std;
using boost::asio::ip::tcp;

string daytime_string() {
	time_t now = time(0);
	return ctime(&now);
}




int main(){
	try {
boost::asio::io_context io_context;
	tcp::endpoint endpoint(tcp::v4(), 2101); //Change this port to whatever you want
	tcp::acceptor acceptor(io_context, endpoint);
	tcp::iostream stream;
	boost::system::error_code error;
	cout << "Waiting for the connection with the client"<<endl;
	acceptor.accept(stream.socket(), error);
	cout << "client connect!!!"<<endl;

	if (!error) {
		while (true) {
			stream << "server" << endl;
			string s;
			stream >> s;
			if (!stream) break;
			cout << "server: " << s << endl;
			usleep(333'333);
		}
	} else {
		cout << "Sadge.\n";
	}
} catch (exception& e) {
	cerr << e.what() << endl;
}

}

