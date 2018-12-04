#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#define PORT 8080

int main(int agrc, char * argv[]) 
{
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *fun_client = "I AM CLIENT, I AM HERE";
	char buffer[2048] = {0};

	/*------------------------1.SOCKET CREATION-------------------------*/
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n error, SOCKET went wrong");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT); //This is to represent the Byte ordering. Here host to network short is represented as HTONS.

	/*------------------------2.ADDRESS VALIDATION-------------------------*/
	//address related operation. Kind of validity you can say!!
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		//inet_pton - convert IPv4 and IPv6 addresses from text to binary form
		printf("\nInvalid address/ Address not supported\n");
		return -1;
	}

	/*------------------------3.ESTABLISH CONNECTION-------------------------*/
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr) < 0))
	{
		printf("\nNo connection\n");
		return -1;
	}

	send(sock, fun_client, strlen(fun_client), 0);
	printf("\nHello message sent\n");
	valread = read(sock, buffer,2048);
	printf("%s\n", buffer);
	return 0;
}

/*The inet_addr() function converts the internet host address cp from IPV4 numbers-and-dots notation into binary data in 
network byte order. If the input is invalid, INADDR_NONE(-1) is returned. But use of this function sometimes can be 
problematic because -1 represents 255.255.255.255. You should avoid its use in favor of inet_aton(), inet_pton() or 
getaddrinfo()*/