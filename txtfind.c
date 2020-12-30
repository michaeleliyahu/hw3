#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define WORD 56
bool substr(char *str1, char *str2, int number)
{
    int str1len = strlen(str1);

    int counter = 0;
    if ((number - str1len) == 0 || (number - str1len) == 1)
    {

        for (int i = 0; i < number; i++)
        {
            if (*(str1 + counter) == *(str2 + i))
            {
                counter++;
            }
        }
    }
    else
    {
        return false;
    }
    if (counter == number || counter + 1 == number)
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}
bool subline(char *str, char *word, char tav)
{
    char keep_word[WORD];
    int place = 0;
    int keep_line = 0;
    bool print_line = false;

    for (int i = 0; *(str + i + 1) != '\0'; i++)
    {
        if (*(str + i) != ' ')
        {
            *(keep_word + place) = *(str + i);
            place++;
        }
        else
        {
            if (substr(word, keep_word, place) == true)
            {
                if (tav == 'a')
                {
                    for (int j = 0; j < place; j++)
                    {
                        putchar(keep_word[j]);
                    }
                    printf("\n");
                }
                print_line = true;
            }
            place = 0;
            memset(keep_word, 0, sizeof WORD);
        }
        if (*(str + i + 2) == '\n')
        {
            // printf("fff");
            *(keep_word + place) = *(str + i);
            if (substr(word, keep_word, place) == true)
            {
                if (tav == 'a')
                {
                    for (int j = 0; j < place; j++)
                    {
                        putchar(keep_word[j]);
                    }
                    printf("\n");
                }
                print_line = true;
            }
            if (print_line == true && tav == 'b')
            {
                for (int j = keep_line+2; j <= i; j++)
                {
                    putchar(*(str + j));
                }
                 printf("\n");
            }
            keep_line = i + 1;
            place = 0;
            memset(keep_word, 0, sizeof WORD);
            print_line = false;
        }
    }
    //  printf("\n");
    return false;
}