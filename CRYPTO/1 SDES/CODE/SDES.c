// SDES implementation in C 
// REFERENCE: https://www.c-sharpcorner.com/article/s-des-or-simplified-data-encryption-standard/

#include <stdio.h>
#include <string.h>
#include "keygen.h"
#include "encrypt.h"

char key[10];
char key1[9];
char key2[9];

char inputString[100];
char output[9];
char outputBits[900];


void main()
{
    int i;
    printf("Enter the 10 bit key: ");
    scanf("%s", &key);

    generateKeys(key, key1, key2);

    printf("Key 1: %s\n", key1);
    printf("Key 2: %s\n", key2);

    printf("Enter input string: ");
    scanf("%s", &inputString);

    int len = strlen(inputString);

    printf("Encrypted string: ");

    for (i = 0; i < len; i++)
    {
        encrypt(inputString[i], key1, key2, output);
        for (int j = 0; j < 8; j++)
        {
            outputBits[i * 8 + j] = output[j];   
        }
    }

    printf("%s\n", outputBits);
}