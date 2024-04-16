#include <stdio.h>
#include <string.h>
#include "Header/patient.h"

int main() {
    Patient paciens1={"Kiss Pista",
                      "1990708965432",
                      {8,7,1999},
                      MIGRAINES};
    printPacient(paciens1 );
    Patient paciens2;
    readPatient(&paciens2);
    char fileName[20];
    strcpy(fileName, paciens2.cnp);
    strcat(fileName,".txt");
    freopen(fileName,"w",stdout);
    printPacient(paciens2);
    freopen("CON","w",stdout);
    return 0;
}
