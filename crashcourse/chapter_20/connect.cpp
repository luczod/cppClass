// Listing 20-4: Connecting to the No Starch web server
#include <boost/asio.hpp>
#include <iostream>

int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context }; // 1
  boost::asio::ip::tcp::socket socket{ io_context }; // 2

  try {
    auto endpoints = resolver.resolve("www.nostarch.com", "http"); // 3
    const auto connected_endpoint = boost::asio::connect(socket, endpoints); // 4
    std::cout << connected_endpoint; // 5
  } catch(boost::system::system_error& se) {
    std::cerr << "Error: " << se.what() << std::endl; // 6
  }
}
