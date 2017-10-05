#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Creates a socket that listens to and accepts connections,
 * and prints one message
 */
int main() {
  int optval = 1; //how many options we will pass to reuseport
  int my_socket = socket(AF_INET, SOCK_STREAM, 0);

  //option to reuse ports, avoiding timeout period
  setsockopt(my_socket, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

  //the variable address stores port and ip address for socket
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  address.sin_family = AF_INET; //remember, AF_INET means standard iPv4 protocol
  address.sin_addr.s_addr = INADDR_ANY; //we can listen to any ip address
  //we chose port number 1969; htons ensures correct network format of number
  address.sin_port = htons(1969);

  //convert sockaddr_in * to a sockaddr *
  bind(my_socket, (struct sockaddr *) &address, addrlen);

  //10 is the max number of connection attempts for backlog
  listen(my_socket, 10);

  //new socket accepts connection that was listened for
  int new_socket = accept(my_socket, (struct sockaddr *) &address,
                          (socklen_t*) &addrlen);

  while (true) {
    //create buffer to store accepted message, with max of 1000 char
    char buffer[1000] = {0};
    //read from new_socket into buffer
    read(new_socket, buffer, 1000);
    //prints string followed by newline from buffer
    printf("%s\n", buffer);
  }                        
  return 0; //makes sure exits successfully
}
