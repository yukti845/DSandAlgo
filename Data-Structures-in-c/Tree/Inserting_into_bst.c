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

int main()
{
struct Node *root,*temp;
root= temp= NULL;
root= add_into_bst(root,10);
root= add_into_bst(root,12);
root= add_into_bst(root,34);
root= add_into_bst(root,6);
root= add_into_bst(root,2);
printf("Printing the inorder traversal of binary tree ::\n1. If the inorder traversal of a binary tree is same as it's sorted order \nthan it is a BST.\n");
inorder(root);

}
