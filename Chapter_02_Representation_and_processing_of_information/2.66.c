#include <stdio.h>
#include <limits.h>

/*
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> Ox8000, and Ox6600 --> Ox4000.
 * If x = 0, then return 0.
 */

int leftmost_one(unsigned x);

int main(int argc, char const *argv[])
{
	printf("%#.8x\n", leftmost_one(0xFF00));
	printf("%#.8x\n", leftmost_one(0x6600));
	printf("%#.8x\n", leftmost_one(0x88886600));
	printf("%#.8x\n", leftmost_one(0));
	return 0;
}

int leftmost_one(unsigned x)
{
	unsigned sizeof_unsigned = sizeof(unsigned);
	unsigned w = sizeof_unsigned << 3;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x & ((~x >> 1)|INT_MIN);
}
