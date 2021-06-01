#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
using namespace std;

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int recv_client_image(int sock);
