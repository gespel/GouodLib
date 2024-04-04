/*
  ==============================================================================

    CommunicationServer.cpp
    Created: 12 Dec 2023 7:17:21pm
    Author:  sten

  ==============================================================================
*/

#include "CommunicationServer.h"
/*
CommunicationServer::CommunicationServer() {
	this->servername = "GouodLab";
	this->port = 8000;
	this->address = "0.0.0.0";


	
       
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
       
    servaddr.sin_family    = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(this->port); 
}


void CommunicationServer::startServer() {
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    while(1) {
		socklen_t len;
		int n; 
    	len = sizeof(cliaddr);
    	n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
    	buffer[n] = '\0'; 
    	printf("Client : %s\n", buffer); 
	}
}*/
