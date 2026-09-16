#include<iostream>
using namespace std;
#include<stack>

//行编辑，输入一行字符串，若字符为#则执行退格，要求正序输出


void test01__02047()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int len = str.length();
		stack<char> s;
		
		//记录栈的长度
		int s_len = 0;
		for (int i = 0; i < len; i++)
		{
			if(str[i]!='#')
			{
				s.push(str[i]);	
				s_len++;
			}
			else
			{
				if(!s.empty())
				{
					//出栈少一个元素
					s.pop();
					s_len--;
				}
			
			}
		}
		
		//把第一个栈的元素入第二个栈，这样可以正序
		stack<char> s1;

		//忘记入栈了，就这一部分全都没写就出栈
		for (int i = 0; i < s_len; i++)
		{
			s1.push(s.top());
			s.pop();
		}

		if (!s_len)
		{
			cout << "NULL";
		}
		for (int i = 0; i < s_len; i++)
		{
			cout << s1.top();
			//打印栈顶后也不出栈，就一直打印它
			s1.pop();
		}
		cout << endl;
	}
}
int main__02047()
{

	test01__02047();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(