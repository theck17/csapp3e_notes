#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y);

int main(int argc, char const *argv[])
{
	printf("%d\n", tsub_ok(123456, 54321));
	printf("%d\n", tsub_ok(2147483647, -1));
	printf("%d\n", tsub_ok(-2147483648, 1));
	return 0;
}

int tsub_ok(int x, int y)
{
	unsigned sizeof_int = sizeof(int);
	unsigned w = sizeof_int << 8;
	y = -y;

	int i = (x ^ y) >> (w-1);//+-:FFFFFFFF ++/--:00000000
	int j = ((x+y) ^ x) >> (w-1);//overflow:FFFFFFFF otherwise:00000000
	return i || ~j;
}
