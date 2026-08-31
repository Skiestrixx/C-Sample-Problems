#include <stdio.h>
#include"airlines.h"
#include<ctype.h>

int main(void) {
    int seats[TOTALSEATS],seatType, totalEconomy=0,totalFirstClass=0;
    initSeats(seats,TOTALSEATS);
    puts("Welcome to MGM Airlines!");
    do{
        if (totalEconomy== TOTALSEATS/2 && totalFirstClass == TOTALSEATS/2) {
            printf("\nAirplane is full\n");
            break;
        }
        displaySeats(seats,TOTALSEATS);
        printf("\nPlease type 1 for \"first class\"\nPlease type 2 for \"economy\" :");
        scanf("%d",&seatType);
        if (seatType!=1 && seatType!=2) {
            continue;
        }
        int seatAssignment = assignSeat(seats, seatType);
        if (seatAssignment != -1) {
            if (seatAssignment <TOTALSEATS/2) {
                totalFirstClass++;
            }else {
                totalEconomy++;
            }
            boardPass(seatAssignment);
        }else {
            if (seatType==1) {
                if (totalEconomy<TOTALSEATS/2) {
                    printf("First class is full would you like to transfer to economy class?(y/n): ");
                    char userReply;
                    scanf(" %c",&userReply);
                    userReply = tolower(userReply);
                    if (userReply=='y') {
                        seatAssignment = assignEconomy(seats,TOTALSEATS);
                        totalEconomy++;
                        boardPass(seatAssignment);

                    }else {
                        break;
                    }
                }
            }
            else if (seatType==2) {
                if (totalFirstClass < TOTALSEATS/2){
                    printf("\nEconomy class is full would you like to transfer to First class?(y/n): ");
                    char userReply;
                    scanf(" %c", &userReply);
                    userReply = tolower(userReply);
                    if (userReply == 'y') {
                        seatAssignment = assignFirstClass(seats,TOTALSEATS);
                        totalFirstClass++;
                        boardPass(seatAssignment);
                    } else {
                        break;
                    }
                }
            }
        }
    }while(1);
    exxit();
    return 0;
}