#include "stdio.h"
unsigned int invert();

int main(int argc, char const *argv[])
{
	unsigned int x = 0b1000;
	unsigned int a = invert(x,1,2);
	printf("%u\n", a);
	return 0;
}

unsigned int invert(unsigned int x, int p, int n) {

	unsigned int x1 = ~((~(~0 << n) << p) & x);
	unsigned int x2 = (~(~0 << n) << p) | x;

	// unsigned int x1 = (~(~0 << n) << p) & ~x;
	// printf("%u\n", x1);
	// unsigned int x2 = ~(~(~0 << n) << p);
	// printf("%u\n", x2);

	return x1 & x2;
}