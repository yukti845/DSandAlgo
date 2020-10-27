#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int queue[100], n=100, front=-1, rear=-1;
void insert()
{
	int val;
	if(rear == n-1)
	cout<<"Queue Overflow"<<endl;
	else
	{
		if(front == -1)
		front  = 0;
		cout<<"Enter the element to be inserted in queue: ";
		cin>>val;
		rear++;
		queue[rear] = val;
	}
}
void Delete()
{
	if(front==-1 || rear==-1)
	{
		cout<<"Queue Underflow"<<endl
		return;
	}
	else
	{
		cout<<"Deleted element: "<<queue[front]<<endl;
		front++;
	}
}
void Display()
{
	if(front == -1)
	cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"Queue elements are: "<<endl;
		for(int i = front; i<=rear; i++)
		cout<<queue[i]<<" ";
		cout<<endl;
	}
}
