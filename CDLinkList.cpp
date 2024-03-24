#include<iostream>

using namespace std;

typedef char ElemType;

typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;

void CreatListF(DLinkNode*& L, ElemType a[], int n)
{
	L = new DLinkNode;
	L->next = nullptr;
	DLinkNode* s, * p = L;
	for (int i = 0; i < n; ++i)
	{
		s = new DLinkNode;
		s->data = a[i];
		s->next = L->next;
		if (L->next != nullptr)
			L->next->prior = s;
		s->prior = L;
		L->next = s;
	}
	while (p->next != nullptr)
		p = p->next;
	p->next = L;
	L->prior = p;
}

void CreatListR(DLinkNode*& L, ElemType a[], int n)
{
	L = new DLinkNode;
	L->next = nullptr;
	DLinkNode* s, * p = L;
	for (int i = 0; i < n; ++i)
	{
		s = new DLinkNode;
		s->data = a[i];
		s->prior = p;
		p->next = s;
		p = p->next;
	}
	p->next = L;
	L->prior = p;
}

void InitList(DLinkNode*& L)
{
	L = new DLinkNode;
	L->prior = L->next = L;
}

void DestroyList(DLinkNode*& L)
{
	DLinkNode* pre = L, * p = pre->next;
	while (p != L)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

bool ListEmpty(DLinkNode* L)
{
	return (L->next == L);
}

int ListLength(DLinkNode* L)
{
	int i = 0;
	DLinkNode* p = L;
	while (p->next != L)
	{
		++i;
		p = p->next;
	}
	return i;
}

void DispList(DLinkNode* L)
{
	DLinkNode* p = L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(DLinkNode* L, int i, ElemType& e)
{
	if (i < 1 || L->next == L)
		return false;
	DLinkNode* p = L->next;
	int j = 1;
	while (p != L && j < i)
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

int LocateElem(DLinkNode* L, ElemType e)
{
	if (L->next == L)
		return false;
	int i = 1;
	DLinkNode* p = L->next;
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

bool ListInsert(DLinkNode*& L, int i, ElemType e)
{
	if (i < 1)
		return false;
	DLinkNode* s, * p = L;
	if (p->next == L)
	{
		s = new DLinkNode;
		s->data = e;
		s->next = p;
		p->next = s;
		s->prior = p;
		p->prior = s;
		return true;
	}
	else if (i == 1)
	{
		s = new DLinkNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		s->next->prior = s;
		s->prior = p;
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
			s = new DLinkNode;
			s->data = e;
			s->next = p->next;
			p->next = s;
			s->next->prior = s;
			s->prior = p;
			return true;
		}
	}
}

bool ListDelete(DLinkNode*& L, int i, ElemType& e)
{
	if (i < 1 || L->next == nullptr)
		return false;
	DLinkNode* p = L, * q;
	if (i == 1)
	{
		q = p->next;
		e = q->data;
		p->next = q->next;
		q->next->prior = p;
		delete q;
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
			q = p->next;
			e = q->data;
			p->next = q->next;
			q->next->prior = p;
			delete q;
			return true;
		}
	}
}

int main()
{
	DLinkNode* L;
	ElemType e;
	cout << "循环双单链表如下：" << endl;
	InitList(L);
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	ListInsert(L, 6, 'f');
	DispList(L);
	cout << "表长为：" << ListLength(L) << endl;
	GetElem(L, 4, e);
	cout << "第4个元素是：" << e << endl;
	cout << "在第1个位置插入元素y" << endl;
	ListInsert(L, 1, 'y');
	DispList(L);
	ListDelete(L, 5, e);
	cout << "删除第5个元素" << e << endl;
	DispList(L);
	DestroyList(L);
}