#include <bits/stdc++.h>

using namespace std;

struct BST
{
	int data;
	BST *left;
	BST *right;
};

class BinaryTree
{

	BST *head = nullptr;
	void printBST(BST *root)
	{
		if (root == NULL)
			return;

		cout << root->data << " ";
		printBST(root->left);
		printBST(root->right);
	}
	BST *recursiveInsert(BST *root, int n)
	{
		if (root == NULL)
		{
			root = getNewNode(n);
			return root;
		}

		if (root->data > n)
			root->left = recursiveInsert(root->left, n);
		else
			root->right = recursiveInsert(root->right, n);

		return root;
	}
	BST *recursiveRemove(BST *root, int n)
	{
		if (root == NULL)
		{
			cout << "Element Not Found" << endl;
			return NULL;
		}
		if (root->data == n)
		{
			cout << "Removed Element : " << n << endl;
			BST *temp = root;
			if (temp->left != NULL && temp->right != NULL)
			{
				root = temp->right;
				root->left = temp->left;
			}
			else if (temp->right != NULL)
				root = temp->right;
			else if (temp->left != NULL)
				root = temp->left;

			delete temp;
			return root;
		}

		if (root->data < n)
			root->right = recursiveRemove(root->right, n);

		if (root->data > n)
			root->left = recursiveRemove(root->left, n);

		return root;
	}
	int recursiveHeight(BST *head)
	{
		if (head == NULL)
		{
			return 0;
		}

		int l = 0, r = 0;
		l = recursiveHeight(head->left);
		r = recursiveHeight(head->right);

		return max(l, r) + 1;
	}
	void preOrderPrint(BST *node)
	{
		if (node == NULL)
			return;
		cout << node->data << " ";

		preOrderPrint(node->left);
		preOrderPrint(node->right);
	}
	void inOrderPrint(BST *node)
	{
		if (node == NULL)
			return;

		preOrderPrint(node->left);
		cout << node->data << " ";
		preOrderPrint(node->right);
	}
	void postOrderPrint(BST *node)
	{
		if (node == NULL)
			return;

		preOrderPrint(node->left);
		preOrderPrint(node->right);
		cout << node->data << " ";
	}
	pair<int, int> recursiveDiameter(BST *node)
	{
		if (node == NULL)
			return pair<int, int>(0, 0);

		auto lTree = recursiveDiameter(node->left);
		auto rTree = recursiveDiameter(node->right);

		pair<int, int> ans;
		ans.first = max(max(lTree.first, rTree.first), (lTree.second + rTree.second + 1));
		ans.second = max(lTree.first, rTree.second) + 1;

		return ans;
	}

public:
	int getHeight()
	{
		recursiveHeight(head);
	}
	int getDiameter()
	{
		pair<int,int> ans = recursiveDiameter(head);
		return max(ans.first, ans.second);
	}
	void insert(int n)
	{
		head = recursiveInsert(head, n);
	}

	void insertFromList(vector<int> arr)
	{
		for (int a : arr)
			insert(a);
	}
	void removeElement(int n)
	{
		head = recursiveRemove(head, n);
	}

	void printTree()
	{
		printBST(head);

		cout << endl
		     << "Height of Tree: " << getHeight() << endl;
	}
	void printOrders()
	{
		cout << "PreOrder ";
		preOrderPrint(head);
		cout << endl;

		cout << "InOrder ";
		inOrderPrint(head);
		cout << endl;

		cout << "PostOrder ";
		postOrderPrint(head);
		cout << endl;
	}
	BST *getNewNode(int n)
	{
		BST *newNode = new BST();
		newNode->data = n;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
};

int main()
{
	BinaryTree bt = *(new BinaryTree());
	bt.insertFromList(vector<int>{7,6,5,4,3,2,1});
	bt.printTree();
	cout << "Diameter: " << bt.getDiameter() << endl;
	return 0;
}