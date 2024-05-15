//
// Created by galfi on 2024. 05. 15..
//

#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>


Node *createNewNode(int newData) {
    Node *newItem = (Node *) malloc(sizeof(Node *));
    if (!newItem) {
        printf("problem");
        exit(-1);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL;
    return newItem;
}

Node *insertLeft(Node *root, int newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, int newData) {
    root->right = createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%i ", root->info);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%i ", root->info);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%i ", root->info);
    }
}