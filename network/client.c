#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

int main(void)
{
	int valread;
	int sockfd = 0,n = 0;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;

	memset(recvBuff, '0', sizeof(recvBuff));

	// First call to socket() function
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0)
	{
		printf("\n Error: Could not create socket\n");
		return 1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5001);		// host to network
	//serv_addr.sin_port = htons(9999);		// host to network
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	//local host addr

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("\n Error: connect failed \n");
		return 1;
	}

	send(sockfd, "hello", strlen("hello"),0);
	printf("hello message sent \n");
	valread = read(sockfd, recvBuff, 1024);
	recvBuff[valread] = '\0';
	printf("%s\n",recvBuff);
	return 0;


}
