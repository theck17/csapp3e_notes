int threefourths(int x)
{
  	int k = 2;
	int bias = (1 << k) - 1;
	unsigned sizeof_int = sizeof(int);
	unsigned w = sizeof_int << 3;
	int judge = x >> (w-1); //-:FFFFFFFF +:00000000
	x = (judge & ((x + bias) >> k)) + (~judge & (x >> k));
  	return (x << 1) + x;
}
