/*
1. NAME
       socket - create an endpoint for communication

SYNOPSIS
       #include <sys/types.h>          /* See NOTES
       #include <sys/socket.h>

       int socket(int domain, int type, int protocol);
			1st arg: Communication doamin specify protocol family (AF_UNIX,AF_INET,AF_INET6)
			2nd arg: type -> communication semantics (SOCK_STREAM,SOCK_DGRAM)
			3rd arg: protocol to be use (0 -> selecet automatically w.r.t. domain)

		return: fd represent to end point(peer) for communication

DESCRIPTION
       socket()  creates  an endpoint for communication and returns a file descriptor that refers to
		that endpoint.  The file descriptor returned by a successful call  will  be  the  lowest-numbered
		file descriptor not currently open for the process.

       The  domain argument specifies a communication domain; this selects the protocol family which will
       be used for communication.  These families are defined in <sys/socket.h>.   The  currently  under‐
       stood formats include:

       Name                Purpose                          Man page
       AF_UNIX, AF_LOCAL   Local communication              unix(7)
       AF_INET             IPv4 Internet protocols          ip(7)
       AF_INET6            IPv6 Internet protocols          ipv6(7)

  The socket has the indicated type, which specifies the communication semantics.  Currently defined
       types are:

       SOCK_STREAM     Provides sequenced, reliable, two-way, connection-based byte streams.  An  out-of-
                       band data transmission mechanism may be supported.

       SOCK_DGRAM      Supports  datagrams  (connectionless,  unreliable  messages  of  a  fixed  maximum
                       length).
*************************************************************************************************
2. NAME
       bzero, explicit_bzero - zero a byte string

SYNOPSIS
       #include <strings.h>

       void bzero(void *s, size_t n);
			1st arg: memory address to errase mem
			2nd arg: no of bytes to erase
		return: None

DESCRIPTION
       The bzero() function erases the data in the n bytes of the memory starting at the location pointed
       to by s, by writing zeroes (bytes containing '\0') to that area.
*************************************************************************************************

3. NAME
       bind - bind a name to a socket

SYNOPSIS
       #include <sys/types.h>          /* See NOTES
       #include <sys/socket.h>

       int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
			1st arg: fd return by socket()
			2nd arg: 

DESCRIPTION
	   bind() assigns the address specified by addr to the socket referred to by the  file  descriptor  sockfd.

       When  a  socket  is  created with socket(2), it exists in a name space (address family) but has no
       address assigned to it.addrlen  specifies  the  size, in bytes, of the address structure
       pointed to by addr.  Traditionally, this operation is called “assigning a name to a socket”.

       The actual structure passed for the addr argument will depend on the address family.  The sockaddr
       structure is defined as something like:

           struct sockaddr {
               sa_family_t sa_family;
               char        sa_data[14];
           }

       * The  only  purpose  of  this structure is to cast the structure pointer passed in addr in order to
       avoid compiler warnings

		* a. ipv4 *****************

		   tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

			When a process wants to receive new incoming packets or connections, it should bind a socket to  a
       local interface address using bind(2).  In this case, only one IP socket may be bound to any given
       local (address, port) pair.  When INADDR_ANY is specified in the bind call,  the  socket  will  be
       bound to all local interfaces.  When listen(2) is called on an unbound socket, the socket is auto‐
       matically bound to a random free port with the local address set to INADDR_ANY.   When  connect(2)
       is  called  on  an unbound socket, the socket is automatically bound to a random free port or to a
       usable shared port with the local address set to INADDR_ANY.




*/

#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int sockfd, newsockfd, portno, clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	// First call to socket() function
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0)
	{
		perror("Error opening socket");
		exit(1);
	}

	// Initialize socket structure
	// Erasing structure memory
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 5001;
	//portno = 9999;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	//serv_addr.sin_addr.s_addr = 0;
	serv_addr.sin_port = htons(portno);		// host to network

	// Now bind the host address using bind() call
	if(bind(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))< 0)
	{
		perror("Error on binding");
		exit(1);
	}

	/* Now start listening for the clients, here process will 
		go in sleep mode and will wait for the incoming connection */

	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	// Accept actual connection from the client
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

	if(newsockfd < 0)
	{
		perror("Error on accept");
		exit(1);
	}

	// If connection is established then start communicating
	bzero(buffer,256);
	n = read(newsockfd,buffer,255);

	if(n<0)
	{
		perror("Error reading from socket");
		exit(1);
	}

	printf("Here is the message: %s\n",buffer);

	// Write a response to the client
	n = write(newsockfd,"I got your message",18);

	if(n<0)
	{
		perror("Error writing to socket");
		exit(1);
	}

	return 0;
}
