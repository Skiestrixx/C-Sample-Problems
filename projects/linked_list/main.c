#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "../array_operations/arrayOp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    List head=NULL;
    // head=createList(head);
    // displayList(head);
    // printf("Sum = %d\n",computeSum(head));
    // printf("Positive = %d\n",countPos(head));
    // printf("Negative = %d\n",countNeg(head));
    // printf("Even = %d\n",countEven(head));
    // printf("Odd = %d\n",countOdd(head));
    // printf("Find Item = %d\n",findItem(head,10));
    // printf("Find Max = %d\n",findMax(head));
    // printf("Find Min = %d\n",findMin(head));
    head = insertFront(head,1);
    head = insertFront(head,3);
    head = insertEnd(head,5);
    head = insertPos(head,1,4);
    displayList(head);
    head = deletePos(head,1);
    displayList(head);
    return 0;
}
