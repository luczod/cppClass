### Chapter 20: NETWORK PROGRAMMING WITH BOOST ASIO

Boost Asio defines a single service object, boost::asio::io_context. Its constructor takes an optional integer argument called the concurrency hint, which is the number of threads the io_context should allow to run **concurrently**.

When you pair a device’s IP address with a port number, the result is called a **socket**.

A Buffer (or data buffer) is memory that stores transient data. The Boost Asio buffer classes form the interface for all I/O operations. Before you can do anything with the network connections you make, you’ll need **an interface for reading and writing data**.

#### Contents

- asio: A program using boost::asio::steady_timer for synchronous and asynchronous waiting
- name_resolution: Blocking hostname resolution with Boost Asio
- name_resolution_async: Refactoring name_resolution to use async_resolve
- connect: Connecting to the No Starch web server
- connect_async: Connecting to the No Starch web server asynchronously
- buffers: Default constructing const_buffer and mutable_buffer yields empty buffers.
- web_request: Completing a simple request to the United States Army Cyber Command web server
- web_request_async: An asynchronous refactor of web_request
- upper_echo_server: An uppercasing echo server
- upper_echo_server_async: An asynchronous version of upper_echo_server
- upper_echo_server_multi: Multithreading your asynchronous echo server
- web_request_async_multi: Multithreading your web_request
