#include <stdio.h>

int int_shifts_are_arithmetic(void);
int int_shifts_are_logic(void);

int main(int argc, char const *argv[])
{
	
	printf("%d\n", int_shifts_are_arithmetic());
	printf("%d\n", int_shifts_are_logic());
	return 0;
}

int int_shifts_are_arithmetic(void)
{
	int x = ~0;
	return x >> 1 == x;
}

int int_shifts_are_logic(void)
{
	unsigned x = ~0;
	return x >> 1 == x;
}
