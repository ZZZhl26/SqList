#include <iostream>

using namespace std;

#define MaxSize 100
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void CreateBTree(BTNode*& b, char* str)
{
	b = nullptr;
	int j(0), k(0), top(0);
	BTNode* St[MaxSize], * p= nullptr;
	while (str[j] != '\0')
	{
		switch (str[j])
		{
		case '(':k = 1; ++top; St[top] = p; break;
		case ')':--top; break;
		case ',':k = 2; break;
		default:
			p = new BTNode();
			p->data = str[j];
			p->lchild = p->rchild = nullptr;
			if (b == nullptr)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		++j;
	}
}

void DestroyBTree(BTNode*& b)
{
	if (b != nullptr)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		delete b;
	}
}

BTNode* FindNode(BTNode* b, ElemType x)
{
	BTNode* p;
	if (b == nullptr)
	{
		return nullptr;
	}
	else if (b->data == x)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, x);
		if (p != nullptr)
		{
			return p;
		}
		else
			return FindNode(b->rchild, x);
	}
}

BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}

BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}

int BTHeight(BTNode* b)
{
	if (b == nullptr)
	{
		return 0;
	}
	else
	{
		int lchild, rchild;
		lchild = BTHeight(b->lchild);
		rchild = BTHeight(b->rchild);
		return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

void DispBTree(BTNode* b)
{
	if (b != nullptr)
	{
		cout << b->data;
		if (b->lchild != nullptr || b->rchild != nullptr)
		{
			cout << "(";
			DispBTree(b->lchild);
			if (b->rchild != nullptr)
			{
				cout << ",";
			}
			DispBTree(b->rchild);
			cout << ")";
		}
	}
}

int main()
{
	BTNode* b, * p, * lp, * rp;
	int h(0);
	char str[] = "A(B(D, E(H(J, K(L, M(, N))))), C(F, G(, I)))";
	CreateBTree(b,str);
	DispBTree(b);
	cout << endl;
	p = FindNode(b, 'M');
	if (p != nullptr)
	{
		lp = LchildNode(p);
		rp = RchildNode(p);
		if (lp != nullptr)
		{
			cout << "M的左孩子是：" << lp->data << endl;
		}
		else  cout << "M无左孩子" << endl;
		if (rp != nullptr)
		{
			cout << "H的右孩子是：" << rp->data << endl;
		}
		else  cout << "H无右孩子" << endl;
	}
	h = BTHeight(b);
	cout << "树b的高度是" << h << endl;
	DestroyBTree(b);
}