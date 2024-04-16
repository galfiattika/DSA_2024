//
// Created by galfi on 2024. 03. 29..
//

#include "../Headers/circular_queue.h"
#include <stdio.h>
#include <string.h>
void createQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

bool isFull(Queue queue) {
    return (queue.rear + 1) % QUEUE_CAPACITY == queue.front;
}

void enqueue(Queue *queue, const char *item) {
    if (isFull(*queue)) {
        printf("Queue is full. Cannot enqueue more items.\n");
        return;
    }

    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    strcpy(queue->elements[queue->rear], item);
}

char* dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty. No items to dequeue.\n");
        return NULL;
    }

    char* dequeuedItem = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        // Queue becomes empty after dequeueing
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    }
    return dequeuedItem;
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear):\n");
    int i = queue.front;
    do {
        printf("%s ", queue.elements[i]);
        i = (i + 1) % QUEUE_CAPACITY;
    } while (i != (queue.rear + 1) % QUEUE_CAPACITY);
    printf("\n");
}

void destroyQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}