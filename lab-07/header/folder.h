//
// Created by galfi on 2024. 04. 10..
//

#ifndef LAB_07_FOLDER_H
#define LAB_07_FOLDER_H
enum TYPE {hazi,iskolai,egyetemi,munkahelyi};
typedef struct {
    char name[31];
    int size;
    enum TYPE type;
}FOLDER;
void beolvasFolder(FOLDER *folder);
void kiirFolder(FOLDER folder);
#endif //LAB_07_FOLDER_H
