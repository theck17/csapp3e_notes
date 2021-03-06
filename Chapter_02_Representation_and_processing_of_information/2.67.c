// A 
// "If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior is undefined"
// 如果右操作数的值为负或大于或等于提升后的左操作数的宽度，则该行为未定义

#include <stdio.h>

int int_size_is_32_B();
int int_size_is_32_C();

int main(int argc, char const *argv[])
{
	int_size_is_32_B();
	int_size_is_32_C();
	return 0;
}

int int_size_is_32_B()
{
  // B
	int set_msb = 1 << 31;
	int beyond_msb = set_msb;
	beyond_msb <<= 1;
	int res1 = set_msb && !beyond_msb;
  printf("B: res1: %d\n", res1);
  return res1;
}

int int_size_is_32_C()
{
  // C
  int set_msb = 1 << 15;
	set_msb <<= 15;
	set_msb <<= 1;
	int beyond_msb = set_msb;
	beyond_msb <<= 1;
	int res2 = set_msb && !beyond_msb;
  printf("C: res2: %d\n", res2);
  return res2;
}


