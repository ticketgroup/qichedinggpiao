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
	for (int p = 0; IdPw[i] != '\0'; i++, p++)		\
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
	char sendy[2]="Y";				\
	send(sock_clt,sendy,2,0);		\
}
//�����ַ�N
#define SENDN {						\
	char sendy[10]="N";				\
	send(sock_clt,sendy,2,0);		\
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
	char cd[CD_SIZE] = "";
	char sid[SD_SIZE] = "";
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
				char cdsd[50] = "";
				recv(sock_clt, cdsd, 50, 0);
				//����һ��ͨ��ѧ��
				int i = 0;
				for (; cdsd[i] != ';'; i++)
				{
					cd[i] = cdsd[i];
				}
				i++;
				for (int p = 0; cdsd[i] != '\0'; i++, p++)
				{
					sid[p] = cdsd[i];
				}

				//��֤һ��ͨ��ѧ��
				if (ver(cd,sid))
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
				char pn[20] = "";
				char pw[50] = "";
				int i = 0;
				//���������Ϣ
				for (int p = 0; buf_msg[i] != ';'; i++, p++)
					pn[p] = buf_msg[i];
				cout << pn << endl;
				i++;
				for (int p = 0; buf_msg[i] != '\0'; i++, p++)
					pw[p] = buf_msg[i];
				cout << pw << endl;
				//��ӵ����ݿ�
				if (reg(cd, pn, pw))
				{
					SENDY;
					cout << "ע��ɹ�!" << endl;
				}
				else
				{
					SENDN
				}
				goto label0;
			}
			break;

			//��ͨ�û���¼
			case 2:
			{
				cout << "�û���½" << endl;
				SENDY;
				//����ID��password
				char IdPw[ID_SIZE + PW_SIZE];
				recv(sock_clt, IdPw, ID_SIZE + PW_SIZE, 0);

				//����ID��password
				DIV_ID_PW(IdPw);

				Nuser nuser(id, pw);
				//��֤�˺�����
				char ver=nuser.verify(pw);
				if (ver == 'Y')
					SENDY
				else if (ver == '1')
					send(sock_clt, "1", 2, 0);
				else if (ver == '2')
					send(sock_clt, "2", 2, 0);
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

				Suser suser(id, pw);
				//��֤�˺�����
				char ver = suser.verify(pw);
				if (ver == 'Y')
					SENDY
				else if (ver == '1')
					send(sock_clt, "1", 2, 0);
				else if (ver == '2')
					send(sock_clt, "2", 2, 0);
					goto label0;
			}

			//��ͨ�û�ע��
			case 3:
			{
				cout << "�ͻ�������ע��..." << endl;
				SENDY;
				goto label0;
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
				Nuser nuser(id, pw);
				if (nuser.carinfo(MMDD, start, end, info))
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
					//delete info
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
				int i = 0;
				char oldpw[PW_SIZE] = "";
				char newpw[PW_SIZE] = "";
				for (; buf_msg[i] != ';'; i++)						
					oldpw[i] = buf_msg[i];							
				i++;											
				for (int p = 0; buf_msg[i] != '\0'; i++, p++)		
					newpw[p] = buf_msg[i];
				cout << buf_msg;
				Nuser nuser(id, oldpw);
				char ver = nuser.verify(oldpw);
				if (ver == 'Y')
				{
					if (nuser.changePassword(newpw))
					{
						memcpy(pw, newpw, strlen(newpw));
						pw[strlen(newpw)] = '\0';
						SENDY;
					}
				}
				if (ver == '2')
				{
					send(sock_clt, "2", 3, 0);
				}		
				goto label0;
			}
			break;

			//��ͨ�û��һ�����
			case 10:
			{
				SENDY;
				RECVMSG;
				char tcd[CD_SIZE] = "";
				char tsd[SD_SIZE] = "";
				int i = 0;
				for (; buf_msg[i] != ';'; i++)
				{
					tcd[i] = buf_msg[i];
				}
				i++;
				for (int p = 0; buf_msg[i] != '\0'; i++, p++)
				{
					tsd[p] = buf_msg[i];
				}

				if (ver(tcd, tsd))
				{
					SENDY;
				}
				else
					SENDN;
				goto label0;
			}
			break;

			//�û��һ�����ʱ�޸�����
			case 11:
			{
				SENDY;
				RECVMSG;
				char tid[CD_SIZE] = "";
				char tpw[SD_SIZE] = "";
				int i = 0;
				for (; buf_msg[i] != ';'; i++)
				{
					tid[i] = buf_msg[i];
				}
				i++;
				for (int p = 0; buf_msg[i] != '\0'; i++, p++)
				{
					tpw[p] = buf_msg[i];
				}
				if (findPassword(tid, tpw))
					SENDY
				else
					SENDN
					goto label0;
			}
			break;

			//��ƱԱע��
			case 6:
			{
				cout << "�ͻ�������ע��..." << endl;
				SENDY;
				goto label0;
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

				Suser suser(id, pw);
				if (suser.carinfo(MMDD, start, end, info))
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

			//��ƱԱ��Ʊ
			case 17:
			{
				SENDY;
				RECVMSG;
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";

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

				Suser suser(id, pw);
				char sour[20] = "";
				if (gettnum(qicheid, qidian, zhongdian, sour))
				{
					int seat = getSeatNum(id, qidian, zhongdian);
					char seat1[5] = "";
					itoa(seat, seat1, 5);
					suser.chooseticket(qicheid, sour, riqi, id, taid, seat1);
					if (suser.buyticket())
					{
						SENDY;
					}
				}
				goto label0;
			}
			break;

			//��ƱԱ��Ʊ
			case 19:
			{
				SENDY;
				RECVMSG;
				//����id;��λ��;���;����ʱ��;�յ�;����ʱ��;�˳���;����;
				//���
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";
				char seat[5] = "";

				int i = 0;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qicheid[m] = buf_msg[i];
				cout << qicheid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					seat[m] = buf_msg[i];
				cout << seat << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidian[m] = buf_msg[i];
				cout << qidian << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidiantime[m] = buf_msg[i];
				cout << qidiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdian[m] = buf_msg[i];
				cout << zhongdian << endl; i++;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdiantime[m] = buf_msg[i];
				cout << zhongdiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					taid[m] = buf_msg[i];
				cout << taid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					riqi[m] = buf_msg[i];
				cout << riqi << endl;
				i++;

				Suser suser(id, pw);

				//���ú�����Ʊ
				char sour[20] = "";

				if (gettnum(qicheid, qidian, zhongdian, sour))
				{
					int seat = getSeatNum(id, qidian, zhongdian);
					char seat1[5] = "";
					itoa(seat, seat1, 5);
					suser.chooseticket(qicheid, sour, riqi, id, taid, seat1);
					if (suser.refundticket())
					{
						SENDY;
					}
					else
						SENDN;
				}
				goto label0;
			}
			break;
			
			//��ƱԱ��ǩ
			case 20:
			{
				SENDY;
				RECVMSG;
				//����id;��λ��;���;����ʱ��;�յ�;����ʱ��;�˳���;����;������;
				//���
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";
				char seat[5] = "";
				char nriqi[MD_SIZE] = "";
				int i = 0;
				char sour[20] = "";
				gettnum(qicheid, qidian, zhongdian, sour);

				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qicheid[m] = buf_msg[i];
				cout << qicheid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					seat[m] = buf_msg[i];
				cout << seat << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidian[m] = buf_msg[i];
				cout << qidian << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidiantime[m] = buf_msg[i];
				cout << qidiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdian[m] = buf_msg[i];
				cout << zhongdian << endl; i++;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdiantime[m] = buf_msg[i];
				cout << zhongdiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					taid[m] = buf_msg[i];
				cout << taid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					riqi[m] = buf_msg[i];
				cout << riqi << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					nriqi[m] = buf_msg[i];
				cout << nriqi << endl;
				i++;

				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				Suser suser(id, pw);
				if (suser.carinfo(nriqi, qidian, zhongdian, info))
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
					//delete info
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
					//���Ͳ�ѯ��Ϣ
					send(sock_clt, cinfo, INFO_SIZE, 0);
					RECVMSG;
					char criqi[MD_SIZE] = "";
					char cqicheid[BUS_ID_SIZE] = "";
					char cqidian[STA_SIZE] = "";
					char cqidiantime[TIME_SIZE] = "";
					char czhongdian[STA_SIZE] = "";
					char czhongdiantime[TIME_SIZE] = "";

					int i = 0;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						criqi[m] = buf_msg[i];
					cout << riqi << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqicheid[m] = buf_msg[i];
					cout << qicheid << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidian[m] = buf_msg[i];
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidian[m] = buf_msg[i];
					i++;
					cout << qidian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidiantime[m] = buf_msg[i];
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
						czhongdian[m] = buf_msg[i];
					i++;
					cout << zhongdian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						czhongdiantime[m] = buf_msg[i];
					cout << taid << endl;

					char csour[20] = "";
					if (gettnum(cqicheid, cqidian, czhongdian, csour))
					{
						int cseat = getSeatNum(id, cqidian, czhongdian);
						char cseat1[5] = "";
						itoa(cseat, cseat1, 5);
						suser.chooseticket(qicheid, sour, riqi, id, taid, seat);
						if (suser.changeticket(cqicheid, criqi, cseat1))
						{
							SENDY;
						}
					}
					goto label0;
				}

				char sour1[20] = "";

				if (gettnum(qicheid, qidian, zhongdian, sour1))
				{
					suser.chooseticket(qicheid, sour1, riqi, id, taid, seat);

				}

			}
				break;

			//��ƱԱ�鶩��
			case 21:
			{
				SENDY;
				RECVMSG;
				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				Suser suser(id, pw);
				if (suser.inquireticket(info,buf_msg))
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
					send(sock_clt, cinfo, 1000, 0);
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
				}
			goto label0;
			}
			break;

			//�û���Ʊ
			case 12:
			{
				SENDY;
				RECVMSG;
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";

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

				Nuser nuser(id, pw);
				char sour[20] = "";
				if (gettnum(qicheid, qidian, zhongdian, sour))
				{
					int seat = getSeatNum(id, qidian, zhongdian);
					char seat1[5] = "";
					itoa(seat, seat1, 5);
					nuser.chooseticket(qicheid, sour, riqi, id, taid, seat1);
					if (nuser.buyticket())
					{
						SENDY;
					}
				}
				goto label0;
			}
			break;

			//��ͨ�û���ѯ����
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
				Nuser nuser(id, pw);
				if (nuser.inquireticket(info))
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
					send(sock_clt, cinfo, 1000, 0);
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
				}
			}
			goto label0;
			break;

			//�û���Ʊ
			case 14:
			{
				SENDY;
				RECVMSG;
				//����id;��λ��;���;����ʱ��;�յ�;����ʱ��;�˳���;����;
				//���
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";
				char seat[5] = "";

				int i = 0;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qicheid[m] = buf_msg[i];
				cout << qicheid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					seat[m] = buf_msg[i];
				cout << seat << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidian[m] = buf_msg[i];
				cout << qidian << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidiantime[m] = buf_msg[i];
				cout << qidiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdian[m] = buf_msg[i];
				cout << zhongdian << endl; i++;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdiantime[m] = buf_msg[i];
				cout << zhongdiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					taid[m] = buf_msg[i];
				cout << taid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					riqi[m] = buf_msg[i];
				cout << riqi << endl;
				i++;

				Nuser nuser(id, pw);

				//���ú�����Ʊ
				char sour[20] = "";

				if (gettnum(qicheid, qidian, zhongdian, sour))
				{
					int seat = getSeatNum(id, qidian, zhongdian);
					char seat1[5] = "";
					itoa(seat, seat1, 5);
					nuser.chooseticket(qicheid, sour, riqi, id, taid, seat1);
					if (nuser.refundticket())
					{
						SENDY;
					}
					else
						SENDN;
				}
				goto label0;
			}
			break;

			//�û���ǩ
			case 15:
			{
				SENDY;
				RECVMSG;
				//����id;��λ��;���;����ʱ��;�յ�;����ʱ��;�˳���;����;������;
				//���
				char riqi[MD_SIZE] = "";
				char qicheid[BUS_ID_SIZE] = "";
				char qidian[STA_SIZE] = "";
				char qidiantime[TIME_SIZE] = "";
				char zhongdian[STA_SIZE] = "";
				char zhongdiantime[TIME_SIZE] = "";
				char taid[10] = "";
				char seat[5] = "";
				char nriqi[MD_SIZE] = "";
				int i = 0;
				char sour[20] = "";
				gettnum(qicheid, qidian, zhongdian, sour);

				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qicheid[m] = buf_msg[i];
				cout << qicheid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					seat[m] = buf_msg[i];
				cout << seat << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidian[m] = buf_msg[i];
				cout << qidian << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					qidiantime[m] = buf_msg[i];
				cout << qidiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdian[m] = buf_msg[i];
				cout << zhongdian << endl; i++;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					zhongdiantime[m] = buf_msg[i];
				cout << zhongdiantime << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					taid[m] = buf_msg[i];
				cout << taid << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					riqi[m] = buf_msg[i];
				cout << riqi << endl;
				i++;
				for (int m = 0; buf_msg[i] != ';'; m++, i++)
					nriqi[m] = buf_msg[i];
				cout << nriqi << endl;
				i++;

				char ***info;
				info = new char **[LINE_SIZE];
				for (int i = 0; i < LINE_SIZE; i++)
				{
					info[i] = new char *[ROW_SIZE];
					for (int j = 0; j < ROW_SIZE; j++)
						info[i][j] = new char[UNIT_SIZE];
				}
				Nuser nuser(id, pw);
				if (nuser.carinfo(nriqi, qidian, zhongdian, info))
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
					//delete info
					for (int i = 0; i < LINE_SIZE; i++)
					{
						for (int j = 0; j < ROW_SIZE; j++)
						{
							delete info[i][j];
						}
						delete info[i];
					}
					delete info;
					//���Ͳ�ѯ��Ϣ
					send(sock_clt, cinfo, INFO_SIZE, 0);
					RECVMSG;
					char criqi[MD_SIZE] = "";
					char cqicheid[BUS_ID_SIZE] = "";
					char cqidian[STA_SIZE] = "";
					char cqidiantime[TIME_SIZE] = "";
					char czhongdian[STA_SIZE] = "";
					char czhongdiantime[TIME_SIZE] = "";

					int i = 0;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						criqi[m] = buf_msg[i];
					cout << riqi << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqicheid[m] = buf_msg[i];
					cout << qicheid << endl;
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidian[m] = buf_msg[i];
					i++;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidian[m] = buf_msg[i];
					i++;
					cout << qidian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						cqidiantime[m] = buf_msg[i];
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
						czhongdian[m] = buf_msg[i];
					i++;
					cout << zhongdian << endl;
					for (int m = 0; buf_msg[i] != ';'; m++, i++)
						czhongdiantime[m] = buf_msg[i];
					cout << taid << endl;

					char csour[20] = "";
					if (gettnum(cqicheid, cqidian, czhongdian, csour))
					{
						int cseat = getSeatNum(id, cqidian, czhongdian);
						char cseat1[5] = "";
						itoa(cseat, cseat1, 5);
						nuser.chooseticket(qicheid, sour, riqi, id, taid, seat);
						if (nuser.changeticket(cqicheid,criqi,cseat1))
						{
							SENDY;
						}
					}
					goto label0;
				}

					char sour1[20] = "";

					if (gettnum(qicheid, qidian, zhongdian, sour1))
					{
						nuser.chooseticket(qicheid, sour1, riqi, id, taid, seat);

					}

				}
				break;

			//����Ա��¼
			case 22:
			{
				cout << "����Ա��½" << endl;
				SENDY
				//����ID��password
				char IdPw[ID_SIZE + PW_SIZE];
				recv(sock_clt, IdPw, ID_SIZE + PW_SIZE, 0);

				//����ID��password
				DIV_ID_PW(IdPw);

				Conductor conductor(id, pw);
				//��֤�˺�����
				char ver = conductor.verify(pw);
				if (ver == 'Y')
					SENDY
				else if (ver == '1')
					send(sock_clt, "1", 2, 0);
				else if (ver == '2')
					send(sock_clt, "2", 2, 0);
			}
			break;

			//����Աע��
			case 23:
			{
				cout << "�ͻ�������ر�����..." << endl;
				SENDY;
				goto label5;
			}
			break;

			//����Ա����ƱԱ
			case 24:
			{
				SENDY;
				RECVMSG;
				char innerpw[10] = "";
				char sellid[40] = "";
				int i = 0;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					innerpw[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellid[j] = buf_msg[i];

				char **sellinfo;
				sellinfo = new char *[3];
				for (int i = 0; i < 10; i++)
				{
					sellinfo[i] = new char[10];
				}
				Conductor conductor(id,pw);
				char seinfo[30];
				if (conductor.inquireSuser(innerpw, sellid, sellinfo))
				{
					int p = 0;
					for (int i = 0; i < 3; i++)
						for (int j = 0; sellinfo[i][j] != '\0'; j++, p++)
							seinfo[p] = sellinfo[i][j];
					send(sock_clt, seinfo, 30, 0);
				};
				goto label0;
			}
			break;

			//����Ա������ƱԱ
			case 25:
			{
				SENDY;
				RECVMSG;
				char innerpw[10]="";
				char sellid[10] = "";
				char sellpw[40] = "";
				char sellname[10] = "";
				int i = 0;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					innerpw[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellid[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellpw[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellname[j] = buf_msg[i];
				Conductor conductor(sellid,sellpw);
				if (conductor.addSuser(innerpw, sellid, sellpw, sellname))
				{
					SENDY;
				}
				goto label0;
			}
			break;

			//����Ա����ƱԱid��pw
			case 26:
			{
				SENDY;
				RECVMSG;
				char innerpw[10] = "";
				char sellid[10] = "";
				char nsellid[10] = "";
				char nsellpw[40] = "";
				int i = 0;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					innerpw[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellid[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					nsellid[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					nsellpw[j] = buf_msg[i];
				Conductor conductor(sellid, nsellpw);
				if (conductor.changeSuserInfo(innerpw, sellid, nsellid, nsellpw))
				{
					SENDY;
				}
				goto label0;
			}
			break;

			//����Ա������ƱԱ
			case 27:
			{
				SENDY;
				RECVMSG;
				char innerpw[10] = "";
				char sellid[10] = "";
				int i = 0;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					innerpw[j] = buf_msg[i];
				i++;
				for (int j = 0; buf_msg[i] != ';'; i++, j++)
					sellid[j] = buf_msg[i];
				Conductor conductor(sellid, sellid);
				if (conductor.deleteUser(innerpw, sellid))
				{
					SENDY;
				}
				goto label0;
			}
			break;

			//����Ա���ӳ�
			case 28:
			{

				goto label0;
			}
			break;

			//����Ա���ٳ�
			case 29:
			{
				goto label0;
			}
			break;

			//����Ա��ѯ��
			case 30:
			{
				goto label0;
			}
			break;

			default:
				goto label0;
			}
		}
	}
		while (ret_val > 0 && strcmp(buf_msg, "exit") != 0);
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
}