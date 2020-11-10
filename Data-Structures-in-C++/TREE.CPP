#include<conio.h>
#inlcude<iostream.h>
#include<stdio.h>
struct Node
{
	int data;
	Node *left;
	Node *right;
};
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
Node* insert_node(Node* root, int value)
{
	if(root==NULL)
	{
		root = create_node(value);
		return root;
	}
	else if(value < root->data)
	{
		root->left = insert_node(root->left, value);
	}
	else
	{
		root->right = insert_node(root->right, value);
	}
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
void main()
{
	Node* root = NULL;
	clrscr();
	insert_node(root, 94);
	insert_node(root, 62);
	insert_node(root, 20);
	insert_node(root, 39);
	insert_node(root, 58);
	inorder(root);
	getch();
}
