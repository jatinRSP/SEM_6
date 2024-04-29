#include <stdio.h>
#include <math.h>
#include <string.h>

void permuteKey(char key[], char permutedKey[])
{
    int i;
    int permutationTable[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};

    for (i = 0; i < 10; i++)
    {
        permutedKey[i] = key[permutationTable[i] - 1];
    }
}

void generateLeftRightKey(char key[], char leftKey[], char rightKey[])
{
    int i;

    for (i = 0; i < 5; i++)
    {
        leftKey[i] = key[i];
    }

    for (i = 5; i < 10; i++)
    {
        rightKey[i - 5] = key[i];
    }
}

void leftShift(char key[], int shift)
{
    int i;
    char tempKey[5];

    strcpy(tempKey, key);

    for (i = 0; i < 5; i++)
    {
        key[i] = tempKey[(i + shift) % 5];
    }
}

void p8(char key[], char key1[])
{
    int i;
    int permutationTable[8] = {6, 3, 7, 4, 8, 5, 10, 9};

    for (i = 0; i < 8; i++)
    {
        key1[i] = key[permutationTable[i] - 1];
    }

    key1[i] = '\0';
}

void generateKey1(char leftKey[], char rightKey[], char key1[])
{
    int i;
    char tempKey[10];

    leftShift(leftKey, 1);
    leftShift(rightKey, 1);

    for (i = 0; i < 5; i++)
    {
        tempKey[i] = leftKey[i];
    }

    for (i = 5; i < 10; i++)
    {
        tempKey[i] = rightKey[i - 5];
    }

    p8(tempKey, key1);
}

void generateKey2(char leftKey[], char rightKey[], char key2[])
{
    int i;
    char tempKey[10];

    leftShift(leftKey, 2);
    leftShift(rightKey, 2);

    for (i = 0; i < 5; i++)
    {
        tempKey[i] = leftKey[i];
    }

    for (i = 5; i < 10; i++)
    {
        tempKey[i] = rightKey[i - 5];
    }

    p8(tempKey, key2);
}

void generateKeys(char key[], char key1[], char key2[])
{
    char leftKey[5], rightKey[5], permutedKey[10];

    permuteKey(key, permutedKey);
    generateLeftRightKey(permutedKey, leftKey, rightKey);
    generateKey1(leftKey, rightKey, key1);
    generateKey2(leftKey, rightKey, key2);
}