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
void main()
{
	int choice;
	cout<<"1. Insert element to queue"<<endl;
	cout<<"2. Delete element from queue"<<endl;
	cout<<"3. Display elements of the queue"<<endl;
	cout<<"4. Exit"<<endl;
	do
	{
	cout<<"Enter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: insert();
			break;
		case 2: Delete();
			break;
		case 3: display();
			break;
		case 4: exit(0);
	}
	}while(choice<4);
}

