#pragma once
#ifndef SERVER_H
#define SERVER_H

#include<Winsock2.h>
#include<windows.h>
#include"stdafx.h"
#pragma comment (lib,"ws2_32.lib")
#include<iostream>
#include"stdio.h"
#include<stdio.h>

#include"Buyer.h"
#include"Conductor.h"
#include"func.h"
#include"Nuser.h"
#include"Suser.h"
#include"Ticket.h"
#include"user.h"
using namespace std;

#define IP_BUF_SIZE 129
#define ID_SIZE 20
#define PW_SIZE 50
#define THCH1 20;
#define THCH2 20;
#define THCH3 20;




class Server
{
public:
	Server();
	~Server();
	Server(const Server &) = delete;
	Server & operator=(const Server &) = delete;
	void WaitForClient();


private:
	WORD winsock_ver;
	WSADATA wsa_data;
	SOCKET sock_svr;
	SOCKET sock_clt;
	HANDLE h_thread;
	SOCKADDR_IN addr_svr;
	SOCKADDR_IN addr_clt;
	int ret_val;
	int addr_len;
	char buf_ip[IP_BUF_SIZE];
};


#endif