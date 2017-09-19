#pragma once
#ifndef TICKET_H
#define TICKET_H

#include<iostream>
#include<string>
using namespace std;


int str2int(char*);
bool getnum(char*, char*, char*, char*);
int getSeatNum(char*, char*,char*);
class Ticket
{
public:
	/**************************************************************
	�������ƣ���Ʊʱ�Ĺ��캯��
	�βα�����ID(char*)��Ʊnum(char*)������(char*(MMDD))����Ʊ��(char*)���˳���(char*),��λ�ţ�char*)
	**************************************************************/
	Ticket(const char*,const char*,const char*,const char*,const char*,const char*);
	/**************************************************************
	�������ƣ���Ʊʱ�Ĺ��캯��
	�βα�����ID(char*)����λ��(char*)��Ʊnum(char*),����(char*(MMDD))
	**************************************************************/
	//Ticket(char*,char*,char*,char*);
	/**************************************************************
	�������ƣ�buy
	�βα�none
	����ֵ��bool(true���ɹ���false��ʧ��)
	���ܣ�����Ʊ
	**************************************************************/
	bool buy();
	/**************************************************************
	�������ƣ�change
	�βα�����ID(char*)������(char*(MMDD))
	����ֵ��bool(true���ɹ���false��ʧ��)
	���ܣ��޸ĳ�Ʊ��Ϣ
	**************************************************************/
	bool change(char*,char*,char*);
	/**************************************************************
	�������ƣ�refund
	�βα�none
	����ֵ��bool(true���ɹ���false��ʧ��)
	���ܣ���Ʊ
	**************************************************************/
	bool refund();
	void getse(char*, char*);
private:
	int seatnum;
	char date[5];
    char *buyer[10];
	char *passenger[10];
	char tNum;
	char id;
};
#endif // !TICKET_H
