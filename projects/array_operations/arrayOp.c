#include <stdio.h>
#include <stdlib.h>
#include "arrayOp.h"
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#endif

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

void printMainMenu()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    clearScreen();
    printf(ANSI_BBLUE "\t\t   Project in CSIT122-Programming-2\n" ANSI_RESET);
    printf(ANSI_BYELLOW "\t\t   Authored by %s\n" ANSI_RESET, NAME);
    printf("\t╔═══════════════════════════════════════════════════════╗\n");
    printf("\t║" ANSI_BYELLOW "\t\t~~~Array Operations~~~\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_BWHITE "\t\tA.) Initialize Array\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_BLUE "\t\tB.) Print Array\t\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_YELLOW "\t\tC.) Insert At Position\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_MAGENTA "\t\tD.) Insert Front\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_CYAN "\t\tE.) Remove At Position\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_RED "\t\tF.) Remove Front\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_MAGENTA "\t\tG.) Locate Data Item\t\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_WHITE "\t\tH.) SortAscending(Bubble Sort)\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_BGREEN "\t\tI.) SortDescending(Bubble Sort)\t" ANSI_RESET "\t║\n");
    printf("\t║" ANSI_BRED "\t\tJ.) Exit\t\t\t" ANSI_RESET "\t║\n");
    printf("\t║\t\t\t\t\t\t\t║\n");
    printf("\t║\t\tEnter Your Choice (A-J): \t\t║\n");
    printf("\t║\t\t\t\t\t\t\t║\n");
    printf("\t╚═══════════════════════════════════════════════════════╝\n");
    printf(ANSI_MOVE_TO_FMT, 16, 50);
}

void printError(int code)
{
    switch (code)
    {
    case 1:
        puts("The size of the array must be an integer value.");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;

    case 2:
        puts("The size of the array must be greater than zero.");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;

    case 3:
        printf("The size of the array must be less than %d.\n", ARRAY_SIZE_LIMIT);
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    case 4:
        puts("The array does not exist.");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    case 5:
        puts("Memory reallocation failed.");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    case 6:
        puts("Invalid position");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    case 7:
        puts("Must be an integer value");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    default:
        puts("An error has occurred.");
        while ((getchar()) != '\n')
            ;
        getchar();
        break;
    }
}

bool arraySize(int *size)
{
    if (*size > 0)
    {
        return false;
    }
    clearScreen();
    printf("Enter the size of the array (>0): ");
    if (scanf("%d", size) != 1)
    {
        printError(1);
        *size = 0;
        clearScreen();
        return false;
    }
    if (*size <= 0)
    {
        printError(2);
        *size = 0;
        clearScreen();
        return false;
    }
    if (*size > ARRAY_SIZE_LIMIT)
    {
        printError(3);
        *size = 0;
        return false;
    }
    return true;
}

int *createArray(int *array, int *size)
{
    bool shouldContinue = arraySize(size);

    if (shouldContinue == false)
    {
        return array;
    }

    array = malloc(*size * sizeof(*array));

    if (array == NULL)
    {
        printError(4);
        return NULL;
    }

    for (int i = 0; i < *size; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            --i;
            getchar();
        }
    }
    return array;
}

void printArray(int *array, int *size)
{
    if (array == NULL)
    {
        clearScreen();
        printError(4);
        return;
    }
    clearScreen();
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nPress any key to continue");
    while ((getchar()) != '\n')
        ;
    getchar();
}

void insertAtPosition(int **array, int *size)
{
    if (*array == NULL)
    {
        clearScreen();
        printError(4);
        return;
    }
    if (*size + 1 > ARRAY_SIZE_LIMIT)
    {
        clearScreen();
        printError(3);
        return;
    }

    *size += 1;
    int position, value, *temp = realloc(*array, (*size) * sizeof(*temp));

    if (temp == NULL)
    {
        printError(5);
        return;
    }
    *array = temp;
    temp = NULL;

    clearScreen();
    printf("Position to insert (0-%d): ", *size - 1);
    if (scanf("%d", &position) != 1)
    {
        printError(6);
        *size -= 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }
    if (position > *size - 1)
    {
        printError(6);
        *size -= 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }
    printf("Integer to insert: ");
    if (scanf("%d", &value) != 1)
    {
        printError(7);
        *size -= 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }
    for (int i = *size - 1; i >= position; i--)
    {
        (*array)[i + 1] = (*array)[i];
    }
    (*array)[position] = value;
}

void insertFirst(int **array, int *size)
{
    clearScreen();
    if (*array == NULL)
    {
        printError(4);
        return;
    }
    if (*size + 1 > ARRAY_SIZE_LIMIT)
    {
        clearScreen();
        printError(3);
        return;
    }

    *size += 1;
    int value, *temp = realloc(*array, (*size) * sizeof(*temp));

    if (temp == NULL)
    {
        printError(5);
        return;
    }
    else
    {
        *array = temp;
        temp = NULL;
    }
    printf("Integer to insert: ");
    if (scanf("%d", &value) != 1)
    {
        printError(7);
        *size -= 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }
    for (int i = *size - 1; i >= 0; i--)
    {
        (*array)[i + 1] = (*array)[i];
    }
    (*array)[0] = value;
}

void removeAtPosition(int **array, int *size)
{
    clearScreen();
    if (*array == NULL)
    {
        printError(4);
        return;
    }
    if (*size - 1 == 0)
    {
        free(*array);
        *array = NULL;
        *size = 0;
        puts("The array has been deleted because there is no element inside the array.");
        while ((getchar()) != '\n')
            ;
        getchar();
        return;
    }
    *size -= 1;
    int position, *temp1, *temp = realloc(*array, (*size) * sizeof(*temp));

    if (temp == NULL)
    {
        printError(4);
        return;
    }
    else
    {
        *array = temp;
        temp = NULL;
    }
    printf("Position to remove (0-%d): ", *size);
    if (scanf("%d", &position) != 1)
    {
        printError(7);
        *size += 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }

    if (position > *size)
    {
        printError(6);
        *size += 1;
        int *revert = realloc(*array, (*size) * sizeof(*revert));
        *array = revert;
        return;
    }
    for (int i = position; i < *size; i++)
    {
        (*array)[i] = (*array)[i + 1];
    }
}

void removeFirst(int **array, int *size)
{
    clearScreen();
    if (*array == NULL)
    {
        printError(4);
        return;
    }
    if (*size - 1 == 0)
    {
        free(*array);
        *array = NULL;
        *size = 0;
        puts("The array has been deleted because there is no element inside the array.");
        while ((getchar()) != '\n')
            ;
        getchar();
        return;
    }
    *size -= 1;
    int *temp = realloc(*array, (*size) * sizeof(int));

    if (temp == NULL)
    {
        printError(5);
        return;
    }
    else
    {
        *array = temp;
        temp = NULL;
    }

    for (int i = 0; i < *size; i++)
    {
        (*array)[i] = (*array)[i + 1];
    }
}

void locateDataItem(int *array, int *size)
{
    int value;
    clearScreen();
    printf("Enter a value to search in the array: ");
    if (scanf("%d", &value) != 1)
    {
        printError(7);
        return;
    }
    for (int i = 0; i < *size; i++)
    {
        if (array[i] == value)
        {
            printf("%d was found on array index %d.\n", value, i);
            while ((getchar()) != '\n')
                ;
            getchar();
            return;
        }
    }
    printf("%d was not found on the array.\n", value);
    while ((getchar()) != '\n')
        ;
    getchar();
}

void sortAscending(int *array, int *size)
{
    for (int i = 1; i < *size; i++)
    {
        for (int j = 0; j < *size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int *array, int *size)
{
    for (int i = *size; i > 1; i--)
    {
        for (int j = 0; j < *size - 1; j++)
        {
            if (array[j + 1] > array[j])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}