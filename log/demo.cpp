#include "log.h"
#include <stdio.h>
#include <string.h>

string name = "C:\\Users\\HP\\Desktop\\ydd.txt";

ofstream OsWrite;

int main()
{
	logConfig mylog( name, false, 1000,2); // 1000字节 ，大于则新建文本，两次存储一次
	openFile(name, OsWrite);
	int count =0;
	while (++count < 50)
	{
		record_string("warn", "today is monday", OsWrite, mylog,false);

	}
	system("PAUSE");
	return 0;
}

