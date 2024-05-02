#include <stdio.h>

// Function to perform modular exponentiation (a^b % m) using iterative approach
long long modularExponentiation(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m; // Take modulo of base if a >= m

    while (b > 0)
    {
        // If b is odd, multiply base with result
        if (b & 1 == 1)
        {
            result = (result * a) % m;
        }

        // Right shift exponent by 1 and square the base
        a = (a * a) % m;
        b = b >> 1; // Divide exponent by 2
    }

    return result;
}

int main()
{
    long long a, b, m;
    printf("Enter base (a): ");
    scanf("%lld", &a);
    printf("Enter exponent (b): ");
    scanf("%lld", &b);
    printf("Enter modulo (m): ");
    scanf("%lld", &m);

    // Compute a^b % m using modular exponentiation
    long long result = modularExponentiation(a, b, m);

    // Display the result
    printf("%lld^%lld mod %lld = %lld\n", a, b, m, result);

    return 0;
}
