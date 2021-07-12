#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	printf("0x%.8X\n", x&0xFF | y&~0xFF);
	return 0;
}
