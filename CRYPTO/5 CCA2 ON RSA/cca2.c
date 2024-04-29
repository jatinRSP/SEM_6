// CCA2 attak on RSA

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

    int m1, c1, decOfC1, mDec;

    printf("\n-----------------CHALLENGER WILL COMPUTE CIPHER TEXT-----------------\n\n");

    do
    {
        printf("Enter the value of p: ");
        scanf("%d", &p);
    } while (!isPrime(p));

    do
    {
        printf("Enter the value of q: ");
        scanf("%d", &q);
    } while (!isPrime(q));

    n = p * q;

    printf("\nValue of n: %d\n", n);

    phi = (p - 1) * (q - 1);

    printf("Value of phi: %d\n", phi);

    do
    {
        printf("\nEnter the value of e between 1 and %d: ", phi);
        scanf("%d", &e);
    } while (e < 1 || e > phi || gcd(e, phi) != 1);

    d = extendedEuclidean(phi, e);

    if (d < 0)
    {
        d += phi;
    }

    printf("Value of d: %d\n", d);

    printf("\nPublic key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    printf("\nEnter the message: ");
    scanf("%d", &m);

    c = fastExponentiation(m, e, n);

    printf("Encrypted message: %d\n", c);

    printf("\n\n-----------------CHALLENGER WILL GIVE %d TO ADVERSARY-----------------\n\n", c);

    printf("\n-----------------ADVERSARY WILL CHOOSE M1-----------------\n\n");

    printf("Enter the message: ");
    scanf("%d", &m1);
    printf("\n");

    printf("\n-----------------C1 = C*M1^e mod n-----------------\n\n");

    c1 = (c * fastExponentiation(m1, e, n)) % n;

    printf("Encrypted message: %d\n", c1);

    printf("\n\n-----------------ADVERSARY WILL QUERY DECRYPTION OF %d-----------------\n\n", c1);

    decOfC1 = fastExponentiation(c1, d, n);

    printf("Decrypted message: %d\n", decOfC1);

    printf("\n\n-----------------ADVERSARY COMPUTES M1 INVERSE WITH RESPECT TO N-----------------\n\n");

    int m1Inverse = extendedEuclidean(n, m1);

    if (m1Inverse < 0)
    {
        m1Inverse += n;
    }

    printf("M1 inverse: %d\n", m1Inverse);

    printf("\n\n-----------------ADVERSARY WILL COMPUTE M = C1*M1^-1 mod n-----------------\n\n");

    mDec = (decOfC1 * m1Inverse) % n;

    printf("Decrypted message: %d\n\n", mDec);

    if (mDec == m)
    {
        printf("Adversary has successfully decrypted the message\n");
    }
    else
    {
        printf("Adversary has failed to decrypt the message\n");
    }

    return 0;
}