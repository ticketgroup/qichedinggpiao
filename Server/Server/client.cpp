#include<iostream>
#include"Conductor.h"
using namespace std;
//登录
	char id[6];
	char pass[10];
	receive(id, pass);
	Conductor conductor(id, pass);
	conductor.verify(pass);
//查询售票员
char **out;
	out = new char *[3];
	for (int i = 0; i < 3; i++)
		out[i] = new char [10];
	char p[6];
	char sid[12];
	receive(p, sid);
	conductor.inquireSuser(p, sid, out);
	char all[30];
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; ; k++, j++)
		{
			all[j] = out[i][k];
			if (out[i][k] == '\0')
			{
				j = j + 1, all[j] = ';';
				break;
			}
		}

	}
	all[j + 1] = '$';
	send(all);
//增加用户
	char p[6];
	char id[12];
	char pass[11];
	char name[7];



