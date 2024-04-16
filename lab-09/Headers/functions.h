//
// Created by galfi on 2024. 04. 16..
//

#ifndef LAB_09_FUNCTIONS_H
#define LAB_09_FUNCTIONS_H
#define QUEUE_CAPACITY 25
enum MUKODESISTATUSZ{SUCCESSFUL, DECLINING, SURCHARGE};
typedef struct {
    int ev,honap,nap;
}datum;
typedef struct {
    char nev[15];
    datum indulasiDatum;
    enum MUKODESISTATUSZ mukodesistatusz;
}Market;
typedef struct {
int front, rear,capacity;
Market *elements;
}circularQueue;
char* getFunctionDescription(enum MUKODESISTATUSZ mukodesistatusz);
void readMarketDetails(Market *pMarket);
void printMarketDetails(Market market);
void createQueue(int capacity, circularQueue *queue);
bool isEmpty(circularQueue queue);
bool isFull(circularQueue queue);
void enqueue(circularQueue *queue, Market market);
Market dequeue(circularQueue *queue);
void display(circularQueue queue);
void destroyQueue(circularQueue *queue);
#endif //LAB_09_FUNCTIONS_H
