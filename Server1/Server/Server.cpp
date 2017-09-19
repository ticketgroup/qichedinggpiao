#include"Server.h"
using namespace std;

//����ڴ沢������Ϣ
#define RECVMSG {												\
	memset(buf_msg, 0, MSG_BUF_SIZE);							\
	ret_val = ::recv(sock_clt, buf_msg, MSG_BUF_SIZE, 0);		\
 }
//�����˺�����
#define DIV_ID_PW(IdPw) {							\
	int i = 0;										\
	for (; IdPw[i] != ';'; i++)						\
		id[i] = IdPw[i];							\
	i++;											\
	for (int p = 0; IdPw[i] != ';'; i++, p++)		\
		pw[p] = IdPw[i];							\
}
//�������ڳ����غ��յ�
#define DIV_MD_ST_ED(buf_msg) {						\
	memset(MMDD, 0,MD_SIZE );/*char MMDD[10];*/			\
	memset(start, 0,STA_SIZE );/*char start[10]*/;									\
	memset(end, 0,STA_SIZE );/*char end[10];*/int i = 0;							\
	for (; buf_msg[i] != ';';i++)					\
		MMDD[i] = buf_msg[i];						\
	i++;											\
	for (int p = 0; buf_msg[i] != ';'; i++, p++)	\
		start[p] = buf_msg[i];i++;					\
	for (int p = 0; buf_msg[i] != ';'; i++, p++)	\
		end[p] = buf_msg[i];						\
}
//�����ַ�Y
#define SENDY {						\
	char sendy[10]="Y";				\
	send(sock_clt,sendy,10,0);		\
}
//�����ַ�N
#define SENDN {						\
	char sendy[10]="Y";				\
	send(sock_clt,sendy,10,0);		\
}
//��ά����ת��Ϊһά����
#define DIV_TH_CH(a) {											\
	char b[60] = " ";											\
	int i = 0;													\
	for (; a[0][0][i] != '\0'&&i < 20; i++)						\
		b[i] = a[0][0][i];										\
	i = 20;														\
	for (int p = 0; a[0][p][0] != '\0'&&p < 20; i++, p++)		\
		b[i] = a[0][p][0];										\
	i = 40;														\
	for (int p = 0; a[p][0][0] != '\0'&&p < 20; i++, p++)		\
		b[i] = a[p][0][0];										\
}


#define SERVER_PORT 6000    //�˿ں�
#define MSG_BUF_SIZE 1024	//buf_msg�ĳ���
#define ID_SIZE 20			//ID����
#define PW_SIZE 50			//���볤��
#define CD_SIZE 20			//һ��ͨ����
#define SD_SIZE 20			//ѧ�ų���
#define PN_SIZE 20			//�ֻ��ų���
#define MD_SIZE 10			//���ճ���
#define STA_SIZE 10			//վ������
#define BUS_ID_SIZE 10
#define TIME_SIZE 10
//��ѯ��Ϣ�������ά
#define UNIT_SIZE 10
#define ROW_SIZE 15
#define LINE_SIZE 20
#define INFO_SIZE 3000

DWORD WINAPI CreateClientThread(LPVOID IpParameter);

//�û���
int nPlayCount;
SOCKET nSocketData[4];

Server::Server()
{
	//��ʼ��������
	cout << "���ڳ�ʼ��������...\n";

	winsock_ver = MAKEWORD(2, 2);
	addr_len = sizeof(SOCKADDR_IN);
	addr_svr.sin_family = AF_INET;
	addr_svr.sin_port = htons(SERVER_PORT);
	addr_svr.sin_addr.S_un.S_addr = ADDR_ANY;
	memset(buf_ip, 0, IP_BUF_SIZE);

	ret_val = ::WSAStartup(winsock_ver, &wsa_data);
	if (ret_val != 0)
	{
		cerr << "WSA ����ʧ��!�������: " << ::WSAGetLastError() << "\n";
		system("pause");
		exit(1);
	}

	cout << "WSA�����ɹ�...\n";

	sock_svr = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_svr == INVALID_SOCKET)
	{
		cerr << "�������׽��ִ���ʧ��!�������: " << ::WSAGetLastError() << "\n";
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "�������׽��ִ����ɹ�...\n";

	ret_val = ::bind(sock_svr, (SOCKADDR*)&addr_svr, addr_len);
	if (ret_val != 0)
	{
		cerr << "�������׽��ְ�ʧ��!�������: " << ::WSAGetLastError() << "\n";
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "�������׽��ְ󶨳ɹ�...\n";

	ret_val = ::listen(sock_svr, SOMAXCONN);
	if (ret_val == SOCKET_ERROR)
	{
		cerr << "�������׽��ּ�������ʧ��!�������: " << ::WSAGetLastError() << endl;
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "�������׽��ֿ�ʼ����...\n";

	cout << "�����������ɹ�..." << endl;

	//��ʼ���û�����
	nPlayCount = 0;
}

Server::~Server()
{
	::closesocket(sock_svr);
	::closesocket(sock_clt);
	::WSACleanup();
	cout << "ͨ�Źر�.." << endl;
}

void Server::WaitForClient()
{
	while (true)
	{
		sock_clt = ::accept(sock_svr, (SOCKADDR*)&addr_clt, &addr_len);
		if (sock_clt == INVALID_SOCKET)
		{
			cerr << "���տͻ�����Ϣʧ��!�������: " << ::WSAGetLastError() << "\n";
			::WSACleanup();
			system("pause");
			exit(1);
		}
		::inet_ntop(addr_clt.sin_family, &addr_clt, buf_ip, IP_BUF_SIZE);
		cout << "һ���µ������ѽ���...IP��ַ: " << buf_ip << ", �˿ں�: " << ::ntohs(addr_clt.sin_port) << endl;

		//�������߳�
		h_thread = ::CreateThread(nullptr, 0, CreateClientThread, (LPVOID)sock_clt, 0, nullptr);
		nSocketData[nPlayCount] = sock_clt;
		nPlayCount++;
		if (h_thread == NULL)
		{
			cerr << "�������߳�ʧ��...�������: " << ::WSAGetLastError() << "\n";
			::WSACleanup();
			system("pause");
			exit(1);
		}
		::CloseHandle(h_thread);
	}
}


DWORD WINAPI CreateClientThread(LPVOID IpParameter)
{
	SOCKET sock_clt = (SOCKET)IpParameter;
	char buf_msg[MSG_BUF_SIZE];
	int ret_val = 0;
	int snd_result = 0;
	char id[ID_SIZE] = "";
	char pw[PW_SIZE] = "";
	char MMDD[MD_SIZE] = "";
	char start[STA_SIZE] = "";
	char end[STA_SIZE] = "";
	char npw[PW_SIZE] = "";


	char riqi[MD_SIZE] = "";
	char qicheid[BUS_ID_SIZE] = "";
	char qidian[STA_SIZE] = "";
	char qidiantime[TIME_SIZE] = "";
	char zhongdian[STA_SIZE] = "";
	char zhongdiantime[TIME_SIZE] = "";
	char taid[10] = "";


label0:
	RECVMSG;

	do
	{
		if (ret_val > 0)
		{
			int judgeint = atoi(buf_msg);

			switch (judgeint)
			{
				//��ͨ�û�ע��ǰ��֤
			case 7:
			{
				cout << "��֤" << endl;
				SENDY;
				char card[20] = "";
				char Sid[20] = "";
				char cdsd[50] = "";
				recv(sock_clt, cdsd, 50, 0);
				//����һ��ͨ��ѧ��
				int i = 0;
				for (; cdsd[i] != ';'; i++)
				{
					card[i] = cdsd[i];
				}
				i++;
				for (int p = 0; cdsd[i] != ';'; i++, p++)
				{
					Sid[p] = cdsd[i];
				}

				//��֤һ��ͨ��ѧ��
				if (ver(id,pw))
				{
					SENDY;
				}
				else
				{
					SENDN;
				}
				goto label0;
			}
			break;
			//��ͨ�û�ע��
			case 8:
			{
				cout << "ע��" << endl;
				SENDY;
				RECVMSG;
				cout << buf_msg << endl;
				char card[20] = "";
				char Sid[20] = "";
				char pn[20] = "";
				char pw[50] = "";
				int i = 0;
				//���������Ϣ
				for (; buf_msg[i] != ';'; i++)
					card[i] = buf_msg[i];
				cout << card << endl;
				i++;
				for (int p = 0; buf_msg[i] != ';'; i++, p++)
					Sid[p] = buf_msg[i];
				cout << Sid << endl;
				i++;
				for (int p = 0; buf_msg[i] != ';'; i++, p++)
					pn[p] = buf_msg[i];
				cout << pn << endl;
				i++;
				for (int p = 0; buf_msg[i] != ';'; i++, p++)
					pw[p] = buf_msg[i];
				cout << pw << endl;
				//��ӵ����ݿ�
				if (/*reg(card,Sid,pn,pw)*/1)
				{
					SENDY;
					cout << "ע��ɹ�!" << endl;
				}
				else
				{
					SENDN
				}
			}
			break;
			//��ͨ�û���¼
			case 2:
			{
				cout << "��½" << endl;
				SENDY
					//����ID��password
					char IdPw[ID_SIZE + PW_SIZE];
				recv(sock_clt, IdPw, ID_SIZE + PW_SIZE, 0);

				//����ID��password
				DIV_ID_PW(IdPw);

				//	Nuser nuser(id, pw);
				//��֤�˺�����
				if (/*nuser.verify(id,pw)*/1)
					SENDY
				else
					SENDN;
				goto label0;
			}
			break;
			//��ƱԱ��¼
			case 5:
			{
				SENDY

					//����ID��password
					char IdPw2[ID_SIZE + PW_SIZE];
				::recv(sock_clt, IdPw2, ID_SIZE + PW_SIZE, 0);

				DIV_ID_PW(IdPw2);


				//��֤�˺�����
				if (1/*�ж�*/)
				{
					SENDY
				}
				else
					SENDN
					goto label0;
			}

			//��ͨ�û�ע��
			case 3:
			{
				cout << "�ͻ�������ر�����..." << endl;
				SENDY;
				goto label5;
			}
			break;

			//��ͨ�û���ѯ��Ϣ
			case 4:
			{
				cout << "��ѯ" << endl;
				SENDY;
				RECVMSG;
				DIV_MD_ST_ED(buf_msg);
				cout << buf_msg << endl;
				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				//����info����
				info[0][0] = "qicheid";
				info[0][1] = "shengyup";
				info[0][2] = "qidian#";
				info[1][0] = "����id";
				info[1][1] = "ʣ��";
				info[1][2] = "���$";
				if (/*carinfo(info)*/1)
				{
					char cinfo[INFO_SIZE] = "";
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							if (info[i][j][strlen(info[i][j]) - 1] == '#')
							{
								strcat(cinfo, info[i][j]);
								break;
							}
							else if (info[i][j][strlen(info[i][j]) - 1] == '$')
							{
								strcat(cinfo, info[i][j]);
								goto labelbreak1;
							}
							else
							{
								strcat(cinfo, info[i][j]);
								strcat(cinfo, ";");
							}
						}
					}
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
				labelbreak1:
					cout << cinfo << endl;
					send(sock_clt, cinfo, INFO_SIZE, 0);
				}
				else
					SENDN;
				goto label0;
			}
			break;

			//��ͨ�û���������
			case 18:
			{
				SENDY;
				RECVMSG;
				DIV_ID_PW(buf_msg);
				SENDY;
				RECVMSG;
				cout << buf_msg;
				//Nuser nuser(id,pw);
				//�������ĳ����ݿ����
				memcpy(pw, buf_msg, strlen(buf_msg));
				pw[strlen(buf_msg)] = '\0';
				if (/*nuser.changePassword(npw)*/1)
				{
					SENDY
						cout << "ID: " << id << "\n������" << buf_msg << endl;
				}
				else
					SENDN;
				goto label0;
			}
			break;

			//��ƱԱע��
			case 6:
			{
				cout << "�ͻ�������ر�����..." << endl;
				SENDY;
				closesocket(sock_clt);
			}
			break;

			//��ƱԱ��ѯ
			case 9:
			{
				cout << "��ѯ" << endl;
				SENDY;
				RECVMSG;
				DIV_MD_ST_ED(buf_msg);
				cout << buf_msg << endl;
				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				//����info����
				info[0][0] = "qicheid";
				info[0][1] = "shengyup";
				info[0][2] = "qidian#";
				info[1][0] = "����id";
				info[1][1] = "ʣ��";
				info[1][2] = "���$";
				if (/*carinfo(info)*/1)
				{
					char cinfo[INFO_SIZE] = "";
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							if (info[i][j][strlen(info[i][j]) - 1] == '#')
							{
								strcat(cinfo, info[i][j]);
								break;
							}
							else if (info[i][j][strlen(info[i][j]) - 1] == '$')
							{
								strcat(cinfo, info[i][j]);
								goto labelbreak;
							}
							else
							{
								strcat(cinfo, info[i][j]);
								strcat(cinfo, ";");
							}
						}
					}
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
				labelbreak:
					cout << cinfo << endl;
					send(sock_clt, cinfo, INFO_SIZE, 0);
				}
				else
					SENDN;
				goto label0;
			}
			break;

			//�û���Ʊ
			case 12:
			{
				SENDY;
				RECVMSG;
				{
					int i = 0;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						riqi[m] = buf_msg[i];
					cout << riqi << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						qicheid[m] = buf_msg[i];
					cout << qicheid << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						qidian[m] = buf_msg[i];
					i++;
					cout << qidian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						qidiantime[m] = buf_msg[i];
					cout << qidiantime << endl;

					i = strlen(buf_msg) - 1;
					i--;
					for (; buf_msg[i] != ';'; i--);
					i--;
					for (; buf_msg[i] != ';'; i--);
					i--;
					for (; buf_msg[i] != ';'; i--);
					i++;

					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						zhongdian[m] = buf_msg[i];
					i++;
					cout << zhongdian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						zhongdiantime[m] = buf_msg[i];
					i++;
					cout << zhongdiantime << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						taid[m] = buf_msg[i];
					i++;
					cout << taid << endl;
				}

				//User user(id,pw);
				//char sour[20]="";
				if (/*user.gettnum(qicheid,qidian,zhongdian,sour)*/1)
				{
					/*int seat=user.getSeatNum(id,start,end)*/
					if (/*a.choosetichet.(qicheid,sour,riiq,id,taid,seat)*/1)
						if (/*a.buyticket()*/1)
						{
							SENDY;
						}
				}
				goto label0;
			}
			break;
			//��ѯ����
			case 13:
			{
				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				//Nuser nuser(id,pw);
				if (/*nuer.inquireticket(info)*/1)
				{
					//��ά����תһά
					char sinfo[1000] = "asd";
					send(sock_clt, sinfo, 1000, 0);
				}
			}
			break;
			//�û���Ʊ
			case 14:
			{
				SENDY;
				RECVMSG;
				//���
				//���ú�����Ʊ

			}
			break;
			//�û���ǩ
			case 15:
			{
				SENDY;
				RECVMSG;
				/////////
			}
			break;
			//����Ա��¼
			case 16:
			{

			}
			case 0:
				goto label0;
				break;
			default:
				goto label0;
			}
		}
	} while (ret_val > 0 && strcmp(buf_msg, "exit") != 0);
	////////////////////////////////////////////////
	if (ret_val == 0)
	{
		cout << "���ӹر�..." << endl;
	}
	else if (ret_val < 0)
	{
		cerr << "�ӿͻ��˽�����Ϣʧ��...�������: " << ::GetLastError() << "\n";
		closesocket(sock_clt);
	}
	send(sock_clt, "tuichu", 10, 0);
label5:
	closesocket(sock_clt);
	return 0;

