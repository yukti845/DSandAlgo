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
		void display()
		{
			if(front == NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}
			Node *temp = front;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};
void main()
{
	Queue q;
	clrscr();
	q.Enqueue(36);
	q.Enqueue(10);
	q.Enqueue(5);
	q.Enqueue(92);
	q.Enqueue(87);
	q.Enqueue(18);
	q.display();
	q.Dequeue();
	q.Dequeue();
	q.display();
	getch();
}
