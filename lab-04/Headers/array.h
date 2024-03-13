//
// Created by galfi on 2024. 03. 13..
//

#ifndef LAB_04_ARRAY_H
#define LAB_04_ARRAY_H
typedef struct {
    int capacity;
    int size;
    int *elements;
}IntArray;
void createIntArray(int capacity, IntArray* pArray);
void printArray(IntArray array);
bool isEmpty(IntArray array);
bool isFull(IntArray array);
void insertFirst(IntArray* pArray, int item);
void insertLast(IntArray* pArray, int item);
void insertAt(IntArray* pArray, int position, int item);
void deleteItemAt(IntArray* pArray, int position);
int search(IntArray pArray, int item);
bool update(IntArray* pArray, int position, int newItem);
void deallocateIntArray(IntArray *pArray);
int getItemAt(IntArray array, int position);
#endif //LAB_04_ARRAY_H
