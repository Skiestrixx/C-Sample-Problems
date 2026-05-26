#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "arrayOp.h"

int main()
{
    char input;
    int *array = NULL, size = 0;
    do
    {
        printMainMenu();
        scanf(" %c", &input);
        input = toupper(input);
        switch (input)
        {
        case 'A':
            array = createArray(array, &size);
            break;
        case 'B':
            printArray(array, &size);
            break;
        case 'C':
            insertAtPosition(&array, &size);
            break;
        case 'D':
            insertFirst(&array, &size);
            break;
        case 'E':
            removeAtPosition(&array, &size);
            break;
        case 'F':
            removeFirst(&array, &size);
            break;
        case 'G':
            locateDataItem(array, &size);
            break;
        case 'H':
            sortAscending(array, &size);
            break;
        case 'I':
            sortDescending(array, &size);
            break;
        case 'J':
            if (array != NULL)
            {
                free(array);
                array = NULL;
            }
            printf("\e[1;1H\e[2J");
            puts("Press enter to exit");
            while ((getchar()) != '\n')
                ;
            getchar();
            break;
        }
    } while (input != 'J');
    return 0;
}