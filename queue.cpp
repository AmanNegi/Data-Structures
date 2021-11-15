#include <bits/stdc++.h>

using namespace std;

const int queueSize = 5;
int Queue[queueSize];
// Add at end remove from start
int back = -1;

void printQ()
{
	cout << "(Back : " << back << ") : ";
	for (int i = 0; i <= back; i++)
		cout << Queue[i] << " ";
	cout << endl;
}
void enqueue(int e)
{
	cout << " Adding " << e << " : ";
	if (back == queueSize - 1)
	{
		cout << "Queue Overflow\n";
		return;
	}
	Queue[++back] = e;
	printQ();
}
void dequeue()
{
	//Remove first element and reduce back
	cout << " Removing " << Queue[0] << " : ";
	if (back == -1)
	{
		cout << "Queue Underflow\n";
		return;
	}

	for (int i = 1; i <= back; i++)
		Queue[i - 1] = Queue[i];

	back--;
	printQ();
}

int main()
{
	enqueue(4);
	enqueue(5);
	dequeue();
	dequeue();
	dequeue();

	return 0;
}