#include <stdio.h>
#include <string.h>

int main()
{
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    if (strcmp(buff, "password"))
    {
        printf("\n Wrong Password \n");
    }
    else
    {
        printf("\n Correct Password \n");
        pass = 1;
    }

    if (pass)
    {
        printf("\n Root privileges given to the user \n");
    }

    return 0;
}