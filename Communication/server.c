//For all the system calls that will be used regarding sockets, it is mandatory that the following header files be used
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080 

int main(int agrc, char * argv[]) 
{
	int sock_fd, new_socket, valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[2048] = {0};
	char *fun = "YAAAAAAAAAAAY";

	/*------------------------1.SOCKET CREATION-------------------------*/
	if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		/*socket can be created using socket system call which takes in the following parameters:
			#domain		#type		#protocol
				Syntax: int socket(int domain, int type, int protocol)
			>The domain can be AF_INET or AF_UNIX where AF_INET refers to the internet domain and AF_UNIX refers to the unix domain.
			>The type can be SOCKET_STREAM or SOCKET_DATAGRAM which specifies the connection to be made i.e TCP or UDP
			>Using 0 in the protocol means that we will be using the IP
		If something goes wrong the socket system call will return a negative value, otherwise it will be successful and get the socket created. 
		*/
		printf("\n error, SOCKET went wrong\n");
		return -1;
	}

	/*configuration of server side settings*/
	address.sin_family = AF_INET; //Address family is set as internet.
	address.sin_addr.s_addr = INADDR_ANY; //Setting the IP address, setting it as INADDR_ANY makes the life easier. Mapped to Localhost 127.0.0.1.
	//address.sin_addr.s_addr = inet_addr("127.0.0.1"); can also be used instead
	address.sin_port = htons(PORT); // This is to represent the Byte ordering. Here host to network short is represented as HTONS.

	/*------------------------2.BINDING-------------------------*/
	if(bind(sock_fd,(struct sockaddr*)&address, sizeof(address))<0)
	{
		/*The second step is binding
			Syntax: int bind(int sockfd, const struct sockaddr *my_addr, int addrlen);

		my_addr is a pointer to the sockaddr that has the information about the IP address and port information. 

		Bind function assigns an IP and port number to a socket.
		*/
		printf("\n error, Binding went wrong \n");
		return -1;
	}

	/*------------------------3.LISTENING-------------------------*/
	if (listen(sock_fd, 4) < 0)
	{
		/*listen system call listens for approaches from clients to the server.
			Syntax: int listen(int sockfd, int backlog);
		backlog refers to the number of connections allowed in the queue. It can never be zero. 
		Here, the unconnected socket is converted to a passive socket. This enables incoming requests to be directed to this socket. 
		*/
		printf("\n error, LISTENING went wrong\n");
		return -1;
	}

	/*------------------------4.ACCEPT-------------------------*/
	if ((new_socket = accept(sock_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))<0)
	{
		/*accept system call allows connections to the server
			Syntax: int accept(int sockfd, void *addr, int *addrlen);

		sockfd refers to the socket file descriptor returned by socket()
		addr is a pointer to a structure sockaddr_in.IP and port information are available here.
		Here, the connection request is handled and the connection gets established here!
		*/
		printf("\n error, ACCEPT went wrong\n");
		return -1;
	}

	valread = read(new_socket, buffer, 2048);
	printf("%s\n", buffer);
	send(new_socket, fun, strlen(fun), 0);
	printf("THE MESSAGE SENT\n");
	return 0;





}


