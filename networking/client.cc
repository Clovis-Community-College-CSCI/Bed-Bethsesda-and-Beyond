#include <cstdlib>
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
			string  s;
			stream>>s;
			if(!stream) break;
			cout<<"client said: "<<s<<endl;
			stream<<"hey its me, the client!"<<endl;
		}
	}
	catch(exception& e){
		cout<<"exception:"<<e.what()<<endl;}
}
