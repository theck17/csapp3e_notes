#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

unsigned unsigned_high_prod(unsigned x, unsigned y);
int signed_high_prod(int x, int y);

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	unsigned w = sizeof(int32_t) << 3;
	int64_t signed_total_prod = signed_high_prod(x, y);
	signed_total_prod <<= w;
	signed_total_prod += x*y;
	bool x_w = x < 0 ? true : false;
	bool y_w = y < 0 ? true : false;
	int64_t unsigned_total_prod = signed_total_prod + ((x_w*(int)y + y_w*(int)x)<<w) + x_w*y_w<<(w*2);
	return (unsigned)(unsigned_total_prod>>w);	
}
