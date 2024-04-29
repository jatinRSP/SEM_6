// Implementation of brute force attack on the SDES algorithm

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "keygen.h"
#include "encrypt.h"

void numToKey(int num, char *key)
{
    // Initialize the key with all bits set to '0'
    for (int i = 0; i < 10; i++)
    {
        key[i] = '0';
    }

    // Convert the number to binary and store it in the key
    for (int i = 9; i >= 0; i--)
    {
        key[i] = (num % 2) + '0';
        num = num / 2;
    }

    key[10] = '\0';
}

int main()
{
    FILE *filePointer;
    char inputStringFromFile[100];
    char outputBitsFromFile[900];
    char key[11], key1[9], key2[9];
    char output[8];
    char outputBits[900];

    int count = 1;

    filePointer = fopen("CTPT.txt", "r");

    if (filePointer == NULL)
    {
        printf("Error: Unable to open the file!\n");
        return 1; // Exit with error code
    }

    fscanf(filePointer, "%s", inputStringFromFile);
    fscanf(filePointer, "%s", outputBitsFromFile);

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
            printf("Key %d: %s\n",count++, key);
        }
    }
    
    fclose(filePointer); // Don't forget to close the file

    return 0;
}