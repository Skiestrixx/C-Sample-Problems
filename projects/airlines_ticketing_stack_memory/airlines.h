//
// Created by jaybee on 8/31/26.
//

#ifndef C_SAMPLE_PROBLEMS_AIRLINES_H
#define C_SAMPLE_PROBLEMS_AIRLINES_H

#define TOTALSEATS 10

void initSeats(int *seats, int size);
void displaySeats(int *seats, int size);
int assignSeat(int *st, int seatType);
int assignFirstClass(int *seats, int size);
int assignEconomy(int *seats, int size);
void boardPass(int seat);
void exxit(void);


#endif //C_SAMPLE_PROBLEMS_AIRLINES_H
