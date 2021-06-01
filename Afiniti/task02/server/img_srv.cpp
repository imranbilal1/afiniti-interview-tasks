#include "img_srv.h"

int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, (unsigned int*) &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	// Function for chatting between client and server
	recv_client_image(connfd);	

	// After chatting close the socket
	close(sockfd);
}


int recv_client_image(int sock){

    int n = 0;

    cout << "Reading image size" << endl;
    char buf[50];
    int siz = 0;
    if ((n = recv(sock, buf, sizeof(buf), 0) <0)){
        perror("recv_size()");
        exit(errno);
    }
    siz = atoi(buf);
    cout << siz << endl; // 880 output

    char Rbuffer[siz];
    cout << "Reading image byte array" << endl;
    n = 0;

    if ((n = recv(sock, Rbuffer, siz, 0)) < 0){
       perror("recv_size()");
       exit(errno);
     }

     cout << "Converting byte array to image" << endl;
     FILE *image;
     image = fopen("recu.jpg", "wb");
     fwrite(Rbuffer, sizeof(char), siz, image);
     fclose(image);    cout << "done" << endl;
}
