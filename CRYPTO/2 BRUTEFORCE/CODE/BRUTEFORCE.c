#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "keygen.h"
#include "encrypt.h"

char key[10], key1[9], key2[9], output[9];
char outputBits[900];
char inputString[100];

numToKey(int num, char *key)
{
    int i;

    // By default all bits are 0
    for (i = 0; i < 10; i++)
    {
        key[i] = '0';
    }

    for (i = 9; i >= 0; i--)
    {
        key[i] = (num % 2) + '0';
        num = num / 2;
    }
}

int main()
{
    FILE *filePointer;

    filePointer = fopen("CTPT.txt", "r+");

    if (filePointer == NULL)
    {
        printf("CANT OPEN FILE!!!\n");
        return 0;
    }

    // LETS FIRST WRITE SOME PT CT PAIR IN FILE
    // ODD LINES ARE PT
    // EVEN LINES ARE CT

    // int i;
    // printf("Enter the 10 bit key: ");
    // scanf("%s", &key);

    // generateKeys(key, key1, key2);

    // printf("Key 1: %s\n", key1);
    // printf("Key 2: %s\n", key2);

    // printf("Enter input string: ");
    // scanf("%s", &inputString);

    // int len = strlen(inputString);

    // printf("Encrypted string: ");

    // for (i = 0; i < len; i++)
    // {
    //     encrypt(inputString[i], key1, key2, output);
    //     for (int j = 0; j < 8; j++)
    //     {
    //         outputBits[i * 8 + j] = output[j];   
    //     }
    // }

    // outputBits[i * 8] = '\0';
    // printf("%s\n", outputBits);

    // fprintf(filePointer, "%s\n", inputString);
    // fprintf(filePointer, "%s\n", outputBits);

    //Lets do bruteforce for input string
    //We will read the file and then do bruteforce

    char inputStringFromFile[100];
    char outputBitsFromFile[900];

    // Read 1st line and store it in inputStringFromFile
    fscanf (filePointer, "%s", inputStringFromFile);
    // Read 2nd line and store it in outputBitsFromFile
    fscanf (filePointer, "%s", outputBitsFromFile);

    printf("Input String from file: %s\n", inputStringFromFile);
    printf("Output Bits from file: %s\n", outputBitsFromFile);

    for (int i = 0; i < 1024; i++)
    {
        numToKey(i, key);
        generateKeys(key, key1, key2);

        int len = strlen(inputStringFromFile);

        for (int j = 0; j < len; j++)
        {
            encrypt(inputStringFromFile[j], key1, key2, output);
            for (int k = 0; k < 8; k++)
            {
                outputBits[j * 8 + k] = output[k];
            }
        }

        outputBits[len * 8] = '\0';

        if (strcmp(outputBits, outputBitsFromFile) == 0)
        {
            printf("Key found: %s\n", key);
            break;
        }
    }
    
    fclose(filePointer); // Don't forget to close the file

    return 0;
}
