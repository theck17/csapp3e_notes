#include <stdio.h>

int float_le(float x, float y);
unsigned f2u(float x);

int main(int argc, char const *argv[])
{
	printf("%d\n", float_le((float)1.11, (float)1.10));
	printf("%d\n", float_le((float)-1.2, (float)3.0));
	printf("%d\n", float_le((float)1.3, (float)1.3));
	printf("%d\n", float_le((float)0, (float)0));
	printf("%d\n", float_le((float)-1.1, (float)0));
	printf("%d\n", float_le((float)0, (float)1.1));
	return 0;
}

unsigned f2u(float x)
{
	return *(unsigned*)&x;
}

int float_le(float x, float y) 
{
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
	/*Get the sign bits*/
	unsigned sx = ux >> 31; //+:0 -:1
	unsigned sy = uy >> 31;

	/* Give an expression using only ux, uy, sx, and sy */
	return (sx ^ sy) ? (sx ? 1 : 0)/*-+ +-*/ : (sx ? (ux>=uy) : (ux<=uy))/*-- ++*/;
}
