#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);

int main(int argc, char const *argv[])
{
	printf("%d\n", saturating_add(123456, -54321));
	printf("%d\n", saturating_add(2147483647, 1));
	printf("%d\n", saturating_add(-2147483648, -1));
	return 0;
}

int saturating_add(int x, int y)
{
	unsigned sizeof_int = sizeof(int);
	unsigned w = sizeof_int << 8;
	int i = (x ^ y) >> (w-1);//+-:FFFFFFFF ++/--:00000000
	int j = ((x+y) ^ x) >> (w-1);//overflow:FFFFFFFF otherwise:00000000
	int k = x >> (w-1);//+:00000000 -:FFFFFFFF
	return (i & (x + y)) + (~i & (j & ( (~k & INT_MAX) + (k & INT_MIN) )));
}
