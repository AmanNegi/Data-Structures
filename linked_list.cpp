#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

class LinkedList
{
private:
	Node *head;

	Node *getNewNode(int v)
	{
		Node *newNode = new Node();
		newNode->value = v;
		newNode->next = NULL;
	}

public:
	int size = 0;
	//* Default Constructor
	LinkedList()
	{
		head = NULL;
	}
	//* Parameterized Constructor
	LinkedList(int a)
	{
		head = getNewNode(a);
		size++;
	}

	void insertElement(int e)
	{
		Node *newNode = getNewNode(e);

		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
		size++;
	}

	void printElements()
	{
		if (head == NULL)
		{
			cout << "Empty Linked List";
			return;
		}
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void deleteElement(int e)
	{
		Node *temp = head;
		Node *prev;
		int depth = 0;
		while (temp->next != NULL)
		{
			if (temp->value == e)
			{
				cout << "Removed Element at depth : " << depth << endl;
				prev->next = temp->next;
				delete temp;
				size--;
				return;
			}
			depth++, prev = temp;
			temp = temp->next;
		}

		cout << "No Element Found" << endl;
	}

	Node *searchElement(int e)
	{
		Node *temp = head;
		int depth = 0;
		while (temp->next != NULL)
		{
			if (temp->value == e)
			{
				cout << "Found Element at depth : " << depth << endl;
			}
			temp = temp->next, depth++;
		}
	}
};

int main()
{
	LinkedList arr = *(new LinkedList(4));
	arr.insertElement(25);
	arr.insertElement(70);

	arr.printElements();
	arr.deleteElement(25);
	arr.printElements();

	return 0;
}
