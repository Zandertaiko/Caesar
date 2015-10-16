/*
* File: caesar.c
* Programmer: Zander Møysal
* Date: 16.10.2015
*
* Encrypts a string with the caesar cipher.
* Takes 1 commandline argument(has to be positive) as key.
*
* How to use example:
*
* username(~/caesar): ./caesar 3
* abc
* def
*
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    
    if (argc < 2 || atoi(argv[0]) < 0 || atoi(argv[1]) < 0 )
    {
        printf("ERROR!\n");
        return 1;
    }
    
    int key = 0;
    char word[100];
    fgets(word, 100, stdin);
    int len = strlen(word) - 1;
    key = atoi(argv[1]);
    
    for (int i = 0; i < len; i++)
    {
        // a = d
        char encrypt = word[i];
        int ascii = encrypt;
        int k = 0;
        
        do
        { 
            k++;
            ascii++;
            
            if (ascii == 123 || ascii == 91)
            {
                if (ascii == 123)
                    ascii = 97;
                else if (ascii == 91)
                    ascii = 65;
            }
        }
        while (k < key);
        
        
        if (ascii == 32 + key)
        {
            printf(" ");
        }
        else if (ascii == 33 + key && 33 + key < 65)
        {
            printf("!");
        }
        else if (ascii == 44 + key)
        {
            printf(",");
        }
        else
        {
            printf("%c", (char)ascii);
        }
    }
    printf("\n");
    return 0;
}
