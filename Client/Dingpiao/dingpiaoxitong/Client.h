#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define SERVER_ADDRESS "127.0.0.1" //服务器端IP地址
#define PORT           6000         //服务器的端口号
#define MSGSIZE        1024         //收发缓冲区的大小
#pragma comment(lib, "ws2_32.lib")  //链接库

#define SERVER_PORT 6000    //端口号
#define MSG_BUF_SIZE 1024	//buf_msg的长度
#define ID_SIZE 20			//ID长度
#define PW_SIZE 50			//密码长度
#define CD_SIZE 20			//一卡通长度
#define SD_SIZE 20			//学号长度
#define PN_SIZE 20			//手机号长度
#define MD_SIZE 10			//月日长度
#define STA_SIZE 10			//站名长度
#define INFO_SIZE 3000		//查询信息长度
#define UNIT_SIZE 10
#define ROW_SIZE 15
#define LINE_SIZE 20

#define RECVMSG {												\
    memset(buf_msg, 0, MSG_BUF_SIZE);							\
    ret_val = recv(sock_clt, buf_msg, MSG_BUF_SIZE, 0);			\
 }
#define CMPY strcmp(buf_msg, "Y") == 0
#define CMPN strcmp(buf_msg, "N") == 0


class Client
{
public:
   Client();
   void sendmsg(const char *,const char *,char *,int ,int );
private:
   char buf_msg[MSGSIZE];
   WSADATA wsaData;
       //连接所用套节字
       SOCKET sock_clt;
       //保存远程服务器的地址信息
       SOCKADDR_IN server;
       //收发缓冲区

       //成功接收字节的个数
       int ret;

};


#endif // CLIENT_H
