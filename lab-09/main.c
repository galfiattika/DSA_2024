#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/functions.h"

int main() {/*
    Market market1={"barcsa",2000, 11,06,0};
    Market market2={"ladoipasi",2018,5,29,2};
    if(!freopen("MARKETNEV_1.txt","w",stdout)){
        exit(-1);
        printf("bajvan");
    }
    printMarketDetails(market1);
    printMarketDetails(market2);
    if(!freopen("CON","w",stdout)){
        exit(-1);
        printf("bajvan");
    }
    Market market3;
    readMarketDetails(&market3);
    printMarketDetails(market3);
     */
    int kapacitas;
    Market market;
    circularQueue queue;
    if(!freopen("MARKET.txt","r",stdin)){
        exit(-1);
        printf("bajvan");
    }
    scanf("%i",&kapacitas);
    createQueue(25,&queue);
    for(int i=0;i<kapacitas;i++){
        readMarketDetails(&market);
        enqueue(&queue,market);
    }
    display(queue);
    if(!freopen("CON","r",stdin)){
        exit(-1);
        printf("bajvan");
    }
    printf("adj egy izet");
    char nevv[50];
    int ujszam;
    scanf("%s",nevv);
    scanf("%i",&ujszam);
    for(int i=0;i<=queue.rear;i++)
    {
        if(strcmp(queue.elements[i].nev,nevv)==0){
            queue.elements[i].mukodesistatusz=ujszam;
        }
    }
    display(queue);
    int adottEv=1000,db=0;
    for(int i=0;i<=queue.rear;i++)
    {
        if(queue.elements[i].indulasiDatum.ev==adottEv){
            db++;
        }
    }
    printf("%i",db);
    Market legregebbiMarket={"",2024,0,0,0};
    for(int i=0;i<=queue.rear;i++)
    {
        if(queue.elements[i].mukodesistatusz==0)
        {
            if(queue.elements[i].indulasiDatum.ev<legregebbiMarket.indulasiDatum.ev)
                legregebbiMarket=queue.elements[i];
        }
    }
    printf("\n");
    printf("%i",legregebbiMarket.indulasiDatum.ev);
    int hely;
    hely=queue.capacity-queue.rear;
    printf("\n");
    printf("%i",hely-1);
    for(int i=0;i<=queue.rear;i++)
    {
        if(strstr(queue.elements[i].nev,"KFT"))
        {
            printMarketDetails(queue.elements[i]);
        }
    }
    return 0;
}


