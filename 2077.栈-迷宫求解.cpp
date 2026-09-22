#include<iostream>
using namespace std;
#include<stack>
#include<deque>
#include<vector>

struct Coordinates
{
	int x;
	int y;
	Coordinates()
	{
		x = y = 0;
	}
	Coordinates(int px, int py) :x(px), y(py)
	{

	}

	//标准比较就是const引用
	bool operator==(const Coordinates& otherone)const
	{
		return (x == otherone.x && y == otherone.y);	
	}
	bool operator!=(const Coordinates& otherone)const 
	{
		return (x != otherone.x || y != otherone.y);	
	}
};

void findpath(stack<Coordinates >& path, int**& Maze, int& N,  Coordinates& orgin)
{
	Coordinates now;

	//用于存放一个结点周围能走的坐标
	stack<Coordinates >isaccess;

	//同样判断i，上
	int i = now.x - 1, j = now.y;
	Coordinates upon(i, j);
	//若与其源节点相同则忽略
	if (upon != orgin)
	{
		//首先确定在地图内
		if (i >= 0 && i < N && j >= 0 && j < N)
		{
			//若为0，则是可以走的坐标，记录
			if (!Maze[i][j])
			{
				isaccess.push(upon);
			}
		}
	}
	//同样判断i，左
	 i = now.x , j = now.y - 1;
	 Coordinates left(i, j);
	 //若与其源节点相同则忽略
	 if (left != orgin)
	 {
		 //首先确定在地图内
		 if (i >= 0 && i < N && j >= 0 && j < N)
		 {
			 //若为0，则是可以走的坐标，记录
			 if (!Maze[i][j])
			 {
				 isaccess.push(left);
			 }
		 }
	 }
	 //同样判断i，下
	  i = now.x + 1, j = now.y;
	  Coordinates down(i, j);
	  //若与其源节点相同则忽略
	  if (down != orgin)
	  {
		  //首先确定在地图内
		  if (i >= 0 && i < N && j >= 0 && j < N)
		  {
			  //若为0，则是可以走的坐标，记录
			  if (!Maze[i][j])
			  {
				  isaccess.push(down);
			  }
		  }
	  }
	  //同样判断i，右
	   i = now.x , j = now.y + 1;
	   Coordinates right(i, j);
	   //若与其源节点相同则忽略
	   if (right != orgin)
	   {
		   //首先确定在地图内
		   if (i >= 0 && i < N && j >= 0 && j < N)
		   {
			   //若为0，则是可以走的坐标，记录
			   if (!Maze[i][j])
			   {
				   isaccess.push(right);
			   }
		   }
	   }



   while (!isaccess.empty())
   {

	   path.push(isaccess.top());
	   isaccess.pop();
	   Maze[now.x][now.y] = 1;

	   if (path.top() != Coordinates(N - 1, N - 1))
	   {
		   findpath(path, Maze, N, now);
	   }
	   if (path.top() == Coordinates(N - 1, N - 1))
		   return;
   }
   if (isaccess.empty())
	{
	   path.pop();
   }

}

//参数：放可行路径的path，迷宫，迷宫大小，orgin是本次递归的来源的坐标
void findpath(stack<Coordinates>& path, int**& Maze,const int& N, const Coordinates& now, const Coordinates& orgin, bool& found)
{

	//如果找到终点返回
	if (found)return;

	//判断是否到终点
	if (now == Coordinates(N - 1, N - 1))
	{
		found = true;
		return;
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	for (int d = 0; d < 4; d++)
	{
		if (found)return;
		int nx = now.x + dx[d];
		int ny = now.y + dy[d];

		//边界问题
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;

		Coordinates nxt(nx, ny);

		if (nxt == orgin)continue;
		//撞墙
		if (Maze[nx][ny] != 0)continue;

		//将走过的路标记为墙
		Maze[nx][ny] = 1;

		path.push(nxt);

		findpath(path, Maze, N, nxt, now, found);

		if (found)return;

		//回溯：恢复现场
		path.pop();
		Maze[nx][ny] = 0;
	}
}

void print(stack<Coordinates >path)
{
	Coordinates cpos;
	stack<Coordinates >path1;
	if (!path.empty())
	{
		while (!path.empty())
		{
			path1.push(path.top());
			path.pop();
		}

		int i = 0;
		while (!path1.empty())
		{
			cpos = path1.top();
			if ((++i) % 4 == 0)
			{
				cout << "[" << cpos.x << ',' << cpos.y << "]" << "--" << endl;

			}
			else
			{
				cout << "[" << cpos.x << ',' << cpos.y << "]" << "--";
			}
			path1.pop();
		}
		cout << "END" << endl;
	}
	else cout << "no path" << endl;
}

void test01()
{
	int t;
	cin >> t;
	while(t--)
	{
		int N;
		cin >> N;
		int** arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		Coordinates orgin(0, 0);
		stack<Coordinates >path;
		path.push(orgin);

		//findpath(path, arr, N, orgin);
		bool found = false;
		
		findpath(path, arr, N, orgin, Coordinates(-1, -1), found);

		print(path);
	}
}
int main()
{

	test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(