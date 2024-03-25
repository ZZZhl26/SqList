//队列
#include <iostream>

using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue*& q)
{
	q = new SqQueue;
	q->front = q->rear = -1;
}

void DestroyQueue(SqQueue*& q)
{
	delete q;
}

bool QueueEmpty(SqQueue* q)
{
	return (q->front == q->rear);
}

bool enQueue(SqQueue*& q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	++q->rear;
	q->data[q->rear] = e;
	return true;
}

bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)
		return false;
	++q->front;
	e = q->data[q->front];
	return true;
}

int main()
{
	SqQueue* q;
	ElemType e;
	cout << "队列如下：" << endl;
	InitQueue(q);
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	enQueue(q, 'd');
	while (!QueueEmpty(q))
	{
		deQueue(q, e);
		cout << e << " ";
	}
	cout << endl;
	DestroyQueue(q);
}