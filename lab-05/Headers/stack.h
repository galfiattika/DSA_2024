//
// Created by galfi on 2024. 03. 27..
//

#ifndef LAB_05_STACK_H
#define LAB_05_STACK_H
#include "constants.h"

typedef struct {
    int capacity;
    int top;
    int *elements;
}Stack;
void createStack(int capacity, Stack *stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
char peek(Stack stack);
void deallocate(Stack *stack,int item);
void printStack(Stack *stack);
int calculateResultByOperation(int val1, int val2, char *token);
#endif //LAB_05_STACK_H
