#include "stdio.h"

int lower(int c);
int main(int argc, char const *argv[])
{
	char c = 'B';
	c = lower(c);
	printf("%c\n", c);
	return 0;
}

int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? (c += 'a' - 'A') : c;
}
