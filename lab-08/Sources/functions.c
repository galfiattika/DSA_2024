//
// Created by galfi on 2024. 04. 16..
//

#include <stdio.h>
#include <malloc.h>
#include "../Headers/functions.h"

char *getFunctionDescription(enum KONVEXITAS konvexitas) {
    switch (konvexitas) {
        case YES: return "YES";
        case NO: return "NO";
        default:return "other";


    }
}

char *getFunctionRegularity(enum SZABALYOSSAG szabalyossag) {
    switch(szabalyossag){
        case IGEN:return "YES";
        case NEM:return "NO";
        default:return "other";
    }
}

void readShapesDetails(Alakzat *pAlakzat) {
    scanf("\n%[^\n]",pAlakzat->nev);
    scanf("\n%d",&pAlakzat->oldalainakSzama);
    scanf("\n%i",&pAlakzat->konvexitas);
    scanf("\n%i",&pAlakzat->szabalyossag);
}

void printShapesDetails(Alakzat alakzat) {
    printf("\n nev: %s",alakzat.nev);
    printf("\n oldalak szama: %i",alakzat.oldalainakSzama);
    printf("\n konvex-e?: %s", getFunctionDescription(alakzat.konvexitas));
    printf("\n szabalyos-e? %s", getFunctionRegularity(alakzat.szabalyossag) );
    printf("\n");
}

bool isFullStack(Verem verem) {
    return verem.teteje==verem.kapacitas-1;
}

bool isEmptyStack(Verem verem) {
    return verem.teteje==-1;
}

Alakzat peek(Verem verem) {
    if(isEmptyStack(verem)){
        printf("A verem üres, nincs elem a tetején.\n");
        Alakzat ures={"",0,0,0};
        return ures;
    }
    Alakzat van=verem.elemek[verem.teteje];
    return van;
}

Verem createStack(int capacitas, Verem *verem) {
    verem->kapacitas=capacitas;
    verem->teteje=-1;
    verem->elemek=(Alakzat*)malloc(verem->kapacitas*sizeof (Alakzat) );
    if(!verem->elemek)
    {
        exit(-1);
        printf("error geci huje");
    }
}

void pushStack(Verem *verem, Alakzat item) {
    if(isFullStack(*verem)){
        printf("A verem tele van, nem lehet további elemet hozzáadni.\n");
        return;
    }
    verem->elemek[++verem->teteje] = item;

}

Alakzat popStack(Verem *verem) {
    Alakzat ures={"",0,0,0};
    if(isEmptyStack(*verem)){
        printf("A verem üres, nem lehet elemet eltávolítani.\n");
        return ures;
    }
    return verem->elemek[verem->teteje--];
}
void printStack(Verem *alakzatok) {
    if (isEmptyStack(*alakzatok)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = 0; i <= alakzatok->teteje; i++) {
        printShapesDetails(alakzatok->elemek[i]);
    }
}

void destroyStack(Verem *verem) {
    free(verem);
}
