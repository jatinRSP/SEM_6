#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    int i;
    for (i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int extendedEuclidean(int a, int b)
{
    int t1 = 0, t2 = 1, q, r, t;
    while (b != 0)
    {
        q = a / b;
        r = a % b;
        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
        a = b;
        b = r;
    }

    return a != 1 ? 0 : t1;
}

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

int main()
{

    int p, q, e, d, n, phi;

    int m, c;

    printf("Enter the value of p: ");
    scanf("%d", &p);

    if (isPrime(p) == 0)
    {
        printf("p is not prime\n");
        return 0;
    }

    printf("Enter the value of q: ");
    scanf("%d", &q);

    if (isPrime(q) == 0)
    {
        printf("q is not prime\n");
        return 0;
    }

    n = p * q;

    phi = (p - 1) * (q - 1);

    printf("Enter the value of e between 1 and %d: ", phi);
    scanf("%d", &e);

    if (e < 1 || e > phi)
    {
        printf("Invalid value of e\n");
        return 0;
    }

    if (gcd(e, phi) != 1)
    {
        printf("Invalid value of e\n");
        return 0;
    }

    d = extendedEuclidean(phi, e);

    if (d < 0)
    {
        d += phi;
    }

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    printf("Enter the message: ");
    scanf("%d", &m);

    c = fastExponentiation(m, e, n);

    printf("Encrypted message: %d\n", c);

    m = fastExponentiation(c, d, n);

    printf("Decrypted message: %d\n", m);

    return 0;
}