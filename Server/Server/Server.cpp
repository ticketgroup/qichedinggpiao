#include<Winsock2.h>
#include<stdio.h>
#include"User.h"
#include<iostream>
#include<string>
#include"func.h"
using namespace std;



void main()
{
	//�����׽��ֿ�
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

	//�������ڼ������׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	//���׽���
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	//���׽�����Ϊ����ģʽ,׼�����ܿͻ�����
	listen(sockSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		
		//���ղ���ʶ����Ϣ
		char judge[10];
		recv(sockConn, judge, 11, 0);
		char test[10] = "denglu";
		//�����յ�����Ϣ��"��¼"�Ƚ�
		if (strcmp(judge, test)==0)
			{
				cout << "��¼"<<endl;
				//�ظ�ȷ����Ϣ
				sendMSG(sockConn);

				//����ID��password
				char IdPw[80];
				recv(sockConn, IdPw, 81, 0);

				//����ID��password
				char id[10]=" ";
				char pw[40]=" ";
				int i = 0;
				for (; IdPw[i] != ';'; i++)
				{
					id[i] = IdPw[i];
				}
				cout<<"�˺�:" << id << endl;
				i++;
				for (int p=0; IdPw[i] != '\0'; i++,p++)
				{
					pw[p] = IdPw[i];
				}
				cout << "����:" << pw << endl;


				//��֤�˺�����
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
