#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List createList(List head){
    Nodeptr ptr;
    int i;
    head=(Nodeptr)malloc(sizeof(Node));
    scanf("%d",&head->data);
    //head->data=1;
    ptr=head;
    for(i=2;i<=5;i++){
        ptr->next=(Nodeptr)malloc(sizeof(Node));
        scanf("%d",&ptr->next->data);
        //ptr->next->data=i;
        ptr=ptr->next;//lets ptr move to the next node
    }
    ptr->next=NULL;
    return head;
}

void displayList(List head){
    Nodeptr ptr=head;//i=0;
    while(ptr!=NULL){//i<count
        printf("%d ",ptr->data);//printf("%d",num[i]);
        ptr=ptr->next;//i++;
    }
    printf("\n");
}

int computeSum(List head){
    Nodeptr ptr=head;
    int sum=0;
    while(ptr!=NULL){
        sum+=ptr->data;
        ptr=ptr->next;
    }
    return sum;
}

int countPos(List head){
    Nodeptr ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data>=0)
            count++;
        ptr=ptr->next;
    }
    return count;
}

int countNeg(List head){
    Nodeptr ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data<0)
            count++;
        ptr=ptr->next;
    }
    return count;
}

int countEven(List head){
    Nodeptr ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data%2==0)
            count++;
        ptr=ptr->next;
    }
    return count;
}

int countOdd(List head){
    Nodeptr ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data%2!=0)
            count++;
        ptr=ptr->next;
    }
    return count;
}

int findItem(List head,int item) {
    Nodeptr ptr=head;
    int isFound =0;
    while (ptr!=NULL) {
        if(ptr->data==item) {
            isFound=1;
            break;
        }
        ptr=ptr->next;
    }
    return isFound;
}

int findMax(List head) {
    Nodeptr ptr=head;
    int max=ptr->data;
    while(ptr!=NULL) {
        if(ptr->data>max) {
            max=ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

int findMin(List head) {
    Nodeptr ptr=head;
    int min=ptr->data;
    while(ptr!=NULL) {
        if(ptr->data<min) {
            min=ptr->data;
        }
        ptr=ptr->next;
    }
    return min;
}

List insertFront(List head,int item) {
    Nodeptr ptr=head;
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data=item;
    newNode->next=head;
    head=newNode;
    return head;
}

List insertEnd(List head,int item) {
    Nodeptr ptr=head;
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data=item;
    while (ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=newNode;

    newNode->next=NULL;
    return head;
}

List insertPos(List head,int pos,int item) {
    Nodeptr ptr=head;
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data=item;
    if (pos != 1) {
        int counter = 1;
        while (counter<pos-1) {
            ptr=ptr->next;
            counter++;
        }
        newNode->next = ptr->next;
        ptr->next= newNode;
    }else {
        newNode->next = head;
        head=newNode;
    }
    return head;
}

List deleteFront(List head) {
    Nodeptr ptr=head;
    head = ptr->next;
    free(ptr);
    ptr=NULL;
    return head;
}

List deleteEnd(List head) {
    Nodeptr ptr=head;
    while (ptr->next->next!=NULL) {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    return head;
}

List deletePos(List head,int pos) {
    Nodeptr ptr=head;
    Nodeptr temp;
   if (pos != 1) {
       int counter = 1;
       while (counter<pos-1) {
           ptr=ptr->next;
           counter++;
       }
       temp = ptr->next;
       ptr->next = ptr->next->next;
       free(temp);
       temp=NULL;
       return head;
   }else{
       temp = head;
       head = head->next;
       free(temp);
       temp=NULL;
   }
    return head;
}