typedef struct node* Nodeptr;

typedef struct node{
    int data;
    Nodeptr next;
}Node;

typedef Node* List;

List createList(List head);
void displayList(List head);
int computeSum(List head);

int countPos(List head);
int countNeg(List head);
int countEven(List head);
int countOdd(List head);

int findItem(List head, int item);
int findMax(List head);
int findMin(List head);

List insertFront(List head, int item);
List insertEnd(List head, int item);
List insertPos(List head,int pos, int item);

List deleteFront(List head);
List deleteEnd(List head);
List deletePos(List head, int pos);