#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(struct BstNode* root, int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(newNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(root,data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

int Min(struct BstNode* root){
    if(root == NULL){
        printf("Tree is Empty. \n");
        return -1;
        
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int Max(struct BstNode* root){
    if(root == NULL){
        printf("Tree is Empty. \n");
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int Min_Recursion(struct BstNode* root){
    if(root == NULL){
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return Min_Recursion(root->left);
}

int Max_Recursion(struct BstNode* root){
    if(root == NULL){
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return Max_Recursion(root->right);
}

int main(){
    struct BstNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 12);
    root = Insert(root, 100);
    root = Insert(root, 1);
    root = Insert(root, 102);
    root = Insert(root, 40);
    root = Insert(root, 13);
    int min,max;
    min = Min(root);
    max = Max(root);
    printf("Minimum value: %d \n", min);
    printf("Maximum value: %d \n",max);
    int minR, maxR;
    minR = Min_Recursion(root);
    printf("Minimum using recursion: %d \n", minR);
    maxR = Max_Recursion(root);
    printf("Maximum using recursion: %d \n", maxR);
    return 0;
    
}