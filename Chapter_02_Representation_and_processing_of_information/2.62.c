#include <stdio.h>

int int_shifts_are_arithmetic(void);
int int_shifts_are_logic(void);

int main(int argc, char const *argv[])
{
	
	printf("int shifts are aritthmetic: %d\n", int_shifts_are_arithmetic());
	printf("int shift are logic: %d\n", int_shifts_are_logic());
	return 0;
}

int int_shifts_are_arithmetic(void)
{
	int x = ~0; // Reverse by position --> x = -1
  printf("x = %d, x>>1: %d\n", x, x>>1);
	return x >> 1 == x;
}

int int_shifts_are_logic(void)
{
	unsigned x = ~0;
  printf("x = %d, x>>1: %d\n", x, x>>1); 
	return x >> 1 == x;
}
