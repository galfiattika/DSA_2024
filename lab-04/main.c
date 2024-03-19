#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include <time.h>
#include <stdlib.h>

int main() {
    IntArray array;
    createIntArray(10,&array);
    printArray(array);
    for(int i=0;i<array.capacity/2;i++)
    {
        insertAt(&array,i,i+1);

    }
    printArray(array);
    for(int i=array.size+1;!isFull(array);++i)
    {
        if(i%2!=0){
            insertLast(&array,i);
        }
        else{
            insertFirst(&array,i);
        }
    }
    printArray(array);
    printf("\nGive me a number:");
    int num;
    scanf("%d",&num);
    if(search(array,num)<0){
        printf("The number is not part of the array!");
    }
    else{
        printf("The position of the number in the array:%d", search(array, num)+1);
        printf("\nGive me a number to replace it with:");
        int replace;
        scanf("%d",&replace);
        update(&array, search(array,num),replace);
        printArray(array);
    }
    srand(time(0));
    while (!isEmpty(array)){
        deleteItemAt(&array,rand()%(10+1));
    }
    deallocateIntArray(&array);

    return 0;
}
