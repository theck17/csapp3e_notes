#include <stdio.h>
unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(int argc, char const *argv[])
{
	printf("%#.8x\n", replace_byte(0x12345678, 2, 0xAB));
	printf("%#.8x\n", replace_byte(0x12345678, 0, 0xAB));
	return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	int move = i * 8;
  printf("temp1: %#.8x\n", x & ~(0xff << move));
  printf("temp2: %#.8x\n", b << move);
	return x & ~(0xFF << move) | b << move;
}
