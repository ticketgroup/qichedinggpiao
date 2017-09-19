#include"Server.h"
using namespace std;

//清空内存并接收消息
#define RECVMSG {												\
	memset(buf_msg, 0, MSG_BUF_SIZE);							\
	ret_val = ::recv(sock_clt, buf_msg, MSG_BUF_SIZE, 0);		\
 }
//分离账号密码
#define DIV_ID_PW(IdPw) {							\
	int i = 0;										\
	for (; IdPw[i] != ';'; i++)						\
		id[i] = IdPw[i];							\
	i++;											\
	for (int p = 0; IdPw[i] != ';'; i++, p++)		\
		pw[p] = IdPw[i];							\
}
//分离日期出发地和终点
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
//发送字符Y
#define SENDY {						\
	char sendy[10]="Y";				\
	send(sock_clt,sendy,10,0);		\
}
//发送字符N
#define SENDN {						\
	char sendy[10]="Y";				\
	send(sock_clt,sendy,10,0);		\
}
//三维数组转化为一维数组
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


#define SERVER_PORT 6000    //端口号
#define MSG_BUF_SIZE 1024	//buf_msg的长度
#define ID_SIZE 20			//ID长度
#define PW_SIZE 50			//密码长度
#define CD_SIZE 20			//一卡通长度
#define SD_SIZE 20			//学号长度
#define PN_SIZE 20			//手机号长度
#define MD_SIZE 10			//月日长度
#define STA_SIZE 10			//站名长度
#define BUS_ID_SIZE 10
#define TIME_SIZE 10
//查询信息数组的三维
#define UNIT_SIZE 10
#define ROW_SIZE 15
#define LINE_SIZE 20
#define INFO_SIZE 3000

DWORD WINAPI CreateClientThread(LPVOID IpParameter);

//用户数
int nPlayCount;
SOCKET nSocketData[4];

Server::Server()
{
	//初始化服务器
	cout << "正在初始化服务器...\n";

	winsock_ver = MAKEWORD(2, 2);
	addr_len = sizeof(SOCKADDR_IN);
	addr_svr.sin_family = AF_INET;
	addr_svr.sin_port = htons(SERVER_PORT);
	addr_svr.sin_addr.S_un.S_addr = ADDR_ANY;
	memset(buf_ip, 0, IP_BUF_SIZE);

	ret_val = ::WSAStartup(winsock_ver, &wsa_data);
	if (ret_val != 0)
	{
		cerr << "WSA 启动失败!错误代码: " << ::WSAGetLastError() << "\n";
		system("pause");
		exit(1);
	}

	cout << "WSA启动成功...\n";

	sock_svr = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_svr == INVALID_SOCKET)
	{
		cerr << "服务器套接字创建失败!错误代码: " << ::WSAGetLastError() << "\n";
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "服务器套接字创建成功...\n";

	ret_val = ::bind(sock_svr, (SOCKADDR*)&addr_svr, addr_len);
	if (ret_val != 0)
	{
		cerr << "服务器套接字绑定失败!错误代码: " << ::WSAGetLastError() << "\n";
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "服务器套接字绑定成功...\n";

	ret_val = ::listen(sock_svr, SOMAXCONN);
	if (ret_val == SOCKET_ERROR)
	{
		cerr << "服务器套接字监听设置失败!错误代码: " << ::WSAGetLastError() << endl;
		::WSACleanup();
		system("pause");
		exit(1);
	}
	cout << "服务器套接字开始监听...\n";

	cout << "服务器启动成功..." << endl;

	//初始化用户人数
	nPlayCount = 0;
}

Server::~Server()
{
	::closesocket(sock_svr);
	::closesocket(sock_clt);
	::WSACleanup();
	cout << "通信关闭.." << endl;
}

void Server::WaitForClient()
{
	while (true)
	{
		sock_clt = ::accept(sock_svr, (SOCKADDR*)&addr_clt, &addr_len);
		if (sock_clt == INVALID_SOCKET)
		{
			cerr << "接收客户端信息失败!错误代码: " << ::WSAGetLastError() << "\n";
			::WSACleanup();
			system("pause");
			exit(1);
		}
		::inet_ntop(addr_clt.sin_family, &addr_clt, buf_ip, IP_BUF_SIZE);
		cout << "一个新的连接已建立...IP地址: " << buf_ip << ", 端口号: " << ::ntohs(addr_clt.sin_port) << endl;

		//开启新线程
		h_thread = ::CreateThread(nullptr, 0, CreateClientThread, (LPVOID)sock_clt, 0, nullptr);
		nSocketData[nPlayCount] = sock_clt;
		nPlayCount++;
		if (h_thread == NULL)
		{
			cerr << "创建新线程失败...错误代码: " << ::WSAGetLastError() << "\n";
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
				//普通用户注册前验证
			case 7:
			{
				cout << "验证" << endl;
				SENDY;
				char card[20] = "";
				char Sid[20] = "";
				char cdsd[50] = "";
				recv(sock_clt, cdsd, 50, 0);
				//分离一卡通和学号
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

				//验证一卡通和学号
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
			//普通用户注册
			case 8:
			{
				cout << "注册" << endl;
				SENDY;
				RECVMSG;
				cout << buf_msg << endl;
				char card[20] = "";
				char Sid[20] = "";
				char pn[20] = "";
				char pw[50] = "";
				int i = 0;
				//分离各项信息
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
				//添加到数据库
				if (/*reg(card,Sid,pn,pw)*/1)
				{
					SENDY;
					cout << "注册成功!" << endl;
				}
				else
				{
					SENDN
				}
			}
			break;
			//普通用户登录
			case 2:
			{
				cout << "登陆" << endl;
				SENDY
					//接收ID和password
					char IdPw[ID_SIZE + PW_SIZE];
				recv(sock_clt, IdPw, ID_SIZE + PW_SIZE, 0);

				//分离ID和password
				DIV_ID_PW(IdPw);

				//	Nuser nuser(id, pw);
				//验证账号密码
				if (/*nuser.verify(id,pw)*/1)
					SENDY
				else
					SENDN;
				goto label0;
			}
			break;
			//售票员登录
			case 5:
			{
				SENDY

					//接收ID和password
					char IdPw2[ID_SIZE + PW_SIZE];
				::recv(sock_clt, IdPw2, ID_SIZE + PW_SIZE, 0);

				DIV_ID_PW(IdPw2);


				//验证账号密码
				if (1/*判断*/)
				{
					SENDY
				}
				else
					SENDN
					goto label0;
			}

			//普通用户注销
			case 3:
			{
				cout << "客户端请求关闭连接..." << endl;
				SENDY;
				goto label5;
			}
			break;

			//普通用户查询信息
			case 4:
			{
				cout << "查询" << endl;
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
				//测试info数组
				info[0][0] = "qicheid";
				info[0][1] = "shengyup";
				info[0][2] = "qidian#";
				info[1][0] = "汽车id";
				info[1][1] = "剩余";
				info[1][2] = "起点$";
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

			//普通用户更改密码
			case 18:
			{
				SENDY;
				RECVMSG;
				DIV_ID_PW(buf_msg);
				SENDY;
				RECVMSG;
				cout << buf_msg;
				//Nuser nuser(id,pw);
				//下面语句改成数据库操作
				memcpy(pw, buf_msg, strlen(buf_msg));
				pw[strlen(buf_msg)] = '\0';
				if (/*nuser.changePassword(npw)*/1)
				{
					SENDY
						cout << "ID: " << id << "\n新密码" << buf_msg << endl;
				}
				else
					SENDN;
				goto label0;
			}
			break;

			//售票员注销
			case 6:
			{
				cout << "客户端请求关闭连接..." << endl;
				SENDY;
				closesocket(sock_clt);
			}
			break;

			//售票员查询
			case 9:
			{
				cout << "查询" << endl;
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
				//测试info数组
				info[0][0] = "qicheid";
				info[0][1] = "shengyup";
				info[0][2] = "qidian#";
				info[1][0] = "汽车id";
				info[1][1] = "剩余";
				info[1][2] = "起点$";
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

			//用户订票
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
			//查询订单
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
					//三维数组转一维
					char sinfo[1000] = "asd";
					send(sock_clt, sinfo, 1000, 0);
				}
			}
			break;
			//用户退票
			case 14:
			{
				SENDY;
				RECVMSG;
				//拆分
				//调用函数退票

			}
			break;
			//用户改签
			case 15:
			{
				SENDY;
				RECVMSG;
				/////////
			}
			break;
			//管理员登录
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
		cout << "连接关闭..." << endl;
	}
	else if (ret_val < 0)
	{
		cerr << "从客户端接收信息失败...错误代码: " << ::GetLastError() << "\n";
		closesocket(sock_clt);
	}
	send(sock_clt, "tuichu", 10, 0);
label5:
	closesocket(sock_clt);
	return 0;

