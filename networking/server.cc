#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
//#include <unistd.h>
//#include <boost/bind/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>
#include <thread>
#include <vector>

using namespace std;
using boost::asio::ip::tcp;

string daytime_string() {
	time_t now = time(0);
	return ctime(&now);
}

//make a funtion that will handle the clients
void handle_client(tcp::iostream& stream){
	try{
		while(true){
			//this pushed to the client screen
			stream << "server" << endl;
			string s;
			stream >> s;
			if (!stream) 
		//break;
				cout<<"error"<<endl;
			cout << "server: " << s << endl;
			usleep(333'333);
		}
	}
	catch(exception& e){
		cerr<<e.what()<<endl;}
}


int main(){
	try {
		boost::asio::io_context io_context;
		tcp::endpoint endpoint(tcp::v4(), 2101); //Change this port to whatever you want
		tcp::acceptor acceptor(io_context, endpoint);
while(true){
		tcp::iostream stream;
		boost::system::error_code error;
		
cout << "Waiting for the connection with the client"<<endl;
		acceptor.accept(stream.socket(), error);

		if (!error) {
		//	while (true) {
				cout << "client connect!!!"<<endl;
				thread(handle_client,std::ref(stream)).detach();
		//	}
		} else {
			cout << "nope, this connect did not work: \n";
		}}
	//	io_context.run();
	} catch (exception& e) {
		cerr << e.what() << endl;
	}
return 0;
}

