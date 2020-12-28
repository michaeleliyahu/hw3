#include "isort.h"
#include <stdio.h>
#include <stdbool.h>
// #define NULL 0
void shift_element(int *arr, int i)
{
    // printf("%d,%d\n", *(arr), i);
    int *f = arr;
    while (i > 0)
    {
        *(f + i) = *(f + i - 1);
        i--;
    }

}
void insertion_sort(int *arr, int len)
{

    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        bool flag = true;
        while (j >= 0 && flag == true)
        {
            if (*(arr + j) > *(arr + i))
            {
                j--;
            }
            else
            {
                flag = false;
            }
        }
        j++;
        int qeep = *(arr + i);
        shift_element((arr + j), i - j);
        *(arr + j) = qeep;
        // for (int j = 0; j <= len - 1; j++)
        // {
        //     printf("%d,", *(arr + j));
        // }
        // printf("\n");
    }
}