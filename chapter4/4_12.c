#include "stdio.h"
#include "math.h"
void itoa();

int main(int argc, char const *argv[])
{
	int n = -1199;
	char s[4];
	itoa(n, s);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[]) {
	static int i;

	if(n/10) {
		itoa(n/10, s);
	}
	else {
		i = 0;
		if(n < 0)
		s[i++] = '-';
	}
	s[i++] = (int)fabs(n) % 10 + '0';
	s[i] = '\0';
}