#include <stdio.h>
#include <malloc.h>
#include "Headers/functions.h"
#include "Headers/linked_list.h"
int main() {
    /*Alakzat alakzat1={"haromszog", 3,0,0};
    Alakzat alakzat2={"teglalap",4,0,0};
    if(! freopen("ALAKZAT_NEVE.txt", "w", stdout))
    {
        printf("File opening error\n");
        return -1;
    }
    printShapesDetails(alakzat1);
    printShapesDetails(alakzat2);
    freopen("CON","w",stdout);*/
    /*
    Alakzat egyalakzat;
    Verem alakzatok;
    int kapacitas;
    printf("Kerem adja meg a verem kapacitasat: ");
    scanf("%d", &kapacitas);
    createStack(kapacitas,&alakzatok);


    if(!freopen("Shapes.txt","r",stdin))
    {
        printf("File opening error\n");
        return -1;
    }
    for(int i=0;i<kapacitas;i++){
        readShapesDetails(&egyalakzat);
        printShapesDetails(egyalakzat);
        pushStack(&alakzatok,egyalakzat);
    }
    printStack(&alakzatok);
    printf("\n\n");
    if(alakzatok.teteje>=1) {
        Alakzat utolsoAlakzat = popStack(&alakzatok);
        Alakzat utolsoElottiAlakzat = popStack(&alakzatok);
        printf("Az utolso 2 alakzat:\n");
        printShapesDetails(utolsoElottiAlakzat);
        printShapesDetails(utolsoAlakzat);
        if (utolsoAlakzat.konvexitas == utolsoElottiAlakzat.konvexitas) {
            printf("The last two shapes have the same convexity.\n");
        } else {
            printf("The last two shapes have different convexity.\n");
        }
        pushStack(&alakzatok, utolsoElottiAlakzat);
        pushStack(&alakzatok, utolsoAlakzat);
    } else{
        printf("There are not enough shapes in the stack to compare convexity.\n");
    }
    popStack(&alakzatok);
    popStack(&alakzatok);
    printStack(&alakzatok);
    printf("The number of free places in the Stack:\n");
    printf("%d", kapacitas - (alakzatok.teteje +1) );
    destroyStack(&alakzatok);
    freopen("CON","r",stdin);*/
    int firstNumber, secondNumber;
    printf("Enter the first number: ");
    scanf("%d", &firstNumber);
    printf("Enter the second number: ");
    scanf("%d", &secondNumber);
    Node *firstList = NULL;
    Node *secondList = NULL;
    Node *resultList = NULL;
    while (firstNumber > 0) {
        insertAtEnd(&firstList, firstNumber % 10);
        firstNumber /= 10;
    }
    while (secondNumber > 0) {
        insertAtEnd(&secondList, secondNumber % 10);
        secondNumber /= 10;
    }
    int carry = 0;
    while (!isEmpty(firstList) || !isEmpty(secondList)) {
        int first = isEmpty(firstList) ? 0 : firstList->data;
        int second = isEmpty(secondList) ? 0 : secondList->data;
        int sum = first + second + carry;
        insertAtEnd(&resultList, sum % 10);
        carry = sum / 10;
        if (!isEmpty(firstList)) {
            deleteFromBeginning(&firstList);
        }
        if (!isEmpty(secondList)) {
            deleteFromBeginning(&secondList);
        }
    }

    if (carry > 0) {
        insertAtEnd(&resultList, carry);
    }
    int result = 0,power = 1;
    while (!isEmpty(resultList)) {
        result += resultList->data * power;
        power *= 10;
        deleteFromBeginning(&resultList);
    }
    printf("The sum of the two numbers is: %d\n", result);

    return 0;
}
