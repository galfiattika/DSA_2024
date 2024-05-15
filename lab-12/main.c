#include <stdio.h>
#include "Functions/bst.h"

int main() {
    /*Node *root = createNewNode(3);
    insertRight(root, 6);
    insertLeft(root->right, 5);
    insertRight(root->right, 8);
    insertRight(insertRight(root->right, 8),100);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");*/
    printf("ujfeladat");
    Node *root2= createNewNode(4);
    insertLeft(root2,2);
    //insertRight(root2->left,2);
    insertLeft(insertLeft(root2->left, 2),0);
    printf("Inorder traversal: ");
    inorderTraversal(root2);
    return 0;
}
