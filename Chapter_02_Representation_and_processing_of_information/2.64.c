#include <stdio.h>

int any_odd_one(unsigned x);

int main(int argc, char const *argv[])
{
	printf("%d\t%d\n", any_odd_one(1011), any_odd_one(1024));
	return 0;
}

int any_odd_one(unsigned x)
{
  // assume w = 32
	unsigned sizeof_unsigned = sizeof(unsigned);
	unsigned w = sizeof_unsigned << 3;
  printf("sizeof_unsigned: %d, w: %d, x: %#.8x, x<<31: %#.8x\n", sizeof_unsigned, w, x, x<<(w-1));
	return !!(x << (w-1));
}

