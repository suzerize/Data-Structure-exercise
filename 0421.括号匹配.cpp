#include<iostream>
using namespace std;
#include<stack>

void test01__0421()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int len = str.length();
		stack<char> s;
		int isTrue = 1;
		for (int i = 0; i < len; i++)
		{
			char e = str[i];
			//左括号入栈
			if (e == '(' || e == '[' || e == '{')
			{
				s.push(e);
				continue;
			}
			//右括号做匹配
				if (e == ')')
				{
					//匹配成功出栈
					if (!s.empty()&&s.top() == '(')
					{
						s.pop();
					}
					//匹配失败就错误了，需要结束循环
					else 
					{
						isTrue = 0;
						break;
					}
				}
				if (e == ']')
				{
					if (!s.empty() && s.top() == '[')
					{
						s.pop();
					}
					else 
					{
						isTrue = 0;
						break;
					}
				}
				if (e == '}')
				{
					if (!s.empty() && s.top() == '{')
					{
						s.pop();
					}
					else 
					{
						isTrue = 0;
						break;
					}
				}
			
		}

		//两个条件都满足才正确
		if (s.empty()&&isTrue)
		{
			cout << "ok" << endl;
		}
		else cout << "error" << endl;
	}
}
int main__0421()
{

	test01__0421();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(