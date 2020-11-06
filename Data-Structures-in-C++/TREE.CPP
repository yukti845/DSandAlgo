#include<conio.h>
#inlcude<iostream.h>
#include<stdio.h>
struct Node
{
	int data;
	Node *left;
	Node *right;
};
class BTree
{
	public:
		Node* create_node(int value)
		{
			Node* new_node = new Node;
			if(!new_node)
			{
				cout<<"Memory error"<<endl;
				return NULL;
			}
			new_node->data = value;
			new_node->left = new_node->right = NULL;
			return new_node;
		}

