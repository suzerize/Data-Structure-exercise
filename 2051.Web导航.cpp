#include<iostream>
using namespace std;
#include<stack>

bool BACK(stack<string>&f, stack<string>&b, string &now)
{
	//if (b.top() == now)
	//{
	//	b.pop();
	//}

	//我要在后页栈不为空的条件下
	if(!b.empty())
	{
		//当前入前页
		f.push(now);
		//当前更新为后页的顶，也就是后一个（而不可能是同一个）
		now = b.top();
		//当前页需要出栈
		b.pop();

	}
	//否则thank you
	else
	{
		return false;
	}
	return true;
}
bool FORWARD(stack<string>&f, stack<string>&b, string &now)
{
	//if (f.top() == now)
	//{
	//	f.pop();
	//}
	//我要在前页栈不为空的条件下
	if(!f.empty())
	{
		//当前入后页
		b.push(now);
		//当前更新为前页的顶，也就是前页栈里的后一个（而不可能是同一个）
		now = f.top();
		//当前页需要出栈
		f.pop();
	}
	else
	{
		return false;
	}
	return true;
}
void VISIT(stack<string>& f, stack<string>& b, string& now, string& newone)
{
	//处理初始情况，访问第一个的时候不能入栈当前，当前什么也没有初始为空
	if (now != "")
	{
		b.push(now);
	}
	now = newone;
	//出栈前检查是否存在
	//清空栈
	while (!f.empty())
	{
		f.pop();
	}
}
void QUIT(stack<string>&f, stack<string>&b, string &now)
{
	while (!f.empty())
	{
		f.pop();
	}
	while (!b.empty())
	{
		b.pop();
	}
	now = "";
}
void test01()
{
	stack<string> forS, backS;
	string now = "";
	string newone = "https://www-acm-org.webvpn.szu.edu.cn/";
	VISIT(forS, backS, now,newone);
	string opera;
	//发现输入string会按空格分开，很好了
	//cout << opera;

	//根据输入执行对应操作
	while(cin >> opera&&opera!="QUIT")
	{
		if (opera == "BACK")
		{
			if (BACK(forS, backS, now))
			{
				cout << now << endl;
			}
			else cout << "Ignored"<<endl;

		}
		else if (opera == "FORWARD")
		{
			if (FORWARD(forS, backS, now))
			{
				cout << now << endl;
			}
			else cout << "Ignored"<<endl;
		}
		else if (opera == "VISIT")
		{
			cin >> newone;
			VISIT(forS, backS, now,newone);
			cout << now << endl;
		}

	}
	QUIT(forS, backS, now);
}
int main()
{

	test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(



//样例，需要则粘到别的地方上用
/*
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT
*/

/*
http://acm.ashland.edu/
http://acm.baylor.edu/acmicpc/
http://acm.ashland.edu/
https://www-acm-org.webvpn.szu.edu.cn/
Ignored
http://acm.ashland.edu/
http://www.ibm.com/
http://acm.ashland.edu/
https://www-acm-org.webvpn.szu.edu.cn/
http://acm.ashland.edu/
*/