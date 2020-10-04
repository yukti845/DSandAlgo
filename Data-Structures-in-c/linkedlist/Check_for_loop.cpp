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
void print_reverse(struct Node *head)
{
if(head== NULL) return;
print_reverse(head->next);
printf("%d\t",head->data);
}
void find_middle(struct Node *head)
{
if(head== NULL)
printf("List is empty!!!\n");
struct Node *s,*f;
s=f= head;
while(f!= NULL && f->next != NULL)
{
s= s->next;
f= f->next->next;
}
printf("%d\n",s->data);
}

bool  find_loop(struct Node *head)
{
struct Node *s,*f;
if(head== NULL) return false;
s=f=head;
while(f!= NULL && f->next!= NULL)
{
s= s->next;
f= f->next->next;
if(s== f) return true;
}
return false;
}
int main()
{
    struct Node *head;
    int i,j,k;
    bool ans;
    // Adding to the head of linked list..
    head= add_to_head(head,10);
    head= add_to_head(head,30);
     head= add_to_head(head,4);
    head= add_to_head(head,36);
     head= add_to_head(head,130);
    head= add_to_head(head,5);
    head= add_to_head(head,555);
    printf("List is ::\n");
    print(head);
    //printf("Printing them in reverse::\n");
    // print the element of the list
    //print_reverse(head);

    //printf("Finding the middle element of list ::\n");
    //find_middle(head);
    printf("\nCheck if loop exist or not ::\n");
    // Check loop exist or not
    ans=find_loop(head);
    if(ans== true)
    printf("Loop exist!!!\n");
    else printf("Loop not exist\n");
    return 0;
}
