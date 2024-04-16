//
// Created by galfi on 2024. 04. 16..
//

#ifndef LAB_08_FUNCTIONS_H
#define LAB_08_FUNCTIONS_H
enum KONVEXITAS {YES,NO};
enum SZABALYOSSAG {IGEN,NEM};
typedef struct {
    char nev[16];
    int oldalainakSzama;
    enum KONVEXITAS konvexitas;
    enum SZABALYOSSAG szabalyossag;
}Alakzat;
typedef struct {
    int kapacitas;
    int teteje;
    Alakzat *elemek;
}Verem;
char* getFunctionDescription(enum KONVEXITAS konvexitas);
char* getFunctionRegularity(enum SZABALYOSSAG szabalyossag);
void readShapesDetails(Alakzat *pAlakzat);
void printShapesDetails(Alakzat alakzat);
bool isFullStack(Verem verem);
bool isEmptyStack(Verem verem);
Alakzat peek(Verem verem);
Verem createStack(int capacitas, Verem *verem);
void pushStack(Verem *verem, Alakzat item);
Alakzat popStack(Verem *verem);
void printStack(Verem *verem);
void destroyStack(Verem *verem);

#endif //LAB_08_FUNCTIONS_H
