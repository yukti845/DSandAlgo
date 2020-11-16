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
	void display()
	{
		inorder(root);
		cout<<endl;
	}
};
