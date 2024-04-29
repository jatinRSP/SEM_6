
#include <stdio.h>
#include <math.h>

int fastExponentiation(int a, int b, int n)
{
    int result = 1;
    a = a % n;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % n;
        }
        b = b / 2;
        a = (a * a) % n;
    }
    return result;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int hashFunction(int m, int p)
{
    return m * m % (p - 1);
}

int randomK(int p)
{
    for (int i = 2; i < p - 1; i++)
    {
        if (gcd(i, p - 1) == 1)
        {
            return i;
        }
    }
}

int inverse(int a, int b)
{
    for (int i = 1; i < b; i++)
    {
        if ((a * i) % b == 1)
        {
            return i;
        }
    }
}

void main()
{
    int p, g, x, y;
    int m, hash, k, s1, s2, kInv;
    int v1, v2;

    printf("-----------------SENDER SIDE-----------------\n\n");

    printf("Enter the value of p: ");
    scanf("%d", &p);

    printf("Enter the value of g: ");
    scanf("%d", &g);

    printf("\nEnter the private key x such that 1 < x < p-1: ");
    scanf("%d", &x);

    y = fastExponentiation(g, x, p);

    printf("\nThe public key is: %d %d %d \n", p, g, y);
    printf("The private key is: %d %d %d \n", p, g, x);

    printf("\nEnter the message m: ");
    scanf("%d", &m);

    // hash = hashFunction(m, p);
    hash = m;

    k = randomK(p);

    printf("The hash value is: %d\n", hash);
    printf("The random number k is: %d\n", k);

    kInv = inverse(k, p - 1);

    printf("The inverse of k is: %d\n", kInv);

    s1 = fastExponentiation(g, k, p);
    s2 = kInv * (hash - x * s1) % (p - 1);

    printf("The signature is: %d %d\n", s1, s2);

    printf("\n\n-----------------RECEIVER SIDE-----------------\n\n");

    v1 = fastExponentiation(g, hash, p);
    v2 = (fastExponentiation(y, s1, p) * fastExponentiation(s1, s2, p)) % p;

    printf("v1: %d\n", v1);
    printf("v2: %d\n", v2);

    if (v1 == v2)
    {
        printf("The signature is verified\n");
    }
    else
    {
        printf("The signature is not verified\n");
    }
}