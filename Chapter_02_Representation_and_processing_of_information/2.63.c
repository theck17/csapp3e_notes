#include <stdio.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k); 

int main(int argc, char const *argv[])
{
	printf("%#.8x\n", srl(0x80000000, 8));
	printf("%#.8x\n", sra(0x80000000, 8));
	return 0;
}

unsigned srl(unsigned x, int k) 
{
	/* Perform shift arithmetically */
	unsigned xsra = (int) x >> k;
	/*思路是由k形成诸如0x00FFFFFF这样的掩码，与xsra进行与操作从而将高位置零*/
	unsigned w = sizeof(int) << 3;
	unsigned mask = ~(((1 << k)-1)<<(w-k)); 
  	/*(1 << k)-1能够获得低位连续为1，高位为0的掩码，但是其不能达到全1，于是继续向左移w-k然后取反*/
	return mask & xsra; 
}

int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned) x >> k;
	/*这个题目的关键点是判断符号位是否为1，通过test &= xsrl，test为零如果符号位为0，否则test不变（处于符号位位置*/
	unsigned w = sizeof(int) << 3;
	int test = 1 << (w-1-k);
	test &= xsrl;
	int mask = ~(test - 1);
  	/*test为零时，~(test - 1)��全零，不会改变xsrl*/
	return mask | xsrl;
}
