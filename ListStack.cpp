#include <iostream>

using namespace std;
typedef char ElemType;

typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}ListStNode;

void InitStack(ListStNode*& s)
{
	s = new ListStNode;
	s->next = nullptr;
}

void DestroyStack(ListStNode*& s)
{
	ListStNode* p = s->next;
	while (p != nullptr)
	{
		delete s;
		s = p;
		p = p->next;
	}
	delete s;
}

bool StackEmpty(ListStNode* s)
{
	return (s->next == nullptr);
}

void Push(ListStNode*& s, ElemType e)
{
	ListStNode* p = new ListStNode;
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(ListStNode*& s, ElemType& e)
{
	if (s->next == nullptr)
		return false;
	ListStNode* p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

bool GetTop(ListStNode *& s, ElemType& e)
{
	if (s->next == nullptr)
		return false;
	e = s->next->data;
	return true;
}

int main()
{
	ListStNode* s;
	ElemType e;
	cout << "Á´Õ»ÈçÏÂ£º" << endl;
	InitStack(s);
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	Push(s, 'f');
	while (!StackEmpty(s))
	{
		Pop(s, e);
		cout << e << " ";
	}
	cout << endl;
	DestroyStack(s);
}