#include "stdio.h"
unsigned int rightrot();

int main(int argc, char const *argv[])
{
	unsigned int x = 0b1111;
	unsigned int result = rightrot(x,2);
	printf("%u\n", result);
	return 0;
}

unsigned int rightrot(unsigned int x, int n) {
	// int b;
	// for(b = 0; x != 0; x >>= 1)
	// 	++b;
	// printf("%d\n", b);
	
		

	// while(n > 0) {
	// 	if(x & 1)
	// 		x = (x >> 1) | ~(~0 >> 1);
	// 	else 
	// 		x = (x >> 1);
	// 	n--;
	// }
	return x;
}