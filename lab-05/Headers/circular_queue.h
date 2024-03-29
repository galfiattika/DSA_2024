//
// Created by galfi on 2024. 03. 29..
//

#ifndef LAB_05_CIRCULAR_QUEUE_H
#define LAB_05_CIRCULAR_QUEUE_H
#define QUEUE_CAPACITY 6
#define STRING_LENGTH 50
typedef struct {
    int front, rear;
    char elements[QUEUE_CAPACITY][STRING_LENGTH];
} Queue;

void createQueue(Queue *queue);
bool isEmpty(Queue queue);
bool isFull(Queue queue);
void enqueue(Queue *queue, const char *item);
char* dequeue(Queue *queue);
void display(Queue queue);
void destroyQueue(Queue *queue);
#endif //LAB_05_CIRCULAR_QUEUE_H
