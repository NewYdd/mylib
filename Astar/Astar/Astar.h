#pragma once
#ifndef A_STAR_H_
#define A_STAR_H_
#include<cstdlib>
#include<cstdio>
#include<list>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
struct Point
{
	//postion
	int x;int y;
	int F,G,H;
	Point *parent;
	int type;
	Point(int _x, int _y) :x(_x), y(_y) { F = G = H = 0; parent = NULL; }
	Point() {}
	Point(int x, int y, Point* father)
	{
		this->x = x;
		this->y = y;
		this->G = 0;
		this->H = 0;
		this->F = 0;
		this->parent = father;
	}
	void CalcF()
	{
		this->F = this->G + this->H;
	}
};

class ASTAR
{
private:
	const int OBLIQUE = 14;
	const int STEP = 10;
	char maze[1000][1000];
	int rows;
	int cols;
	list<Point*> closeList;
	list<Point*> openList;
	 bool CanReach(int x, int y)
	{
		 if (x < 0 || x >= rows || y < 0 || y >= cols)
			 return false;
		 else 
			return maze[x][y] == '0';
	}
	 bool CanReach(Point* start, int x, int y, bool IsIgnoreCorner)
	 {
		 if (!CanReach(x, y) || findInList(closeList,x,y))
			 return false;
		 else
		 {
			 if (abs(x - start->x) + abs(y - start->y) == 1)
				 return true;
			 //如果是斜方向移动, 判断是否 "拌脚"
			 else
			 {
				 if (CanReach(abs(x - 1), y) && CanReach(x, abs(y - 1)))
					 return true;
				 else
					 return IsIgnoreCorner;
			 }
		 }
	 }

	 bool findInList(list<Point*> l, int x, int y)
	 {
		 for (auto point : l)
		 {
			 if (point->x == x&&point->y == y)
				 return true;
		 }
		 return false;
	 }

	 bool findInList(list<Point*> l, Point* p)
	 {
		 for (auto point : l)
		 {
			 if (point->x == p->x&&point->y == p->y)
				 return true;
		 }
		 return false;
	 }
	 int CalcG(Point* start, Point* point)
	 {
		 int G = (abs(point->x - start->x) + abs(point->y - start->y)) == 1 ? STEP : OBLIQUE;
		 int parentG = point->parent != NULL ? point->parent->G : 0;
		 return G + parentG;
	 }
	 int CalcH(Point* end, Point* point)
	 {
		 int step = abs(point->x - end->x) + abs(point->y - end->y);
		 return step * STEP;
	 }
	 void FoundPoint(Point* tempStart, Point* point)
	 {
		 int G = CalcG(tempStart, point);
		 if (G < point->G)
		 {
			 point->parent = tempStart;
			 point->G = G;
			 point->CalcF();
		 }
	 }

	  void NotFoundPoint(Point* tempStart, Point* end, Point* point)
	 {
		 point->parent = tempStart;
		 point->G = CalcG(tempStart, point);
		 point->H = CalcH(end, point);
		 point->CalcF();
		 openList.push_front(point);
	 }

public:
	ASTAR(char *a, int rows, int cols)
	{
		this->cols = cols;
		this->rows = rows;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				this->maze[i][j] = a[i*cols + j];
		}
		//复制到数组中
	}
	
	static bool compare(const Point *a, const Point *b)
	{
		return a->F < b->F;
	}
	Point* FindPath(Point* start, Point* end, bool IsIgnoreCorner) 
	{
		openList.push_front(start);
		while (!openList.empty())
		{
			//find the minest F
			openList.sort(compare);
			Point* tempStart = openList.front();
			openList.pop_front();
			closeList.push_front(tempStart);

			//经过点变换

			maze[tempStart->x] [ tempStart->y] = '*';
			show();
	

			//找到相邻点
			list<Point*>surroundPoints = SurrroundPoints(tempStart, IsIgnoreCorner);
			for(Point *point : surroundPoints)
			{
				//如果该点在列表中，更新G值
				if (findInList(openList,point))
					//计算G值, 如果比原来的大, 就什么都不做, 否则设置它的父节点为当前点,并更新G和F
					FoundPoint(tempStart, point);
				else
					//如果它们不在开始列表里, 就加入, 并设置父节点,并计算GHF
					NotFoundPoint(tempStart, end, point);
			}
			if (findInList(openList, end))
			{
				maze[end->x][end->y] = '*';
				show();
				return openList.front();
			}
		}

		if (findInList(openList, end))
		{
			maze[end->x][end->y] = '*';
			show();
			return openList.front();
		}
		else
			return NULL;
	}


	list<Point*> SurrroundPoints(Point* point, bool IsIgnoreCorner)
	{
		list<Point*> surroundPoints;

		for (int x = point->x - 1; x <= point->x + 1; x++)
			for (int y = point->y - 1; y <= point->y + 1; y++)
			{
				if (CanReach(point, x, y, IsIgnoreCorner))
				{
					Point* p=new Point(x, y);
					surroundPoints.push_front(p);
				}
			}
		return surroundPoints;
	}

	void show()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				
				if(maze[i][j]=='*')
					printf("●");
				else if (maze[i][j] == '0')
					printf("○");
				else
					printf("■");
			}
			cout << endl;
		}
	
		cout << endl;
	}



};
#endif // !A_STRR_H_
