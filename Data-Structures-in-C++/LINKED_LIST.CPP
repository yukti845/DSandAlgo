#include<stdio.h>
#include<stdlib.h>
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
			// Searching of the node to be deleted while
			// keeping the record of the previous node
			while(temp != NULL && temp->data != value)
			{
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL)
			{
				prev->next = temp->next;
				free(temp);
			}
		}
		// Search for the given node in the list and return its index
		void search(int value)
		{
			Node* temp = head;
			int index = 0;
			while(temp != NULL)
			{
				if(temp->data == NULL)
				{
					cout<<count;
				}
				temp = temp->next;
				count++;
			}
		}
		void get_count()
		{
			int count = 0;
			Node* temp = head;
			while(temp != NULL)
			{
				count++;
				temp = temp->next;
			}
			cout<<"The number of nodes are: "<<count;
		}
		// function to rotate the linked list by number of rotation=k
		void rotate(int k)
		{
			int count=1;
			if(k==0)
				return;

				Node* temp = head;
				while(count < k && temp != NULL)
				{
					temp = temp->next;
					count++;
				}
				if(temp == NULL)
					return;

				Node* current = temp;
				while(temp->next != NULL)
				temp = temp->next;

				temp->next = head;
				current->next = NULL;
		}
		//function to reverse the linked list
		void reverse()
		{
			Node* current = head;
			Node *prev = NULL, *next = NULL;
			while(current != NULL)
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			head = prev;
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
	l.delete_node(1);
	l.delete_node(3);
	l.display();
	l.reverse();
	l.display();
	l.rotate(3);
	l.display();
	l.get_count();
	getch();
}






