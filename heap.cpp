/*
* Heap Implementation Max Heap and Min Heap

* Important Points:
! 1. Complete Binary Tree represented in form of array, index '0' is always NULL
! 2. Parent = n/2
! 3. Left child = n*2
! 4. Right child = n*2+1
! 5. Leaf nodes start from n/2 to n
*/

#include <bits/stdc++.h>

using namespace std;

class Heap
{
	vector<int> arr = *new vector<int>;
	int size = 0;
	
	void maxHeap(int i)
	{
		int largest = i;

		int l = i * 2;
		int r = i * 2 + 1;

		if (i * 2 <= size && arr[l] > arr[i])
			largest = l;
		if (i * 2 + 1 <= size && arr[r] > arr[largest])
			largest = r;

		if (arr[largest] != arr[i])
		{
			//* swap elements
			int temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;
			//* invoke maxifyHeap at changed element index
			maxHeap(largest);
		}
	}
	void minHeap(int i)
	{
		int smallest = i;
		int left = i * 2;
		int right = i * 2 + 1;

		if (left <= size && arr[left] < arr[i])
			smallest = left;
		if (right <= size && arr[right] < arr[smallest])
			smallest = right;

		if (smallest != i)
		{
			int temp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = temp;

			minHeap(smallest);
		}
	}

public:
	Heap()
	{
		//* Index 0 is never used
		arr.push_back(-1);
	}
	//* Adds and sorts the max Heap at the same time
	void insertMaxHeap(int value)
	{

		size++;
		int insertedAt = size;
		arr.push_back(value);

		int pIndex = size / 2;
		if (pIndex <= 0)
			return;

		int temp = arr[pIndex];
		//! Check if parent is smaller than the new element and swap
		while (value > temp)
		{
			arr[pIndex] = value;
			arr[insertedAt] = temp;

			if (pIndex / 2 <= 0)
				return;

			insertedAt = pIndex;
			pIndex = pIndex / 2;
			temp = arr[pIndex];
		}
	}
	//* Adds from list and sorts at same time
	void insertMaxHeapFromList(vector<int> arr)
	{
		for (int i : arr)
			insertMaxHeap(i), printArray();
	}
	//* Converts the random array to Max Heap
	void maxifyHeap()
	{
		for (int i = size / 2; i >= 1; i--)
			maxHeap(i);
	}
	//* Converts the random arry to Min Heap
	void minifyHeap()
	{
		for (int i = size / 2; i >= 1; i--)
			minHeap(i);
	}
	int getMaxElement()
	{
		maxifyHeap();
		return arr[1];
	}
	int getMinElement()
	{
		minifyHeap();
		return arr[1];
	}
	//* Randomly adds an element at end of the list
	void randomInsert(int a)
	{
		arr.push_back(a), size++;
	}
	//* Randomly adds list of elements at end of list
	void randomInsertFromList(vector<int> e)
	{
		for (int i : e)
			arr.push_back(i), size++;
	}
	void printArray()

	{
		for (int i = 0; i < size; i++)
			cout << arr[i + 1] << " ";
		cout << endl;
	}
};

int main()
{
	Heap heap;
	heap.randomInsertFromList(vector<int>{1, 4, 3, 7, 8, 9, 10});
	heap.minifyHeap();
	heap.printArray();
	return 0;
}