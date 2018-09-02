#include <cstdlib>
#include <cstdio>
#include "Astar.h"
#include<ctime>
#include<fstream>
#include<iostream>
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

const char* file = "C:\\Users\\HP\\Desktop\\map.txt";
//create random map
void createMap(int rows, int cols)
{
	fstream out;
	out.open(file, ios::out);
	out << rows << " " << cols << endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			out <<0<<" ";
		}
		out << endl;
	}
	out.close();
}

int main()
{
	//createMap(10, 10);
	fstream in(file);
	int rows, cols;
	in >> rows >> cols;
	int length = rows*cols;
	int *a = new int[length] {0};
	int data;
	for (int i = 0; i < length; i++)
	{
		in >> data;
		a[i] = data;
	}
	in.close();


	ASTAR test(a,rows,cols);
	Point *start=new Point(5, 0 );
	Point *end=new Point(5,9 );
	test.show();
	cout << endl;
	bool dfs = true;
	Point *root=test.FindPath(start, end, false);
	if (root == NULL)
		cout << "cannot find\n";
	else
		cout << "you get it\n";

	delete[]a;

	system("pause");
	return 0;
}