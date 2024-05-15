#include <stdio.h>
#include <malloc.h>
#include "Headers/linked_list.h"

int main() {
    int inputNumber;
    printf("Adj meg egy szamot: ");
    scanf("%d", &inputNumber);

    Node *unsortedList = NULL;

    // Beolvasott számjegyek beszúrása a listába (hátulról előre)
    while (inputNumber > 0) {
        int digit = inputNumber % 10; // Utolsó számjegy kiválasztása
        insertAtEnd(&unsortedList, digit); // Beszúrás a lista végére
        inputNumber /= 10; // Utolsó számjegy levágása
    }

    // Rendezés (buborékrendezés) a lista elemeinek
    Node *current = unsortedList;
    while (current != NULL) {
        Node *nextNode = current->next;
        while (nextNode != NULL) {
            if (current->data > nextNode->data) {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }

    // Legkisebb és legnagyobb szám felépítése a rendezett lista elemeiből
    int smallestNumber = 0, largestNumber = 0;
    current = unsortedList;
    int power = 1;
    while (current != NULL) {
        smallestNumber = smallestNumber + current->data * power;
        largestNumber= largestNumber * 10 + current->data;
        current = current->next;
        power *= 10;}

    // Eredmények kiíratása
    printf("Legnagyobb szam: %d\n", smallestNumber);
    printf("Legkisebb szam: %d\n", largestNumber);

    // Memóriafelszabadítás
    while (unsortedList != NULL) {
        Node *temp = unsortedList;
        unsortedList = unsortedList->next;
        free(temp);
    }

    return 0;
}
