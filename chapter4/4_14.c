#include "stdio.h"
#define swap(t, x, y) {\
	t temp;\
	x = temp;\
	x = y;\
	y = temp;\
}

int main(int argc, char const *argv[])
{
	int x = 3;
	int y = 2;
	swap(int, x ,y);
	printf("%d\n", x);
	return 0;
}