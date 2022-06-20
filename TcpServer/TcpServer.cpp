// TcpServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "stdafx.h"
#include <iostream>
//#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <ctime>
#include <afunix.h>
#include <string>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT 27015
#define DEFAULT_PORT_String "27015"

#define DEFAULT_BUFLEN 512
//#define _WINSOCK_DEPRECATED_NO_WARNINGS


// 1. Initialize Winsock
// 2. Socket
//		2.1 Settings for socket
//		2.2 Socket creation
// 3. Bind Socket
//		3.1 free getaddr result
// 4. Listening on Socket
// 5. Accept incoming connection

int main() {
	int iResult;

	// Initialize Winsock step1
	cout << "Initializing Winsock..." << endl;
	WSADATA wsaData;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) { // Error handling
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	//Another method - of Socket creation for Server
	// Socket creation for Server
	cout << "Creating Socket for the Server..." << endl;
	struct addrinfo* result = NULL,
					* ptr = NULL,
						hints;

	// Settings for the Socket
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET; // used to specify the IPv4 address family. ( after vista you can specify dual-socket for IPv4 an IPv6 )
	hints.ai_socktype = SOCK_STREAM; // used to specify a stream socket.
	hints.ai_protocol = IPPROTO_TCP; // used to specify the TCP protocol .
	hints.ai_flags = AI_PASSIVE; // caller intends to use the returned socket address structure in a call to the bind function.

	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT_String, &hints, &result);
	if (iResult != 0) { // Error handling
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	/*else
	{
		cout << hints << endl;

	}*/





	//Step 2 create the SOCKET.
	SOCKET ListenSocket;		//ListeningSocket for Server.

	if ((ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		cout << "socket failed with error " << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	//Setup of SOCKADDR_IN SERVER_ADDRESS
	SOCKADDR_IN ServerAddr;
	int port = DEFAULT_PORT;

	ServerAddr.sin_family = AF_INET;
	//May set the ip_address using this line:

	//ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//SERVER_ADDRS.c_str() - keyin or cin>>SERVER_ADDRS
	// This ip address will change according to the machine
#pragma warning(suppress : 4996)
	//ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ServerAddr.sin_port = htons(port);		//host to networks
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);	//any clients could be connect to it.

	// Socket Binding
	if (bind(ListenSocket, (sockaddr*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		//freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "Successfully make a bind: " << endl;
#pragma warning(suppress : 4996).
		char* connected_ip = inet_ntoa(ServerAddr.sin_addr);
		int Server_port = ntohs(ServerAddr.sin_port);
		
		cout << "[Server_IP: " << connected_ip << ", Connected on Server_PORT:" << Server_port << "]" << endl;

	}

// 
	// Listening on Socket
	cout << "Start listening on Socket..." << endl;
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) { // SOMAXCONN = max size of pending connection queue
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	cout << "Waiting for new incoming connection!" << endl;
	clock_t begin = clock();
	SOCKET ClientSocket;
	ClientSocket = INVALID_SOCKET;
	SOCKADDR_IN ClientAddr;		//sockadd_In for client
	int CliendAddrLen;
	CliendAddrLen = sizeof(SOCKADDR);
	ClientSocket = accept(ListenSocket, (sockaddr*)&ClientAddr,&CliendAddrLen);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "Successfully make a connection: "<<endl;
#pragma warning(suppress : 4996).
		char* connected_ip = inet_ntoa(ClientAddr.sin_addr);
		int Clientport = ntohs(ClientAddr.sin_port);
		cout << "[IP:" << connected_ip << ", Connected on PORT:" << Clientport << "]" << endl;
		
	}
	//---------------------------------------------------------------------------
	cout << "Receive data!" << endl;
	// Receiving Data
	char recvbuf[DEFAULT_BUFLEN];
	int iSendResult;
	int recvbuflen = DEFAULT_BUFLEN;

	// Receive until the peer shuts down the connection
	do {

		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);

			recvbuf[iResult] = '\0';	//impt!!! null-character to terminate the string.
			//printf("%s\n", recvbuf);
			cout << recvbuf << endl;

			// Echo the buffer back to the sender
			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			printf("Bytes sent: %d\n", iSendResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}

	} while (iResult > 0);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Elapsed time: " << elapsed_secs << endl;

	// Shutdown
	cout << "Shutdown the Server!" << endl;
	iResult = shutdown(ClientSocket, SD_BOTH);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}
	// cleanup
	closesocket(ClientSocket);
	WSACleanup();


	system("pause");
	return 0;
}
