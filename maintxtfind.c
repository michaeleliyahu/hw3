#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 56
int main()
{

    char str[LINE];
    char line[LINE];
    char word[LINE];
    char h = getc(stdin);
    int g = 0;
    while (h != EOF)
    {
        str[g] = h;
        g++;
        h = getc(stdin);
    }

    ///print all arr
    // for (int i = 0; i < g; i++)
    // {
    //     putchar(str[i]);
    // }

    //get in first line
    int count = 0;
    while (str[count + 1] != '\n')
    {
        line[count] = str[count];
        count++;
    }

    // printf("\n");

    int i = 0;
    ////find the word
    while (line[i] != ' ')
    {
        word[i] = line[i];
        i++;
    }
    char tav ;
    tav = line[i+1];

    subline(str + count + 4, word, tav);
}