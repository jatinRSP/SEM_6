#include <stdio.h>

int t1 = 0, t2 = 1, q, r, t;

int extendedEuclidean(int a, int b)
{
    if (b == 0)
        return t1;
    q = a / b;
    r = a % b;
    t = t1 - t2 * q;
    t1 = t2;
    t2 = t;
    a = b;
    b = r;
    return extendedEuclidean(a, b);
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    int a, b, result;
    printf("Inverse of: ");
    scanf("%d", &a);
    printf("Modulo: ");
    scanf("%d", &b);
    if (gcd(b, a) != 1)
    {
        printf("Inverse does not exist\n");
        return 0;
    }
    result = extendedEuclidean(a, b);
    if (result < 0)
        result += b;
    printf("Inverse: %d\n", result);
    return 0;
}
