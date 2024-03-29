#include <stdio.h>
#include "Headers/stack.h"
#include "Headers/regular_queue.h"

#include <stdlib.h>
#include <string.h>


int main() {

    /*char operation[] = "2 5 3 6 + * * 15 / 2 -";

    Stack stack;

    createStack(strlen(operation), &stack);

    printf("Stack is %s\n", (isEmpty(stack)) ? ("EMPTY") : ("NOT EMPTY"));
    printf("Stack is %s\n", (isFull(stack)) ? ("FULL") : ("NOT FULL"));

    const char separators[2] = " ";
    const char operators[] = "+/-*%";

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
     */
    Queue queue;
    createQueue(MAX_CAPACITY, &queue);

    while (true) {
        int option;
        printf("\nChoose from the following:\n"
               "\t1. New car arrived\n"
               "\t2. Car removed\n"
               "\t3. Display queue\n"
               "\t4. Exit\n"
               "Your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (!isFull(queue)) {
                    printf("Enter the plate number of the arriving car: ");
                    char carPlate[20];
                    scanf("%s", carPlate);
                    enqueue(&queue, carPlate);
                    printf("Car with plate number %s added to the queue.\n", carPlate);
                } else {
                    printf("The car wash is full. Cannot add more cars at the moment.\n");
                }
                break;
            }
            case 2: {
                if (!isEmpty(queue)) {
                    char *washedCar = dequeue(&queue);
                    printf("Car with plate number %s washed and removed from the queue.\n", washedCar);
                } else {
                    printf("No cars in the queue to wash.\n");
                }
                break;
            }
            case 3:
                display(queue);
                break;
            case 4:
                destroyQueue(&queue);
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
    }



