#include<iostream>

using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreatList(SqList*& L, ElemType a[], int n)
{
	L = new SqList;
	for (int i = 0; i < n; ++i)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

void InitList(SqList*& L)
{
	L = new SqList;
	L->length = 0;
}

void DestroyList(SqList*& L)
{
	delete L;
}

bool ListEmpty(SqList* L)
{
	return (L->length == 0);
}

int ListLength(SqList* L)
{
	return (L->length);
}

void DispList(SqList* L)
{
	for (int i = 0; i < L->length; ++i)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
}

bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length&& L->data[i] != e)
	{
		++i;
	}
	if (i == L->length)
		return 0;
	else
		return (i + 1);
}

bool ListInsert(SqList*& L, int i, ElemType e)
{
	if (i<1 || L->length == MaxSize || i>L->length + 1)
		return false;
	--i;
	for (int j = L->length; j > i; --j)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	++L->length;
	return true;
}

bool ListDelete(SqList*& L, int i, ElemType& e)
{
	if (i<1 || i>L->length || L->length == 0)
		return false;
	e = L->data[--i];
	for (int j = i; j < L->length - 1; ++j)
	{
		L->data[j] = L->data[j + 1];
	}
	--L->length;
	return true;
}

int main()
{
	SqList* L;
	ElemType e;
	cout << "顺序表如下：" << endl;
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
	cout << "在第2个位置插入元素z" << endl;
	ListInsert(L, 2, 'z');
	DispList(L);
	ListDelete(L, 5, e);
	cout << "删除第5个元素" << e << endl;
	DispList(L);
	DestroyList(L);
}