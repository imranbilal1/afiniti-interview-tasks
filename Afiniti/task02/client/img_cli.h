#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

using namespace std;

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int send_server_image(int sock);
