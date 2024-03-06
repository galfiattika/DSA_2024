#include <stdio.h>
#include "functions.h"
int main() {
    int n,m,**matrix,x;

    readMatrix(&n,&m,&matrix,"matrix.in");
    allocateMemoryForMatrix1(n,m);
    printMatrix(n,m,matrix,"CON");
    scanf("%i",&x);

    printf("%i", minimumValueOfRow(m,&x,matrix));
    printf("\n");
    int *minArray = rowMinimums(n, m, matrix);
    for(int i=0;i<n;i++)
        printf("%i  ",minArray[i]);
    printf("\n");
    printf("%i", minimumValueOfMatrix(n,m,matrix));
    printf("\n");
    printf("%f", averageOfMatrixElements(n,m,matrix));
    printf("\n");
    printf("%f", averageDiagMatrix(n,matrix));
    deallocateMemoryForMatrix(n,&matrix);
    return 0;
}
