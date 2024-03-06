//
// Created by galfi on 2024. 03. 06..
//

#ifndef DSA_FUNCTIONS_H
#define DSA_FUNCTIONS_H
int** allocateMemoryForMatrix1(int rows, int cols);
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
void deallocateMemoryForMatrix(int rows, int ***dpMatrix);
int minimumValueOfRow(int cols, int *pRow,int **matrix);
int* rowMinimums(int rows, int cols, int **pMatrix);
int minimumValueOfMatrix(int rows, int cols, int **pMatrix);
float averageOfMatrixElements(int rows, int cols, int **pMatrix);
float averageDiagMatrix(int rows, int **pMatrix);
#endif //DSA_FUNCTIONS_H
