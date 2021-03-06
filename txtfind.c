#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define WORD 56

/*
Function subline get two word and check if thay are the same
return true or false
*/
bool substr(char *str1, char *str2, int number)
{
    int str1len = strlen(str1); //length of word we looking

    int counter = 0;
    // check the length of this two word
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
/*
Function subline get full string, the word that we looking, wich program.
This function separator between line and after that between word. 
In the next step function send to substr to word to check if thay the same.
*/
void subline(char *str, char *word, char tav)
{
    char keep_word[WORD]; //keep word we wont to check from the text
    int place = 0;
    int keep_line = 0;         //keep line we wont to check from the text
    bool correct_word = false; // if there is correct word in the line

    for (int i = 0; *(str + i + 1) != '\0'; i++)
    {
        if (*(str + i) != ' ')
        {
            *(keep_word + place) = *(str + i); //keep the word
            if (*(str + i) != '\n' && *(str + i) != '\r')
            {
                place++;
            }
        }
        else
        {   
            //if correct word print it and keep it true that have word in line
            if (substr(word, keep_word, place) == true)
            {
                if (tav == 'b')
                {
                    for (int j = 0; j < place; j++)
                    {
                        putchar(keep_word[j]);
                    }
                    printf("\n");
                }
                correct_word = true; //tell to next step that there is correct word in line
            }
            place = 0;
            memset(keep_word, 0, sizeof WORD); //restart word
        }

        //seprate option for last word or last line
        if (*(str + i + 2) == '\n' || *(str + i + 2) == '\0')
        {
            *(keep_word + place) = *(str + i); //take word from text

            //if its kast char we need to keep it
            if (*(str + i + 2) == '\0')
            {
                *(keep_word + place) = *(str + i+1);
                place++;                
            }

            //if correct word print it and keep it true that have word in line
            if (substr(word, keep_word, place) == true)
            {
                if (tav == 'b')
                {
                    for (int j = 0; j < place; j++)
                    {
                        putchar(keep_word[j]);
                    }
                    printf("\n");
                }
                correct_word = true; //tell to next step that there is correct word in line
            }

            //if exist correct word in line print it
            if (correct_word == true && tav == 'a')
            {
                for (int j = keep_line; j <= i+1; j++)
                {
                    putchar(*(str + j));
                }
                printf("\n");
            }
            keep_line = i + 3;                 //keep the location of first char in line
            place = 0;                         // tell to keep word the place of the char
            memset(keep_word, 0, sizeof WORD); //restart word
            correct_word = false;              //restart to check to next word
        }
    }
}