#include "stdio.h"
int bitcount();

int main(int argc, char const *argv[])
{
	unsigned bin = 0b1111;
	printf("%d\n", bitcount(bin));
	return 0;
}

int bitcount (unsigned x) {
	int b = 0;
	while(x != 0) {
		x &= x-1;
		++b;
	}
	return b;
}