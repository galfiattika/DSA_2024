#include <stdio.h>
#include <constants.h>
#include <stdlib.h>
#include "student.h"
int main() {
    Student_t student1={"Vas Sandor","12345678","Tatabanya",{2004,9,3},0,7.8};
    printStudent(student1);
    printf("\n");
    Student_t student2,student3;
    if(!freopen("student.txt","r",stdin))
    {
        printf(FILE_OPEN_ERROR_MESSAGE);
        exit(FILE_OPEN_ERROR_CODE);
    }
    readStudentDetails(&student2);
    printStudent(student2);
    freopen("CON","r",stdin);
    return 0;
}
