/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：2.61.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-14 00:44:22
 *   Description   ：
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{

	int x, y;	/* y means 0 should be returned */
	int sizeof_int = sizeof(int);
	
	/*condition A*/
	x = ~0;
	y = 0xFFFFFF00;
	printf("%d\t%d\n", !(~x), !(~y));
	
	/*condition B*/
	x = 0;
	y = 0x000000FF;
	printf("%d\t%d\n", !x, !y);
	
	/*condition C*/
	x = 0x000000FF;
	y = 0x0000000F;
	printf("%d\t%d\n", !((x ^ 0xFF)<<((sizeof_int-1)<<3)), !((y ^ 0xFF)<<((sizeof_int-1)<<3)));

	/*condition D*/
	x = 0x00FFFFFF;
	y = 0x0FFFFFFF;
	printf("%d\t%d\n", !(x >> ((sizeof_int-1) << 3)), !(y >> ((sizeof_int-1) << 3)));
	return 0;
}

