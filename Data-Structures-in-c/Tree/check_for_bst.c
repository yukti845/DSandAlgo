#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node *left,*right;
};

struct Node * add_into_bst(struct Node *root,int data)
{
if(root== NULL)
{
root= (struct Node *)malloc(sizeof(struct Node));
root->left = root->right= NULL;
root->data= data;
return root;
}
if(root->data < data)
root->right=add_into_bst(root->right,data);
else root->left= add_into_bst(root->left,data);
return root;

}
void inorder(struct Node *root)
{
if(root== NULL) return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}

void preorder(struct Node *root)
{
if(root== NULL) return;
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct Node *root)
{
if(root== NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}

bool check_data_exist(struct Node *root,int data)
{
if(root== NULL) return false;
if(root->data < data) return check_data_exist(root->right,data);
else if(root->data > data) return check_data_exist(root->left,data);
else return root; // found the element...
}

bool check_if_bst(struct Node *root,int mini,int maxi)
{
if(root== NULL) return true;
if(root->data >= maxi || root->data < mini) return false;
return check_if_bst(root->left,mini,root->data) && check_if_bst(root->right,root->data,maxi);
}
int main()
{
// mini is minimum and maxi : maximum value
int mini= -9999,maxi= 99999;
struct Node *root,*temp;
root= temp= NULL;
root= add_into_bst(root,10);
root= add_into_bst(root,12);
root= add_into_bst(root,34);
root= add_into_bst(root,6);
root= add_into_bst(root,2);

printf("\nInorder traversal\n");
inorder(root);
/*
printf("\nCheck if value = 2 exist");
if(check_data_exist(root,2)== true) printf("\nIt exists!!!");
else printf("\nNot exist!!!");

printf("\nCheck if value = 15 exist");
if(check_data_exist(root,15)== true) printf("\nIt exists!!!");
else printf("\nNot exist!!!");
*/

if(check_if_bst(root,mini,maxi)== true)
printf("\nIt is binary search tree !!!");
else printf("\nNot a binary Tree!!!");

}
