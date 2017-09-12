#include<Winsock2.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return;
	}
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	//创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);


	//向服务器发出连接请求
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char jud[10] = "denglu";
	send(sockClient, jud, 11, 0);
	closesocket(sockClient);


	closesocket(sockClient);
	WSACleanup();
}