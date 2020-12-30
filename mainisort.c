#include <stdio.h>
#include <stdbool.h>
#include "isort.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define LENGTH 50
#define LENGTH2 50
int ARR[LENGTH];
int ARR2[LENGTH2];
int main()
{
    int input = 0;
    int counter = 0;
    //get text
    do
    {
        scanf("%d", &input);
        ARR2[counter] = input;
        counter++;
    } while (counter < LENGTH2);


    int *P = &ARR2[0];
    insertion_sort(P, LENGTH2);

    //print text after sort
    for (int f = 0; f < LENGTH2; f++)
    {
        if (f==LENGTH2-1)
        {
             printf("%d ", ARR2[f]);
        }
        else
        {
             printf("%d,", ARR2[f]);
        }
    }
    printf("\n");
}