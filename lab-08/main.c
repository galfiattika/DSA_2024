#include <stdio.h>
#include <malloc.h>
#include "Headers/functions.h"

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
    freopen("CON","r",stdin);
    return 0;
}
