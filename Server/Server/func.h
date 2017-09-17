#pragma once
#ifndef  FUNC_H
#define FUNC_H

#include<Winsock2.h>
#include<stdio.h>

void sendMSG(SOCKET sock)
{
	char sendmsg[3] = "OK";
	send(sock, sendmsg, 4, 0);
}

void recvMSG(SOCKET sock)
{
	char recvmsg[3];
	recv(sock, recvmsg, 4, 0);
}
/**************************************************************
�������ƣ�str2int
�βα���������ɵ��ַ�(char*)
����ֵ��int
���ܣ����ַ��е���ת������(Ŀǰ�İ汾��Ϊ�򵥣����õ�ʱ����ȷ���ַ�����һ����)
**************************************************************/
int str2int(char*s)
{
	int a = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		a *= 10;
		a += s[i] - '0';
	}
	return a;
}

/**************************************************************
�������ƣ�gettnum
�βα�����ID(char*)����ʼ��(char*)���յ�(char*)�����(char*)
����ֵ��bool(true���ɹ���false��ʧ��)
���ܣ�ͨ��ID����㣬�յ㣬���Ʊ�ı���
**************************************************************/
bool gettnum(char *id, char *st, char *en, char *source)
{
	MYSQL con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int s, e, station;
	char tem[200];
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	sprintf(tem, "select max(num) from ctov where id='%s'", id);
	mysql_real_query(&con, tem, 48);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	station = str2int(row[0]);
	for (int i = 0; i < station; source[i] = '0', i++);
	source[station] = '\0';
	sprintf(tem, "select num from ctov where id='%s' and station='%s' union select num from ctov where id='%s' and station='%s'", id, st, id, en);
	mysql_real_query(&con, tem, 200);
	res = mysql_store_result(&con);
	row = mysql_fetch_row(res);
	s = str2int(row[0]);
	row = mysql_fetch_row(res);
	e = str2int(row[0]);
	if (s < e)
	{
		for (int i = s - 1; i < e; i++)
		{
			source[i] = '1';
		}
		return true;
	}
	else
		return false;
}
void timeAdd(char *time, char *addM, char *res)
{
	char temp[4][3] = { time[0],time[1],'\0',time[2],time[3],'\0',addM[0],addM[1],'\0',addM[2],addM[3],'\0' };
	int m = str2int(temp[1]) + str2int(temp[3]);
	int h = m / 60;
	m %= 60;
	h += str2int(temp[0]) + str2int(temp[2]);
	sprintf(res, "%02d:%02d", h, m);
}

#endif //  FUNC_H