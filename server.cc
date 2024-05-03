#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <unistd.h>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;
using boost::asio::ip::tcp;
string daytime_string(){
time_t now = time(0);
	return ctime(&now);
}
/*
class connection
  : public boost::enable_shared_from_this<connection>
{
public:
  typedef boost::shared_ptr<connection> pointer;

  static pointer create(boost::asio::io_context& io_context)
  {
    return pointer(new connection(io_context));
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    message_ = daytime_string();

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
        boost::bind(&connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

private:
  connection(boost::asio::io_context& io_context)
    : socket_(io_context)
  {
  }

  void handle_write(const boost::system::error_code& ,
      size_t )
  {
  }

  tcp::socket socket_;
  std::string message_;
};

*/
//ill make a class named server
//ill be using a tcp server
/*
class server{
private:
	void accept_client(){
connection::pointer new_connection =
      connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&server::accept_client, this, new_connection,
          boost::asio::placeholders::error));
	}

void accept(connection::pointer new_connection, const boost::system::error_code& error){

if (!error)
    {
      new_connection->start();
    }

    accept_client();
	}
  boost::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
public:
server(boost::asio::io_context& io_context)
    : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
  {
    accept_client();
  }
};*/

/*
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

}*/
