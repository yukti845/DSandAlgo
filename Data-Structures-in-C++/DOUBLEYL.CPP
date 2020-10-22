#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
struct Node
{
	public:
		int data;
		Node *next;
		Node *prev;
};
class doubly_linked_list
{
	public:
	Node *head, *tail;
	doubly_linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	void insert_begin(int value)
	{
		Node* new_node = new Node;
		Node* temp = head;
		new_node->data = value;
		if(head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
			temp->prev = new_node;
		}
	}
	void insert_end(int value)
	{
		Node* new_node = new Node;
		Node* temp = tail;
		new_node->data = value;
		new_node->next = NULL;
		if(head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
			new_node->prev = temp;
		}
	}
	void display()
	{
		Node* temp = head;
		cout<<"\n Traversal in forward order \n";
		while(temp != NULL)
		{
			cout<<temp->data;
			temp = temp->next;
			cout<<" ";
		}
		cout<<"\n Traversal in reverse order \n";
		temp = tail;
		while(temp != NULL)
		{
			cout<<temp->data;
			temp = temp->prev;
			cout<<" ";
		}
	}
};
void main()
{
	clrscr();
	doubly_linked_list d;
	d.insert_end(6);
	d.insert_end(2);
	d.insert_end(5);
	d.insert_end(7);
	d.insert_begin(1);
	d.insert_begin(3);
	d.display();
	getch();
}



