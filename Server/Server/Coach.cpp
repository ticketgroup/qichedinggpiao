#include "Coach.h"

Coach::Coach(int i)
{
	mysql_init(&con);
	mysql_real_connect(&con, "localhost", "root", "111111", "coach", 3306, NULL, 0);
	id = i;
}
