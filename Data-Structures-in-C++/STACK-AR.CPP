#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
int stack[100], n=100, top=-1;
void push(int value)
{
	if(top>=n-1)
	cout<<"Stack Overflow"<<endl;
	else
	{
		top++;
		stack[top] = value;
	}
}

void display()
{
	if(top>=0)
	{
		cout<<"Stack elements are: "<<endl;
		for(int i=top; i>=0; i--)
		cout<<stack[i]<<" ";
		cout<<endl;
	}
	else
	cout<<"Stack is empty";
}
void main()
{
	clrscr();
	int choice, val;
	char a = 'y';
	cout<<"1. Push element in stack"<<endl;
	cout<<"2. Pop from the stack"<<endl;
	cout<<"3. Display Stack"<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	do
	{
	switch(choice)
	{
		case 1: cout<<"Enter the element to be pushed: ";
			cin>>val;
			push(val);
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: exit(0);
	}
	cout<<endl<<"Do you want to get the menu again? y/n ";
	cin>>a;
	}while(a=='y' || a=='Y');
	getch();
}
