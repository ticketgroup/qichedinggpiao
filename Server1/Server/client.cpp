#include<iostream>
#include"Conductor.h"
using namespace std;
//��¼
	char id[6];
	char pass[10];
	receive(id, pass);
	Conductor conductor(id, pass);
	conductor.verify(pass);
//��ѯ��ƱԱ
char **out;
	out = new char *[3];
	for (int i = 0; i < 3; i++)
		out[i] = new char [10];
	char p[6];
	char sid[12];
	conductor.inquireSuser(p, sid, out);

