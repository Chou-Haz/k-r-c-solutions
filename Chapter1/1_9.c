#include <stdio.h>

int main()
{
	int count = 0;
	int c;
	while((c = getchar()) != EOF){
		if(c != ' ')
			count = 0;
		else {
			count++;
		}

		if(count < 2)
		putchar(c);
	}
}