//
// Created by galfi on 2024. 03. 06..
//

#ifndef LAB_02_STUDENT_H
#define LAB_02_STUDENT_H

enum GENDER{MALE,FEMALE};
typedef struct{
    int year,month,day;
}Date_t;
typedef struct{
    char name[51];
    char neptunCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    enum GENDER gender;
    float examResult;
}Student_t;
void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
#endif //LAB_02_STUDENT_H
