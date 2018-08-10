#include <cstdlib>
#include <cstdio>
#include "Astar.h"


int main()
{
	char pBuff[] = {
		'0','0','0','0','0','0','0',
		'0','1','1','0','0','1','1',
		'0','S','1','0','1','E','0',
		'0','1','0','0','0','1','0',
		'0','0','0','1','0','1','0'
		
	};
	ASTAR test(pBuff,5,7);
	Point *start=new Point(0, 0);
	Point *end=new Point(2, 3);
	test.show();
	cout << endl;
	Point *root=test.FindPath(start, end, false);
	if (root == NULL)
		cout << "cannot find\n";
	else
		cout << "you get it\n";


	getchar();
	return 0;
}