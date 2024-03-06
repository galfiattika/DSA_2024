//
// Created by galfi on 2024. 03. 06..
//

#include "../Headers/student.h"
#include <stdio.h>

void readStudentDetails(Student_t *pStudent) {
    scanf("%\n[^\n]",pStudent->name);
    scanf("\n%s",pStudent->neptunCode);
    scanf("\n%[^\n]",pStudent->birthPlace);
    scanf("%i%i%i",&pStudent->dateOfBirth.year,&pStudent->dateOfBirth.month,&pStudent->dateOfBirth.day);
    scanf("%i",&pStudent->gender);
    scanf("%f",&pStudent->examResult);


}
void printStudent(Student_t student){
    printf("%s\n",student.name);
    printf("%s\n",student.neptunCode);
    printf("%s\n",student.birthPlace);
    printf("%i %i %i\n",student.dateOfBirth.year,student.dateOfBirth.month,student.dateOfBirth.day);
    printf("\t%i\n",student.gender);
    printf("%t.2f\n",student.examResult);

}
