#include <string.h>
#include<winsock2.h>
#include"Client.h"
#include <QMessageBox>
#include <QDebug>
//定义程序中使用的常量      
#define SERVER_ADDRESS "127.0.0.1"  //服务器端IP地址      
#define PORT           6000         //服务器的端口号
#define MSGSIZE        1024         //收发缓冲区的大小      
#pragma comment(lib, "ws2_32.lib")  

Client::Client()
{

    WSAStartup(0x0202, &wsaData);

        // 创建客户端套节字
        sock_clt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET指明使用TCP/IP协议族；
                                                             //SOCK_STREAM, IPPROTO_TCP具体指明使用TCP协议
        // 指明远程服务器的地址信息(端口号、IP地址等)
        memset(&server, 0, sizeof(SOCKADDR_IN)); //清空server内存
        server.sin_family = PF_INET; //声明地址格式是TCP/IP地址格式
        server.sin_port = htons(PORT); //指明连接服务器的端口号，htons()用于 converts values between the host and network byte order
        server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS); //指明连接服务器的IP地址
                                                            //结构SOCKADDR_IN的sin_addr字段用于保存IP地址址
        //连接到服务器
        label:
        //判断连接是否成功
     connect(sock_clt, (struct sockaddr *) &server, sizeof(SOCKADDR_IN));
}

void Client::sendmsg(const char *state, const char *msg, char *rec, int m, int n)
{
    char *st;
    send(sock_clt,state,3,0);
    recv(sock_clt,st,2,0);
    if(st[0] == 'Y')
    {
        send(sock_clt, msg,m,0);
        recv(sock_clt,rec,n,0);
    }
    else if(st[0] == 'N')
    {
        rec = NULL;
    }
}
