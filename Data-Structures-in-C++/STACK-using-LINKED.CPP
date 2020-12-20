#include<stdio.h>
#include<conio.h>
#include<iostream.h>
struct Node
{
	int data;
	Node *next;
};
class Stack
{
	Node* head;
	Stack()
	{
		front = NULL;
	}
	void push(int value)
	{
		Node *temp;
		temp = new Node;
		temp->data = value;
		if(front==NULL)
		{
			front = temp;
			temp->next=NULL;
		}
		else
		{
			temp->next = front;
			front = temp;
		}
	}
	void pop()
	{
		if(head == NULL)
		{
			cout<<"Stack Underflow"<<endl;
		}
		else
		{
			Node *temp = head;
			head = head->next;
			delete(temp);
		}
	}
	void top()
	{
		cout<<head->data<<endl;
	}
	void display()
	{
		Node* temp;
		if(head == NULL)
		{
			cout<<"Stack is empty"<<endl;
		}
		else
		{
			temp = head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		cout<<endl;
	}
};
void main()
{
	Stack s;
	clrscr();
	s.push(56);
	s.push(72);
	s.push(3);
	s.push(80);
	s.push(19);
	s.display();
	s.top();
	s.pop();
	s.display();
	getch();
}
