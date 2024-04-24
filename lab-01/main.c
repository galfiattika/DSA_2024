#include <stdio.h>
#include <stdlib.h>
#include "Headers/functions.h"

int main() {
    Flower flower1={"jacint",true,0,25,1};
    if(!freopen("viragneve.txt","w",stdout)){
        printf("hiba");
        exit(-1);
    }
    printViragDetails(flower1);
    if(!freopen("CON","w",stdout)){
        printf("hiba");
        exit(-1);
    }
    Flower flower2;
    readViragDetails(&flower2);
    printViragDetails(flower2);
    return 0;
}
