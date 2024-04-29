#include <stdio.h>

int t1 = 0, t2 = 1, q, r, t;

int extendedEuclidean(int a, int b)
{
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

int main()
{

    int a, b, result;
    printf("Inverse of: ");
    scanf("%d", &a);
    printf("With modulo: ");
    scanf("%d", &b);

    result = extendedEuclidean(b, a);

    if (result == 0)
    {
        printf("Inverse does not exist\n");
        return 0;
    }

    else if (result < 0)
    {
        result += b;
    }

    printf("Inverse: %d\n", result);
    return 0;
}