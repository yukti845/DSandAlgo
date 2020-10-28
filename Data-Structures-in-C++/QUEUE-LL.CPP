#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct Node
{
	int data;
	Node *next;
};
class Queue
{
	public:
		Node *front, *rear;
		Queue()
		{
			front = rear = NULL;
		}
		void Enqueue(int value)
		{
			Node *new_node = new Node;
			new_node->data = value;
			if(rear == NULL)
			{
				front = rear = new_node;
				return;
			}
			rear->next = new_node;
			rear = new_node;
		}
		void Dequeue()
		{
			if(front == NULL)
			{
				cout<<"Queue is empty"<<endl;
				return;
			}
			Node *temp = front;
			front = front->next;
			delete(temp);
		}
};
