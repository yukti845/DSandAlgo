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
		void add_node(int value)
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
	l.add_node(1);
	l.add_node(2);
	l.add_node(3);
	l.display();
	getch();
}






