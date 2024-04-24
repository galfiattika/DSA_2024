//
// Created by galfi on 2024. 04. 17..
//

#ifndef LAB_01_FLOWERGARDEN_H
#define LAB_01_FLOWERGARDEN_H
#define QUEUE_CAPACITY 25

#include "../Headers/functions.h"

typedef struct {
int front, rear, capacity;
Flower *elements;
}circularQueue;
void createQueue(int capacity, circularQueue *queue);
void destroyQueue(circularQueue *queue);
bool isEmpty(circularQueue queue);
bool isFull(circularQueue queue);
void enqueue(circularQueue *queue,Flower flower);
Flower dequeue(circularQueue *queue);
void display(circularQueue queue);
#endif //LAB_01_FLOWERGARDEN_H
