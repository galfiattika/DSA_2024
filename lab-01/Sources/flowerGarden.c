//
// Created by galfi on 2024. 04. 17..
//

#include <malloc.h>
#include <stdio.h>
#include "flowerGarden.h"

void createQueue(int capacity, circularQueue *queue) {
    queue->capacity=capacity;
    queue->front=queue->rear=-1;
    queue->elements=(Flower*)calloc(25,sizeof (Flower));
    if(!queue->elements){
        printf("hiba");
        exit(-2);
    }
}

void destroyQueue(circularQueue *queue) {
    queue->front=-1;
    queue->rear=-1;
}

bool isEmpty(circularQueue queue) {
    return queue.front==-1;
}

bool isFull(circularQueue queue) {
    return (queue.rear+1)%QUEUE_CAPACITY==queue.front;
}

void enqueue(circularQueue *queue, Flower flower) {
    if(isFull(*queue)){
        printf("hiba");
        return;
    }
    if(isEmpty(*queue))
        queue->front=0;
    queue->rear=(queue->rear+1)%QUEUE_CAPACITY;
    queue->elements[queue->rear]=flower;
}

Flower dequeue(circularQueue *queue) {
    if(isEmpty(*queue)){
        printf("hiba");
        exit(-3);
    }
    Flower dequeuedItem;
    dequeuedItem=queue->elements[queue->front];
    if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
    } else{
        queue->front=(queue->front+1)%QUEUE_CAPACITY;
    }
    return dequeuedItem;
}

void display(circularQueue queue) {
    if(isEmpty(queue)){
        printf("hiba");
        return;
    }
    printf("elements:");
    int i=queue.front;
    do{
        printViragDetails(queue.elements[i]);
        i=(i+1)%QUEUE_CAPACITY;
        printf("\n");
    } while (i!=(queue.rear+1)%QUEUE_CAPACITY);
    printf("\n");

}
