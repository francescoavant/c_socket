//print out any data we get from remote connection
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
	//create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket 
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons (9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = connect(network_socket,(struct sockaddr*) &server_address, sizeof(server_address));
	//check for error with the connection
	if (connection_status == -1){
		printf ("error in socket connection \n");
	}
	//receive data from server 
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response),0);

	//print out the server's response
	printf ("server says: %s\n", server_response);

	//close the socket
	pclose (network_socket);

	return 0;
}
