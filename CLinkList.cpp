#include<iostream>

using namespace std;

typedef char ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void CreatListF(LinkNode*& L, ElemType a[], int n)
{
	L = new LinkNode;
	L->next = nullptr;
	LinkNode* s, * p = L;
	for (int i = 0; i < n; ++i)
	{
		s = new LinkNode;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
	while (p->next != nullptr)
		p = p->next;
	p->next = L;
}

void CreatListR(LinkNode*& L, ElemType a[], int n)
{
	L = new LinkNode;
	L->next = nullptr;
	LinkNode* s, * p = L;
	for (int i = 0; i < n; ++i)
	{
		s = new LinkNode;
		s->data = a[i];
		p->next = s;
		p = p->next;
	}
	p->next = L;
}

void InitList(LinkNode*& L)
{
	L = new LinkNode;
	L->next = L;
}

void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = pre->next;
	while (p != L)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

bool ListEmpty(LinkNode* L)
{
	return (L->next == L);
}

int ListLength(LinkNode* L)
{
	int i = 0;
	LinkNode* p = L;
	while (p->next != L)
	{
		++i;
		p = p->next;
	}
	return i;
}

void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(LinkNode* L, int i, ElemType& e)
{
	if (i < 1 || L->next == L)
		return false;
	LinkNode* p = L->next;
	if (i == 1)
	{
		e = p->data;
		return true;
	}
	else
	{
		int j = 1;
		while (j < i && p != L)
		{
			++j;
			p = p->next;
		}
		if (p == L)
			return false;
		else
		{
			e = p->data;
			return true;
		}
	}
}

int LocateElem(LinkNode* L, ElemType e)
{
	if (L->next == L)
		return false;
	int i = 1;
	LinkNode* p = L->next;
	while (p != L && p->data != e)
	{
		++i;
		p = p->next;
	}
	if (p == L)
		return false;
	else
		return i;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)
{
	if (i < 1)
		return false;
	LinkNode* s, * p = L;
	if (i == 1 || p->next == L)
	{
		s = new LinkNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
	else
	{
		p = p->next;
		int j = 1;
		while (j < i - 1 && p != L)
		{
			++j;
			p = p->next;
		}
		if (p == L)
			return false;
		else
		{
			s = new LinkNode;
			s->data = e;
			s->next = p->next;
			p->next = s;
			return true;
		}
	}
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)
{
	if (i < 1 || L->next == L)
		return false;
	LinkNode* q, * p = L;
	if (i == 1)
	{
		q = L->next;
		e = q->data;
		L->next = q->next;
		delete q;
		return true;
	}
	else
	{
		p = L->next;
		int j = 1;
		while (j < i - 1 && p != L)
		{
			++j;
			p = p->next;
		}
		if (p == L)
			return false;
		else
		{
			q = p->next;
			e = q->data;
			p->next = q->next;
			delete q;
			return true;
		}
	}
}

int main()
{
	LinkNode* L;
	ElemType e;
	cout << "循环单链表如下：" << endl;
	InitList(L);
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	ListInsert(L, 6, 'f');
	DispList(L);
	cout << "表长为：" << ListLength(L) << endl;
	GetElem(L, 1, e);
	cout << "第1个元素是：" << e << endl;
	cout << "在第1个位置插入元素z" << endl;
	ListInsert(L, 1, 'z');
	DispList(L);
	ListDelete(L, 5, e);
	cout << "删除第5个元素" << e << endl;
	DispList(L);
	DestroyList(L);
}