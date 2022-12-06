#include<iostream>
using namespace std;
#define MAX 100
struct STACK {
	int sp;
	int elem[MAX];
};
void init(STACK& s)
{
	s.sp = -1;
}
int empty(STACK s)
{
	return s.sp == -1;
}
int Full(STACK s)
{
	return s.sp == MAX - 1;
}
void push(STACK& s, int x)
{
	if (!Full(s))
	{
		s.sp++;
		s.elem[s.sp] = x;
	}
}
void nhap(STACK& s)
{
	int x;
	while (1)
	{
		cout << "Nhap du lieu vao stack: ";
		cin >> x;
		if (x == -99)
			break;
		push(s, x);
	}
}
void xuat(STACK s)
{
	for (int i = s.sp; i >= 0; i--)
	{
		cout << s.elem[i] << "\n";
	}
}

int pop(STACK& s)
{
	if (!Full(s))
		return s.elem[s.sp--];
	return 0;
}
int top(STACK& s)
{
	if (!Full(s))
	{
		return s.elem[s.sp];
	}
	return 0;
}


void main()
{
	STACK s;
	init(s);
	nhap(s);
	cout << "\nStack sau khi nhap la: " << endl;
	xuat(s);
	cout << "\nGia tri ban dau cua stack la: " << top(s);
	pop(s);
	cout << "\nStack sau khi lay gia tri dau la: " << endl;
	xuat(s);
	cout << "\nGia tri ban dau cua stack la: " << top(s);
	system("pasue");
}