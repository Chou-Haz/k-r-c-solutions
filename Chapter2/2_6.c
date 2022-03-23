#include "stdio.h"

unsigned setbite(unsigned x, int p ,int n, unsigned y);

int main(int argc, char const *argv[])
{
	unsigned int x = 0b100;
	unsigned int y = 0b00011;
	unsigned int result = setbite(x,0,1,y);
	printf("%u\n", result);
	return 0;
}

unsigned int setbite(unsigned int x, int p ,int n, unsigned int y) {

	unsigned int x1 = ~(~(~0 << n) << p) & x;
	unsigned int y1 = (~(~0 << n) & y) << p;
	// printf("%u\n", y1);

	return x1 | y1;
}
