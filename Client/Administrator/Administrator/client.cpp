#include <string.h>
#include<winsock2.h>
#include"Client.h"
#include <QMessageBox>
#include <QDebug>
//���������ʹ�õĳ���      
#define SERVER_ADDRESS "127.0.0.1"  //��������IP��ַ      
#define PORT           6000         //�������Ķ˿ں�
#define MSGSIZE        1024         //�շ��������Ĵ�С      
#pragma comment(lib, "ws2_32.lib")  

Client::Client()
{

    WSAStartup(0x0202, &wsaData);

        // �����ͻ����׽���
        sock_clt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INETָ��ʹ��TCP/IPЭ���壻
                                                             //SOCK_STREAM, IPPROTO_TCP����ָ��ʹ��TCPЭ��
        // ָ��Զ�̷������ĵ�ַ��Ϣ(�˿ںš�IP��ַ��)
        memset(&server, 0, sizeof(SOCKADDR_IN)); //���server�ڴ�
        server.sin_family = PF_INET; //������ַ��ʽ��TCP/IP��ַ��ʽ
        server.sin_port = htons(PORT); //ָ�����ӷ������Ķ˿ںţ�htons()���� converts values between the host and network byte order
        server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS); //ָ�����ӷ�������IP��ַ
                                                            //�ṹSOCKADDR_IN��sin_addr�ֶ����ڱ���IP��ַַ
        //���ӵ�������
        label:
        //�ж������Ƿ�ɹ�
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
