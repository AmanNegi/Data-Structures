#include <bits/stdc++.h>

using namespace std;

int currentSize = 5;
int *st, top = -1;

int getSize()
{
	return top + 1;
}

void printStack()
{
	int size = getSize();
	for (int i = 0; i < currentSize; i++)
		cout << st[i] << " ";
	cout<<"Size : "<<size << endl;
}

void push(int element)
{
	if (top >= currentSize - 1)
	{
		int temp = currentSize;
		currentSize = currentSize * 2;
		int *nSt = new int[currentSize]{};

		for (int i = 0; i < temp; i++)
			nSt[i] = st[i];
		st = nSt;
	}
	else if (top == -1)
	{
		cout << "Initializing Array as: ";
		int *nSt = new int[currentSize]{};
		for (int i = 0; i < currentSize; i++)
			cout << nSt[i] << " ";
		cout << endl;
		st = nSt;
	}

	st[++top] = element;

	printStack();
}

void pop()
{
	if (top == -1)
		cout << "Invalid Action";
	else
		st[top--] = 0;

	printStack();
}

int topE()
{
	if (top == -1)
		cout << "Invalid Action";
	else
		return st[top];
}

int main()
{

	push(4);
	push(5);
	push(2);
	push(1);
	push(4);

	push(5);
	push(2);
	pop();
	push(1);

	return 0;
}