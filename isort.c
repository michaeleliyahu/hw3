#include "isort.h"
#include <stdio.h>
#include <stdbool.h>

//move right i char
void shift_element(int *arr, int i)
{
    int *f = arr;
    while (i > 0)
    {
        *(f + i) = *(f + i - 1);
        i--;
    }

}

//changed value
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

    }
}