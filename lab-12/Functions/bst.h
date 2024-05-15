//
// Created by galfi on 2024. 05. 15..
//

#ifndef LAB_12_BST_H
#define LAB_12_BST_H
typedef struct Node {
    int info;
    struct Node *left, *right;
} Node;

Node *createNewNode(int newData);

Node *insertLeft(Node *root, int newData);

Node *insertRight(Node *root, int newData);

void preorderTraversal(Node *root);

void inorderTraversal(Node *root);

void postorderTraversal(Node *root);
#endif //LAB_12_BST_H
