#include<Winsock2.h>
#include<stdio.h>
#include"User.h"
#include<iostream>
#include<string>
#include"func.h"
using namespace std;



void main()
{
	//加载套接字库
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

	//创建用于监听的套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	//绑定套接字
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	//将套接字设为监听模式,准备接受客户请求
	listen(sockSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		
		//接收操作识别信息
		char judge[10];
		recv(sockConn, judge, 11, 0);
		char test[10] = "denglu";
		//将接收到的信息与"登录"比较
		if (strcmp(judge, test)==0)
			{
				cout << "登录"<<endl;
				//回复确认信息
				sendMSG(sockConn);

				//接收ID和password
				char IdPw[80];
				recv(sockConn, IdPw, 81, 0);

				//分离ID和password
				char id[10]=" ";
				char pw[40]=" ";
				int i = 0;
				for (; IdPw[i] != ';'; i++)
				{
					id[i] = IdPw[i];
				}
				cout<<"账号:" << id << endl;
				i++;
				for (int p=0; IdPw[i] != '\0'; i++,p++)
				{
					pw[p] = IdPw[i];
				}
				cout << "密码:" << pw << endl;


				//验证账号密码
				User user;
				if (user.check(id, pw))
				{
					char jud[10] = "YES";
					send(sockConn, jud, 11, 0);
				}
				else
				{
					char jud[10] = "NO";
					send(sockConn, jud, 11, 0);
				}
			}



		closesocket(sockConn);
	}







}
