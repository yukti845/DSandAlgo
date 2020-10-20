#include<stdio.h>
#include<iostream.h>
#include<conio.h>
struct Node
{
	public:
	int data;
	Node *next;
};
class linked_list
{
	public:
		Node *head, *tail;
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		void add_node_end(int value)
		{
			Node *temp = new Node;
			temp->data = value;
			temp->next = NULL;

			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		void add_node_begin(int value)
		{
			Node *new_node = new Node;
			new_node->data = value;
			new_node->next = head;
			head = new_node;
		}
		//Deleting a node when given data of the node
		void delete_node(int value)
		{
			Node* temp = head;
			Node* prev;
			if(temp!=NULL && temp->data == value)
			{
				head = temp->next;
				free(temp);
			}
			
		void display()
		{
			Node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
};
void main()
{
	clrscr();
	linked_list l;
	l.add_node_end(1);
	l.add_node_end(2);
	l.add_node_end(3);
	l.add_node_begin(4);
	l.add_node_begin(9);
	l.display();
	getch();
}






