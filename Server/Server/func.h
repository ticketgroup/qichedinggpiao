#pragma once
#ifndef  FUNC_H
#define FUNC_H

#include<Winsock2.h>
#include<stdio.h>

void sendMSG(SOCKET sock)
{
	char sendmsg[3] = "OK";
	send(sock, sendmsg, 4, 0);
}

void recvMSG(SOCKET sock)
{
	char recvmsg[3];
	recv(sock, recvmsg, 4, 0);
}

#endif //  FUNC_H