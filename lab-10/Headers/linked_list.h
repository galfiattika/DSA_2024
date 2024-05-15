//
// Created by galfi on 2024. 05. 08..
//

#ifndef LAB_10_LINKED_LIST_H
#define LAB_10_LINKED_LIST_H
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* newNode(int new_data);
bool isEmpty(Node *head);
void insertAtBeginning(Node** head_ref, int new_data);
void insertAfter(Node* prev_ref, int new_data);
void insertAtEnd(Node** head_ref, int new_data);
void deleteFromBeginning(Node** head_ref);
void deleteFromEnd(Node** head_ref);
void deleteNode(Node** head_ref, int key);
bool searchNode(Node* head_ref, int key);
void sortLinkedList(Node** head_ref);
void orderedList(Node** head_ref, int new_data);
void printList(Node* node);
#endif //LAB_10_LINKED_LIST_H
