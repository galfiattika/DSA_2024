#include <stdio.h>
#include "Headers/stack.h"
#include <constants.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char operation[] = "2 5 3 6 + * * 15 / 2 -";

    Stack stack;

    createStack(strlen(operation), &stack);

    printf("Stack is %s\n", (isEmpty(stack)) ? ("EMPTY") : ("NOT EMPTY"));
    printf("Stack is %s\n", (isFull(stack)) ? ("FULL") : ("NOT FULL"));

    const char separators[2] = " ";
    const char operators[] = "+-*/%";

    char *token = strtok(operation, separators);

    while (token != NULL) {
        if (strstr(operators, token)) {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            int result = calculateResultByOperation(val2, val1, token);
            push(&stack, result);
        } else {
            int val = atoi(token);
            push(&stack, val);
        }
        token = strtok(NULL, separators);
    }

    int finalResult = pop(&stack);
    if (!isEmpty(stack)) {
        printf("INCORRECT");
    } else {
        printf("The final result is: %d\n", finalResult);
    }

    deallocate(&stack,strlen(operation));

    return 0;
}


