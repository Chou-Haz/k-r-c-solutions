#include "stdio.h"

	#define IN 1
	#define OUT 0

int main() {
	int c;
	int state = OUT;

		while((c = getchar()) != EOF) {

		if(c == ' '|| c == '\n' || c == '\t'){

			if(state == IN) {//未考虑到的部分。
			state = OUT;
			printf("\n");
		}

		}
		else { 
			state = IN;
		}

		if(state == IN) {
			printf("-");
			// putchar(c);
		}
	}	
}