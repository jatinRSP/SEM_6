#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int custom_rand(unsigned long long int seed)
{
    unsigned long long int multiplier = 6364136223846793005ULL;
    unsigned long long int increment = 1442695040888963407ULL;
    unsigned long long int modulus = 18446744073709551615ULL; // 2^64 - 1 (64-bit unsigned integer max value)

    // Calculate the next pseudo-random number using LCG algorithm
    seed = (multiplier * seed + increment) % modulus;

    return seed;
}

int main()
{
    unsigned long long int seed = 12345; // Initial seed value
    int i;

    int range_min = 0;
    int range_max = 100;

    // Use current time as seed for better randomness
    time_t t;
    time(&t);
    seed = t;

    // Generate and print 10 pseudo-random numbers within the specified range
    for (i = 0; i < 10; i++)
    {
        // Generate next pseudo-random number
        seed = custom_rand(seed);
        // map to the specified range
        printf("%d\n", range_min + (seed % (range_max - range_min + 1)));
    }

    return 0;
}
