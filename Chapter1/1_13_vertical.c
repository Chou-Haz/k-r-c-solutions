#include "stdio.h"

	#define IN 1
	#define OUT 0
	#define MAXLENGTH 30 

int main() {
	int c,max,word;
	int state = OUT;
	int wordLength[MAXLENGTH];
	max = word = 0;

		for(int i = 0;i < MAXLENGTH;i++) {
			wordLength[i] = 0;
		}

		while((c = getchar()) != EOF) {

		if(word > MAXLENGTH) {
			printf("\n\nToo many words.");
			return 1;
		}

		if(c == ' '|| c == '\n' || c == '\t'||c == '.'||c == ','){

			if(state == IN) {
			state = OUT;
			++word;			
			// printf("\n");
		}

		}
		else { 
			state = IN;
		}

		if(state == IN) {
			++wordLength[word];					
			// printf("-");
			// putchar(c);
		}
	}

		for(int i = 0; i < MAXLENGTH;i++) {
			if(max < wordLength[i])
			max = wordLength[i];
		}

		for(int i = max; i > 0; i--) {//打印垂直直方图，从单词长度最长的一行开始打印。
			for(int j = 0; j < MAXLENGTH; j++) {
				if(wordLength[j] >= i) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}

		return 0;
}