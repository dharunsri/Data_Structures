#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int maxHieght(struct node* node)
{
    if(node == NULL)
        return -1;
    else{
        int lheight = maxHieght(node->left);
        int rheight = maxHieght(node->right);
        
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    struct node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    printf("Height of the tree is %d", maxHieght(root));
    return 0;
}