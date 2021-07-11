#include <stdio.h>
#include <stdint.h>

int is_little_endian(void);

int main(int argc, char const *argv[])
{
	return is_little_endian();
}

int is_little_endian(void)
{
    int32_t i = 1;
	unsigned char *p = (unsigned char *)&i;
	if(*p)
	{
		return 1;
	}
	return 0;
}
