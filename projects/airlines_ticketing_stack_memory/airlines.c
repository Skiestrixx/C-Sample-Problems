#include<stdio.h>
#include"airlines.h"

#ifdef _WIN32
#include <windows.h>
#endif

void initSeats(int *seats, int size){
    int i;
    for(i=0;i<size;i++){
        seats[i]=0;
    }
}

void displaySeats(int *seats, int size){
    int row;
    printf("\n\nFirst Class Section: ");
    for (row=0;row<size/2;row++){
        printf("[%d] ",seats[row]);
    }
    printf("\nEconomy Section: ");
    for (row=5;row<size;row++){
        printf("[%d] ",seats[row]);
    }
}

int assignFirstClass(int *seats, int size){
    int i;
    for (i=0;i<size/2;i++){
        if (seats[i]==0){
            seats[i]=1;
            return i;
        }
    }
    return -1;
}

int assignEconomy(int *seats, int size){
    int i;
    for (i=5;i<size;i++){
        if (seats[i]==0){
            seats[i]=1;
            return i;
        }
    }
    return -1;
}

int assignSeat(int *st, int seatType){
    if (seatType==1){
        return assignFirstClass(st,TOTALSEATS);
    }else if(seatType==2){
        return assignEconomy(st,TOTALSEATS);
    }
    return -1;
}

void boardPass(int seat){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    printf("\n┌──────────────────────────────────────┐\n");
    printf("│                                      │\n");
    printf("│  BOARDING PASS                       │\n");
    if (seat >= 0 && seat < 5) {
        printf("│  First Class Section                 │\n");
    } else {
        printf("│  Economy Class Section               │\n");
    }

    printf("│  Seat #%d                             │\n", seat + 1);
    printf("└──────────────────────────────────────┘\n");

}

void exxit(void){
    puts("Next flight leaves in three hours");
}
