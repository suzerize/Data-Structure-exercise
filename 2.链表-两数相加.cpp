#include<iostream>
using namespace std;

typedef struct Lnode
{
	int data;
	Lnode* next;
}Lnode,*LinkList;

void InitLinkList(LinkList& l)
{
	l = new Lnode;
	l->next = NULL;
}

void FoundLinkList(LinkList& l)
{
	int num;
	Lnode* p = l;
	int n;
	cout << "输入有几个元素" << endl;
	cin >> n;

	cin >> p->data;
	for(int i=1;i<n;i++)
	{
		Lnode* newone = new Lnode;
		cin>>newone->data;
		newone->next = NULL;
		p->next = newone;
		p = p->next;
	}
}

LinkList& LinkListadd(LinkList& l1, LinkList& l2)
{
	Lnode* p = l1->next;
	Lnode* q = l2->next;

	int count = 0;
	while (p && q)
	{
		p->data += q->data + count;
		if (p->data >= 10)
		{
			p->data -= 10;
			count = 1;
		}
		else count = 0;
		p = p->next;
		q = q->next;
	}
	while (p)
	{
		p->data += count;
		if (p->data >= 10)
		{
			p->data -= 10;
			count = 1;
		}
		else count = 0;
		p = p->next;
	}
	while (q)
	{
		p->next = q;
		q->data += count;
		if (q->data >= 10)
		{
			q->data -= 10;
			count = 1;
		}
		else count = 0;
		q = q->next;
		p = p->next;
	}
	if (count == 1)
	{
		Lnode* lastone = new Lnode;
		lastone->data = 1;
		lastone->next = NULL;
		p = lastone;
	}
	return l1;
}

void printLink(LinkList& l)
{
	Lnode* p = l;
	cout << "[";
	while (p)
	{
		cout << p->data;
		
		p = p->next;
		if (p)
		{
			cout << ",";
		}
		else cout << "]";
	}
	cout << endl;
}
void test01()
{
	LinkList l1;
	InitLinkList(l1);
	FoundLinkList(l1);
	LinkList l2;
	InitLinkList(l2);
	FoundLinkList(l2);

	printLink(LinkListadd(l1, l2));

}
int main()
{
	
	test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(