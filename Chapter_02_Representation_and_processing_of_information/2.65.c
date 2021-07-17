#include <stdio.h>

int odd_ones(unsigned x);

int main(int argc, char const *argv[])
{
	unsigned x1 = 0xFF00FF00;
  int res1 = odd_ones(x1);
	printf("res = %d, %#.8x\n", res1, res1);
	unsigned x2 = 0xFF01FF00;
  int res2 = odd_ones(x2); 
	printf("res = %d, %#.8x\n", res2, res2);
	return 0;
}

int odd_ones(unsigned x)
{
  // int a = x >> 16;
	// x = x ^ a;
  // printf("x = %#.8x, a = %#.8x\n", x, a);
  // a = x >> 8;
	// x = x ^ a;
  // printf("x = %#.8x, a = %#.8x\n", x, a);
  // a = x >> 4;
	// x = x ^ a;
  // printf("x = %#.8x, a = %#.8x\n", x, a);
  // a = x >> 2;
	// x = x ^ a;
  // printf("x = %#.8x, a = %#.8x\n", x, a);
  // a = x >> 1;
	// x = x ^ a;
  // printf("x = %#.8x, a = %#.8x\n", x, a);
  x = x ^ (x >> 1);  
  x = x ^ (x >> 2);  
  x = x ^ (x >> 4);  
  x = x ^ (x >> 8);  
  x = x ^ (x >> 16);  
	return x & 1;
}
