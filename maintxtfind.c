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
    //get text to str
    while (h != EOF)
    {
        str[g] = h;
        g++;
        h = getc(stdin);
    }

    int count = 0;
    //keep the first line from text
    while (str[count + 1] != '\n')
    {
        line[count] = str[count];
        count++;
    }

    int i = 0;
    int j = 0;

    //skips of fulty char
    while (line[i] == ' ')
    {
        i++;
    }

    ////find the word
    while (line[i] != ' ')
    {
        word[j] = line[i];
        i++;
        j++;
    }
    char tav;

    //keep the char
    while (line[i] == ' ')
    {
        i++;
    }
    if (line[i] != 'a' && line[i] != 'b')
    {
        printf("program %d not exist\n", line[i]);
    }
    else
    {
        tav = line[i];
        subline(str + count + 4, word, tav);
    }
}