#include <stdio.h>
#include <math.h>

// int fast_exp(int a, int b, int n)
// {
//     int y = 1;
//     while (b > 0)
//     {
//         if (b % 2 == 0)
//         {
//             a = (a * a) % n;
//             b = b / 2;
//         }
//         else
//         {
//             y = (a * y) % n;
//             b = b - 1;
//         }
//     }
//     return y;
// }

int fastExponentiation(int a, int b, int n)
{
    int bitCount = (int)ceil(log2(b)); // Cast log2 result to int

    int aBinary[bitCount];
    int modValues[bitCount];

    int i;
    int result = 1; // Initialize result to 1

    for (i = bitCount - 1; i >= 0; i--)
    {
        aBinary[i] = b % 2;
        b = b / 2;
    }

    for (i = bitCount - 1; i >= 0; i--)
    {
        if (i == bitCount - 1) // Change i == 0 to i == bitCount - 1
        {
            modValues[i] = a % n;
        }
        else
        {
            modValues[i] = (modValues[i + 1] * modValues[i + 1]) % n; // Change i - 1 to i + 1
        }
    }

    for (i = 0; i < bitCount; i++)
    {
        if (aBinary[i] == 1)
        {
            result = (result * modValues[i]) % n; // Add modulo operation here
        }
    }
    return result;
}

void main()
{
    int p, g, x, y;
    int m, r, c1, c2, dec_m;

    printf("Enter the value of p: ");
    scanf("%d", &p);

    printf("Enter the value of g: ");
    scanf("%d", &g);

    printf("\nEnter the private key x such that 1 < x < p-1: ");
    scanf("%d", &x);

    y = (int)pow(g, x) % p;

    printf("\nThe public key is: %d %d %d \n", p, g, y);
    printf("The private key is: %d %d %d \n", p, g, x);

    printf("\nEnter the message m: ");
    scanf("%d", &m);

    printf("\nEnter random number r such that 1 < r < p-1: ");
    scanf("%d", &r);

    c1 = fastExponentiation(g, r, p);
    c2 = fastExponentiation(y, r, p) * m % p;

    printf("\nThe cipher text is: %d %d \n", c1, c2);

    dec_m = c2 * fastExponentiation(c1, p - 1 - x, p) % p;

    printf("\nThe decrypted message is: %d \n", dec_m);
}