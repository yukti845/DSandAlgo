#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node *next;
};

struct Node *add_to_head(struct Node *head,int data)
{
struct Node *t= (struct Node *)malloc(sizeof(struct Node));
t->data= data;
t->next= head;
return t;
}
void print(struct Node *head)
{
while(head != NULL)
{
printf("%d\t",head->data);
head= head->next;
}
}
int main()
{
    struct Node *head;
    int i,j,k;
    // Adding to the head of linked list..
    head= add_to_head(head,10);
    head= add_to_head(head,30);
     head= add_to_head(head,4);
    head= add_to_head(head,36);
     head= add_to_head(head,130);
    head= add_to_head(head,5);
    print(head);
    return 0;
}
