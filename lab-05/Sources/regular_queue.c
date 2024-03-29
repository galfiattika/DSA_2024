//
// Created by galfi on 2024. 03. 29..
//

#include "../Headers/regular_queue.h"
#include "../Headers/constants.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createQueue(int capacity, Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

bool isFull(Queue queue) {
    return (queue.rear + 1) % QUEUE_CAPACITY == queue.front;
}

void enqueue(Queue *queue, char *carPlate) {
    if (isFull(*queue)) {
        printf("Queue is full. Cannot enqueue more cars.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    strcpy(queue->elements[queue->rear], carPlate);

    if (queue->front == -1) {
        queue->front = queue->rear;
    }
}

char *dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty. No cars to dequeue.\n");
        return NULL;
    }

    char *dequeuedCar = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    }
    return dequeuedCar;
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Cars in the queue (front to rear):\n");
    int i = queue.front;
    do {
        printf("%s\n", queue.elements[i]);
        i = (i + 1) % QUEUE_CAPACITY;
    } while (i != (queue.rear + 1) % QUEUE_CAPACITY);
}

void destroyQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
