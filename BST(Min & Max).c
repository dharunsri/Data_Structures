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
    else if(root->data <= data){
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
    }
    while(root != NULL){
        root = root->left;
    }
    return root->data;
}

int Max(struct BstNode* root){
    if(root == NULL){
        printf("Tree is Empty. \n");
    }
    while(root != NULL){
        root = root->right;
    }
    return root->data;
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
    Min(root);
    printf("Min %d", root->data);
    Max(root);

    return 0;

}
