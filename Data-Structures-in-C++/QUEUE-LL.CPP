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
};