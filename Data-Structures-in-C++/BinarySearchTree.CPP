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
};
