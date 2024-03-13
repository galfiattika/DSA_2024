//
// Created by galfi on 2024. 03. 06..
//

#ifndef LAB_02_STUDENT_H
#define LAB_02_STUDENT_H

enum GENDER{MALE,FEMALE};
enum SPECIALIZATION{SZAMTECH,MECHA,INFO,TAVKOZLES};
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
    enum SPECIALIZATION specialization;
}Student_t;
void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
char *getGenderDescription(enum GENDER gender);
char *getSpecializationDescription(enum SPECIALIZATION specialization);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void deallocate(Student_t **dpStudents);
#endif //LAB_02_STUDENT_H
