#include <stdio.h>

int lower_one_mask(int n);

int main(int argc, char const *argv[])
{
	printf("%#.8x\n", lower_one_mask(6));
	printf("%#.8x\n", lower_one_mask(17));
	return 0;
}

int lower_one_mask(int n)
{
	int sizeof_int = sizeof(int);
	unsigned x = ~0;
	x >>= ((sizeof_int << 3) - n);
	return x;
}
