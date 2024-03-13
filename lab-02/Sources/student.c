//
// Created by galfi on 2024. 03. 06..
//

#include "../Headers/student.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

void readStudentDetails(Student_t *pStudent) {
    scanf("\n%[^\n]",pStudent->name);
    scanf("\n%s",pStudent->neptunCode);
    scanf("\n%[^\n]",pStudent->birthPlace);
    scanf("%d%d%d",&pStudent->dateOfBirth.year,&pStudent->dateOfBirth.month,&pStudent->dateOfBirth.day);
    scanf("%i",&pStudent->gender);
    scanf("%f",&pStudent->examResult);
    scanf("%i",&pStudent->specialization);


}
void printStudent(Student_t student){
    printf("%s\n",student.name);
    printf("%s\n",student.neptunCode);
    printf("%s\n",student.birthPlace);
    printf("%d %d %d\n",student.dateOfBirth.year,student.dateOfBirth.month,student.dateOfBirth.day);
    printf("%s\n", getGenderDescription(student.gender));
    printf("%.2f\n",student.examResult);
    printf("%s\n",getSpecializationDescription(student.specialization));

}

char *getGenderDescription(enum GENDER gender) {
    switch (gender) {
        case MALE: return "Male";
        case FEMALE: return "Female";
        default:return "error";

    }
}

char *getSpecializationDescription(enum SPECIALIZATION specialization) {
    switch (specialization) {
        case SZAMTECH: return "Szamtech";
        case INFO:return "Info";
        case TAVKOZLES: return "Tavkozles";
        case MECHA: return "Mecha";

    }
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    (*dpStudents)=(Student_t*)malloc(numberOfStudents*sizeof (Student_t));
    if(!(*dpStudents)){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    if(!freopen(input,"r",stdin))
    {
        printf(FILE_OPEN_ERROR_MESSAGE);
        exit(FILE_OPEN_ERROR_CODE);
    }
    scanf("%i",numberOfStudents);
    allocateMemoryForStudents(dpStudents, *numberOfStudents);
    for(int i=0;i<*numberOfStudents;i++)
    {
        readStudentDetails(&((*dpStudents)[i]));
    }
    freopen("CON","r",stdin);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    (freopen(destination,"w",stdout));
    for(int i=0;i<numberOfStudents;i++)
    {
        printStudent(pStudents[i]);
        printf("\n");
    }
    freopen("CON","w",stdout);
}

void deallocate(Student_t **dpStudents) {
free(*dpStudents);
*dpStudents=NULL;
}
