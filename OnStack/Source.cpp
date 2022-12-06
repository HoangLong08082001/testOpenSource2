#include <iostream>
using namespace std;

#define MAX 100
struct QUEUE {
	int elem[MAX];
	int front;
	int rear;
};
void Init(QUEUE& q)
{
	q.front = -1;
	q.rear = -1;
}
int Empty(QUEUE q)
{
	return q.front == -1 ? 1 : 0;
}
int Full(QUEUE q)
{
	return (q.rear - q.front == MAX - 1);
}
int enQueue(QUEUE& q, int x)
{
	if (!Full(q))
	{
		if (q.front == -1)
			q.front = 0;
		else if(q.rear == MAX -1){
			for (int i = q.front; i <= q.front; i++)
			{
				q.elem[i - q.front] = q.elem[i];
			}
			q.rear = MAX - 1 - q.front;
			q.front = 0;
		}
		q.rear++;
		q.elem[q.rear] = x;
		return q.rear;
	}
	return 0;
}

void nhap(QUEUE &q)
{
	int x;
	while (1)
	{
		cout << "\nNhap du lieu vao Queue(nhap -99 de dung): ";
		cin >> x;
		if (x == -99)
			break;
		enQueue(q, x);
	}
}
void xuat(QUEUE q)
{
	for (int i = q.front; i <= q.rear; i++)
	{
		cout << q.elem[i] << "\t";
	}
}

int DeQueue(QUEUE& q)
{
	if (!Empty(q))
	{
		if (q.front == q.rear)
			Init(q);
		else {
			int t = q.elem[q.front];
			q.front = q.front + 1;
			return t;
		}
	}
	return 0;
}
int getFront(QUEUE &q)
{
	if (!Empty(q))
	{
		int t = q.elem[q.front];
		return t;
	}
	return 0;
}
void main()
{
	QUEUE q;
	Init(q);
	nhap(q);
	cout << "\nQueue sau khi nhap la: " << endl;
	xuat(q);
	cout << "\nPhan tu dau cua Queue la: " << getFront(q) << endl;
	DeQueue(q);
	cout << "\nQueue sau khi lay ra mot phan tu nam o dau la: " << endl;
	xuat(q);
	cout << "\nPhan tu dau cua Queue la: " << getFront(q) << endl;
	system("pasue");
}