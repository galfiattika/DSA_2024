//
// Created by galfi on 2024. 04. 16..
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/functions.h"

char *getFunctionDescription(enum MUKODESISTATUSZ mukodesistatusz) {
    switch (mukodesistatusz) {
        case SUCCESSFUL:return "SUCCESSFUL";
        case DECLINING:return "DECLINING";
        case SURCHARGE:return "SURCHARGE";
        default:return "other";

    }
}

void readMarketDetails(Market *pMarket) {
    scanf("\n%[^\n]",pMarket->nev);
    scanf("\n%d%d%d",&pMarket->indulasiDatum.ev,&pMarket->indulasiDatum.honap,&pMarket->indulasiDatum.nap);
    scanf("\n%i",&pMarket->mukodesistatusz);
}

void printMarketDetails(Market market) {
    printf("\nnev: %s",market.nev);
    printf("\nindulasi datum %d %d %d",market.indulasiDatum.ev,market.indulasiDatum.honap,market.indulasiDatum.nap);
    printf("\nmukodesi statusz %s\n", getFunctionDescription(market.mukodesistatusz));

}


void createQueue(int capacity, circularQueue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (Market *) calloc(25, sizeof(Market));
    if (!queue->elements) {
        printf("Memory allocation failed!\n");
        exit(-2);
    }
}

bool isEmpty(circularQueue queue) {
        return queue.front == -1;
}

bool isFull(circularQueue queue) {

    return (queue.rear + 1) % QUEUE_CAPACITY == queue.front;
}

void enqueue(circularQueue *queue, Market market) {
    if (isFull(*queue)) {
        printf("Queue is full. Cannot enqueue more items.\n");
        return;
    }

    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->elements[queue->rear]=market;
}
Market dequeue(circularQueue *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty. No items to dequeue.\n");
        exit(-3);
    }
    Market dequeuedItem;
    dequeuedItem = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    }
    return dequeuedItem;
}
void display(circularQueue queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear):\n");
    int i = queue.front;
    do {
        printMarketDetails(queue.elements[i]);
        i = (i + 1) % QUEUE_CAPACITY;
        printf("\n");
    } while (i != (queue.rear + 1) % QUEUE_CAPACITY);
    printf("\n");
}
void destroyQueue(circularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

