#include "img_cli.h"

void func(int sockfd)
{
	char buff[MAX];
	int n;
	for (;;) {
		bzero(buff, sizeof(buff));
		printf("Enter the string : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff));
		printf("From Server : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and varification
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
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
	//func(sockfd);
	send_server_image(sockfd);

	// close the socket
	close(sockfd);
}

int send_server_image(int sock){

    int n = 0;
    int siz = 0;
    FILE *picture;
    char buf[50];
    char *s="";

    cout << "Getting image size" << endl;
    picture = fopen("/home/ahmad/Desktop/bilal imran/Afiniti-20210601T080801Z-001/Afiniti/task02/example.jpg", "rb"); 
    fseek(picture, 0, SEEK_END);
    siz = ftell(picture);
    cout << siz << endl; // Output 880

    cout << "Sending picture size to the server" << endl;
    sprintf(buf, "%d", siz);
    if((n = send(sock, buf, sizeof(buf), 0)) < 0)
    {
            perror("send_size()");
            exit(errno);
    }

    char Sbuf[siz];
    cout << "Sending the picture as byte array" << endl;
    fseek(picture, 0, SEEK_END);
    siz = ftell(picture);
    fseek(picture, 0, SEEK_SET); //Going to the beginning of the file

    while(!feof(picture)){
    n = fread(Sbuf, sizeof(char), siz, picture);
    if (n > 0) { /* only send what has been read */
        if((n = send(sock, Sbuf, siz, 0)) < 0) /* or (better?) send(sock, Sbuf, n, 0) */
        {
            perror("send_data()");
            exit(errno);
        }
    }
    /* memset(Sbuf, 0, sizeof(Sbuf)); useless for binary data */
    }
}

