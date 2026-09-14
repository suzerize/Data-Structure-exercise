#include<iostream>
using namespace std;
#include<string>

typedef struct DLnode
{
	char data;
	DLnode* prior;
	DLnode* next;
}DLnode,*Dlist;

//初始化
void InitDList(Dlist& l)
{
	l = new DLnode;
	l->next = l->prior = NULL;
	l->data = '\0';
}

void FoundDList(Dlist& l)
{
	string str;
	getline(cin, str);
	DLnode* p = l;
	for(int i=0;i<str.size();i++)
	{
		DLnode* newLnode = new DLnode;
		newLnode->data = str[i];
		newLnode->next = NULL;
		p->next = newLnode;
		newLnode->prior = p;
		p = p->next;
	}
	
}

void printDL(Dlist& l)
{
	DLnode* p = l->next;
	if (!p)
	{
		cout << "-" ;
	}
	while (p)
	{
		cout << p->data ;
		p = p->next;
	}
	
	cout << endl;
}

//插入
bool InsertDL(Dlist& l,int i,char e, DLnode*& p)
{
	//仍选择遍历到插入的前一个位置
	int j = 0;
	while (p && j < i)
	{
		p=p->next;
		j++;
	}
	if (j > i || !p)
	{
		cout << "插入失败" << endl;
		return false;
	}

	DLnode* newLnode = new DLnode;
	newLnode->data = e;
	newLnode->next = p->next;
	if(p->next)
	{
		p->next->prior = newLnode;
	}
	newLnode->prior = p;
	p->next = newLnode;

	//最后让指针指向新插入的元素
	p = p->next;
	return true;
}

//删除
bool DeleteDL(Dlist& l, DLnode*& p)
{
	DLnode* r = p;
	if (!p)
	{
		cout << "删除位置不合法" << endl;
		return false;
	}
	p->prior->next = p->next;
	if (p->next)
	{
		p->next->prior = p->prior;

		//指向删除的下一个元素，这个元素相当于新插入的元素
		p = p->next;
		delete r;
		r = NULL;
	}
	else
	{
		delete p;
		p = NULL;
	}
	return true;
}

//判断是否三连可消
//新结论：判断是否大于等于三连可消
//更加新的结论：判断是否大于三连五连100连可消
//p是插入位置
int Isremove( Dlist l,DLnode*& p)
{
	//最后返回可消的最前面的指针
 	int Is = 1;
	if (!p)
	{
		return 0;
	}

	//r作为迭代器，判断是否和新插入的值相等
	DLnode* r = p;
	while (r->next&&r->data==r->next->data)
	{
		
		Is++;
		r = r->next;
	}
	r = p;
	while (r->prior !=l&& r->data == r->prior->data)
	{
	
		Is++;
		r = r->prior ;
		p = r;
	}
	
	//if (r->next&&r->data == r->next->data)
	//{
	//	Is++;
	//	if (r->next->next&&r->data == r->next->next->data)
	//	{
	//		Is++;
	//		
	//	}
	//}

	//
	//if (r->prior!=l&&r->data == r->prior->data)
	//{
	//	Is++;
	//	p = p->prior;
	//	if (r->prior->prior !=l&& r->data == r->prior->prior->data)
	//	{
	//		Is++;
	//		p = p->prior;
	//	}
	//}
		
	if (Is >=3)
	{
		return Is;
	}
	else return 0;

	////插入位置在可消的中间
	//if (p&&p->next&&p->prior&&p->data == p->prior->data && p->data == p->next->data)
	//{
	//	Is = 1;
	//	p = p->prior;
	//}
	////插入位置在可消的最后
	//else if (p&&p->prior&&p->prior->prior&&p->data == p->prior->data && p->data == p->prior->prior->data)
	//{
	//	Is = 1;
	//	p = p->prior->prior;
	//}
	////插入位置在可消的最前面
	//else if (p&&p->next&&p->next->next&&p->data == p->next->data && p->data == p->next->next->data)
	//{
	//	Is = 1;
	//}

}
void test01()
{
	Dlist l;
	InitDList(l);
	FoundDList(l);
	printDL(l);

	DLnode* p = l;
	int i;
	char e;
	cout << "输入插入位置和元素" << endl;
	cin >> i >> e;
	
	InsertDL(l, i, e, p);
	printDL(l);

	cout << "输入插入位置和元素" << endl;
	cin >> i >> e;
	InsertDL(l, i, e, p);
	printDL(l);

}

void test02()
{
	Dlist l;
	InitDList(l);
	FoundDList(l);
	//printDL(l);
	int n;
	cin >> n;
	while (n--)
	{
		int wei;
		char e;
		cin >> wei >> e;
		DLnode* p = l;
		InsertDL(l, wei, e, p);

		
		while(1)
		{
			int count = Isremove(l, p);

			for (int i = 0; i < count; i++)
			{
				DeleteDL(l, p);
			}
			if (!count)break;
		}
		printDL(l);
	}

}
int main()
{
	test02();
	//test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(