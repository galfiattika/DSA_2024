//
// Created by galfi on 2024. 04. 10..
//

#include <stdio.h>
#include "../header/folder.h"

void beolvasFolder(FOLDER *folder) {
    scanf("\n%[^\n]",folder->name);
    scanf("%d",&folder->size);
    scanf("%d",&folder->type);

}

void kiirFolder(FOLDER folder) {
printf("%s\n",folder.name);
printf("%d\n",folder.size);
    printf("%i\n",folder.type);
}
