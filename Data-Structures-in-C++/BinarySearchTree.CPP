#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct Node
{
	int data;
	Node* left;
	Node* right;
};
class bst
{
	Node* root;

	Node* makeEmpty(Node* root)
	{
		if(root == NULL)
			return NULL;
		else
		{
			makeEmpty(root->left);
			makeEmpty(root->right);
			delete root;
		}
		return NULL;
	}
	Node*  insert(int value, Node* root)
	{
		if(root == NULL)
		{
			root = new Node;
			root->data = value;
			root->left = root->right = NULL;
		}
		else if(value < root->data)
			root->left = insert(value, root->right);
		else if(value > root->data)
			root->right = insert(value, root->right);
		return root;
	}
	void inorder(Node* root)
	{
		if(root == NULL)
			return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	Node* remove(int value, Node* root)
	{
		Node^ temp;
		if(root == NULL)
			return NULL;
		else if(value < root->data)
			root->left = remove(value, root->left);
		else if(value > root->data)
			root->right = remove(value, root->right);
		else if(root->left && root->right)
		{
			temp = find_min(root->right);
			root->data = temp->data;
			root->right = remove(root->data, root->right);
		}
		else
		{
			temp = root;
			if(root->left == NULL)
				root = root->right;
			else if(root->right == NULL)
				root = root->left;
			delete temp;
		}
		return temp;
	}
	void display()
	{
		inorder(root);
		cout<<endl;
	}
};
void main()
{
	clrscr();
	bst t;
	Node* root = NULL;
	root = t.insert(30, root);
	t.insert(94, root);
	t.insert(39, root);
	t.insert(28, root);
	t.insert(83, root);
	t.display();
	getch();
}

