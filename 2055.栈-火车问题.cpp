#include<iostream>
using namespace std;
#include<stack>


bool IsSatisfy(string &str1,string &str2,stack<string>&re)
{
	
	//s1为入站栈，s2为出站栈
	stack<char>s1, s2;
	for (int i = str2.length()-1;i>=0; i--)
	{
		s2.push(str2[i]);
	}

	//用于储存步骤（倒序）
	stack<string>er;

	//用于确定最后所有元素都入栈后若不为空则返回0
	int len1 = 0;
	//退出条件，要么所有元素都入过栈，但栈没清空，要么已经满元素的出站栈被清空了
	while(!s2.empty()&&len1<str1.length())
	{
		s1.push(str1[len1]);
		len1++;
		er.push("in");
		//反复比较两栈栈顶元素是否相等
		//若相等则说明到他该出栈的时候了
		while (!s1.empty()&&s1.top()==s2.top())
		{
			s1.pop();
			s2.pop();
			er.push("out");
		}
	}
	if (s2.empty())
	{
		while (!er.empty())
		{
			re.push(er.top());
			er.pop();
		}
		return true;
	}
	else
	{
		return false;
	}

	
}
void test01()
{
	int n;
	while (cin >> n)
	{
		//储存入站与出站的字符串
		string str1, str2;
		cin >> str1 >> str2;

		//用于储存步骤（正序）
		stack<string>s3;

		if (IsSatisfy(str1, str2, s3))
		{
			cout << "Yes." << endl;
			while (!s3.empty())
			{
				cout << s3.top() << endl;
				s3.pop();
			}

		}
		else cout << "No." << endl;
		cout << "FINISH" << endl;
	}
}
int main()
{

	test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(