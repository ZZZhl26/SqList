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
	LinkNode* s;
	for (int i = 0; i < n; ++i)
	{
		s = new LinkNode;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
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
	p->next = nullptr;
}

void InitList(LinkNode*& L)
{
	L = new LinkNode;
	L->next = nullptr;
}

void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = pre->next;
	while (p != nullptr)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

bool ListEmpty(LinkNode* L)
{
	return (L->next == nullptr);
}

int ListLength(LinkNode* L)
{
	int i = 0;
	LinkNode* p = L;
	while (p->next != nullptr)
	{
		++i;
		p = p->next;
	}
	return i;
}

void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(LinkNode* L, int i, ElemType& e)
{
	if (i < 1 || L->next == nullptr)
		return false;
	LinkNode* p = L->next;
	int j = 1;
	while (p != nullptr && j < i)
	{
		++j;
		p = p->next;
	}
	if (p == nullptr)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

int LocateElem(LinkNode* L, ElemType e)
{
	if (L->next == nullptr)
		return false;
	int i = 1;
	LinkNode* p = L->next;
	while (p != nullptr && p->data != e)
	{
		++i;
		p = p->next;
	}
	if (p == nullptr)
		return false;
	else
		return i;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)
{
	if (i < 1)
		return false;
	LinkNode* s, * p = L;
	int j = 0;
	while (j < i - 1 && p != nullptr)
	{
		++j;
		p = p->next;
	}
	if (p == nullptr)
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

bool ListDelete(LinkNode*& L, int i, ElemType& e)
{
	if (i < 1 || L->next == nullptr)
		return false;
	int j = 0;
	LinkNode* p = L;
	while (j < i - 1 && p != nullptr)
	{
		++j;
		p = p->next;
	}
	if (p == nullptr)
		return false;
	else
	{
		LinkNode* q = p->next;
		e = q->data;
		p->next = q->next;
		delete q;
		return true;
	}
}

int main()
{
	LinkNode* L;
	ElemType e;
	cout << "单链表如下：" << endl;
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
	cout << "在第2个位置插入元素y" << endl;
	ListInsert(L, 2, 'y');
	DispList(L);
	ListDelete(L, 5, e);
	cout << "删除第5个元素" << e << endl;
	DispList(L);
	DestroyList(L);
}