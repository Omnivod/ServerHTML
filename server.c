#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello from C!";
  
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);
  
  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, 3);
  
  new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
  
  read(new_socket, buffer, 1024);
  send(new_socket, hello, strlen(hello), 0);
  
  close(new_socket);
  close(server_fd);
}
