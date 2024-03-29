//
// Created by galfi on 2024. 03. 27..
//

#include "../Headers/stack.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;

    stack->elements = (char *) malloc(capacity * sizeof(char));
    if (!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

/*bool isEmpty(Stack stack) {
    return stack.top == -1;
}

bool isFull(Stack stack) {
    return stack.top == stack.capacity - 1;
}
*/
void push(Stack *stack, int item) {
    if (isFull(*stack)) {
        printf("The stack is full!\n");
        exit(-3);
    } else {
        stack->elements[++stack->top] = item;
    }
}

int pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf("The stack is empty!\n");
        exit(-4);
    } else {
        int save = stack->elements[stack->top];
        stack->elements[stack->top--] = 0;
        return save;
    }
}

char peek(Stack stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty!\n");
        exit(-4);
    } else {
        char save = stack.elements[stack.top];
        return save;
    }
}

void deallocate(Stack *stack, int capacity) {
    free(stack->elements);
    stack->elements = NULL;
}

void printStack(Stack *stack) {
    printf("Stack tartalma:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->elements[i]); // Feltételezve, hogy az array a veremtartalom tömbje
    }
}
int calculateResultByOperation(int val1, int val2, char *token) {
    char operation = token[0];
    switch (operation) {
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            return val1 / val2;
        case '%':
            return val1 % val2;
        default:
            return 1;
    }
}
