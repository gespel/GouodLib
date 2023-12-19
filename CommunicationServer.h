/*
  ==============================================================================

    CommunicationServer.h
    Created: 12 Dec 2023 7:17:21pm
    Author:  sten

  ==============================================================================
*/
/*
#pragma once
#include "JuceHeader.h"
#include <string>
#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

class CommunicationServer {
public:
	CommunicationServer();
	void startServer();
private:
	std::string servername;
	std::string address;
	int port;
	int sockfd; 
    char buffer[1024]; 
    struct sockaddr_in servaddr, cliaddr; 

};


class ServerThread : public juce::Thread {
public:
    ServerThread() : juce::Thread("ServerThread") {}

    void run() override
    {
        // Hier wird die Aufgabe im Hintergrund ausgeführt
        for (int i = 0; i < 10; ++i)
        {
            juce::String message = juce::String("Iteration ") + juce::String(i + 1);
			std::cout << message << std::endl;

            // Hier könnten weitere Berechnungen oder Operationen erfolgen
            juce::Thread::sleep(1000); // 1 Sekunde Pause zwischen den Iterationen
        }
    }


private:

};
*/
