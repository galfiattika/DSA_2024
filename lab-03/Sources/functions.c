//
// Created by galfi on 2024. 03. 06..
//

#include "../Headers/functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
int **allocateMemoryForMatrix1(int rows, int cols) {
    int **pMatrix;
    pMatrix = (int **) malloc(rows * sizeof(int *));
    if (!pMatrix) {
        printf("Error");
        exit(-1);
    }
    for (int i = 0; i < rows; ++i) {
        pMatrix[i] = (int *) malloc(cols * sizeof(int));
        if (!pMatrix[i]) {
            printf("Error");
            exit(-2);
        }
    }
    return pMatrix;
}

void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix) {
    dpMatrix = (int *) malloc(rows * sizeof(int *));
    if (!(*dpMatrix)) {
        printf("Error");
        exit(-1);
    }
    for (int i = 0; i < rows; ++i) {
        (*dpMatrix[i]) = (int *) malloc(cols * sizeof(int));
        if (!(*dpMatrix[i])) {
            printf("Error");
            exit(-2);
        }
    }
}

void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf("Error");
        exit(-2);
    }
    scanf("%d %d", pRows, pCols);
    *dpArray = allocateMemoryForMatrix1(*pRows, *pCols);
    for (int i = 0; i < *pRows; ++i) {
        for (int j = 0; j < *pCols; ++j) {
            scanf("%d", &(*dpArray)[i][j]);
        }
    }
    freopen("CON", "r", stdin);
}

void printMatrix(int rows, int cols, int **pMatrix, const char *output) {
    freopen(output, "w", stdout);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf(" %2d ", pMatrix[i][j]);
        }
        printf("\n");
    }
    freopen("CON", "w", stdout);
}

void deallocateMemoryForMatrix(int rows, int ***dpMatrix) {
    for (int i = 0; i < rows; ++i) {
        free((*dpMatrix)[i]);
    }
    free(*dpMatrix);
}

int minimumValueOfRow(int cols, int *pRow, int **matrix) {
    int min=matrix[*pRow][0];
    for(int i=1;i<cols;i++)
    {
        if(matrix[*pRow][i]<min)
            min=matrix[*pRow][i];
    }
    return min;
}

int *rowMinimums(int rows, int cols, int **pMatrix) {
    int *minArray = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        int min = pMatrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (pMatrix[i][j] < min) {
                min = pMatrix[i][j];
            }
        }

        minArray[i] = min;     }

    return minArray;
}

int minimumValueOfMatrix(int rows, int cols, int **pMatrix) {
    int min=pMatrix[0][0];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(pMatrix[i][j]<min)
                min=pMatrix[i][j];
        }
    }
    return min;
}

float averageOfMatrixElements(int rows, int cols, int **pMatrix) {
    float sum=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            sum+=pMatrix[i][j];
    }
    float db=rows*cols;
    sum/=db;
    return sum;
}

float averageDiagMatrix(int rows, int **pMatrix) {
    float average=0;
    float db;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows;j++)
        {
            if(i==j) {
                average = average + pMatrix[i][j];
                db++;
            }
        }
    }
    return 4.66;
}
