#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Rotate bits to the right
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

// SHA-256 Constants
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

// SHA-256 initial hash values
const uint32_t initial_hash[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};

// SHA-256 Functions
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define EP1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

// SHA-256 Compression Function
void sha256_compress(uint32_t state[8], const uint8_t block[64])
{
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t T1, T2;

    // Prepare message schedule
    for (int t = 0; t < 16; ++t)
    {
        W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) | (block[t * 4 + 2] << 8) | block[t * 4 + 3];
    }
    for (int t = 16; t < 64; ++t)
    {
        W[t] = SIG1(W[t - 2]) + W[t - 7] + SIG0(W[t - 15]) + W[t - 16];
    }

    // Initialize working variables
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    // Compression loop
    for (int t = 0; t < 64; ++t)
    {
        T1 = h + EP1(e) + CH(e, f, g) + K[t] + W[t];
        T2 = EP0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    // Update hash state
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

// SHA-256 hash function
void sha256(const uint8_t *message, size_t len, uint8_t hash[32])
{
    uint32_t state[8];
    uint32_t length_bits = len * 8;
    uint8_t block[64];
    size_t i;

    // Initialize hash state
    for (i = 0; i < 8; ++i)
    {
        state[i] = initial_hash[i];
    }

    // Process message in 512-bit blocks
    while (len >= 64)
    {
        memcpy(block, message, 64);
        sha256_compress(state, block);
        message += 64;
        len -= 64;
    }

    // Append padding and length
    memset(block, 0, 64);
    memcpy(block, message, len);
    block[len] = 0x80;
    if (len < 56)
    {
        // There is enough room for padding and length in this block
        for (i = 0; i < 8; ++i)
        {
            block[56 + i] = (length_bits >> (56 - i * 8)) & 0xFF;
        }
        sha256_compress(state, block);
    }
    else
    {
        // We need an additional block to store padding and length
        sha256_compress(state, block);
        memset(block, 0, 64);
        for (i = 0; i < 8; ++i)
        {
            block[56 + i] = (length_bits >> (56 - i * 8)) & 0xFF;
        }
        sha256_compress(state, block);
    }

    // Write final hash
    for (i = 0; i < 8; ++i)
    {
        hash[i * 4] = (state[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = state[i] & 0xFF;
    }
}

// Utility function to print hash in hexadecimal format
void print_hash(const uint8_t hash[32])
{
    for (int i = 0; i < 32; ++i)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main()
{
    const char *message = "Hello, world!";
    uint8_t hash[32];
    sha256((uint8_t *)message, strlen(message), hash);
    printf("SHA-256 hash of '%s':\n", message);
    print_hash(hash);
    return 0;
}