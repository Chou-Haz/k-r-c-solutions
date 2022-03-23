#include "stdio.h"

int main() {
	int c,i,j;
	int words[55];

		for(i = 0;i < 55;i++) {
			words[i] = 0;
		}

		while((c = getchar()) != EOF) {

		if(c == ' '|| c == '\n' || c == '\t'|| c == '.'|| c == ','){
			++words[54];
		}
		else { 
			if(c >= 'a' && c <= 'z') {
				++words[c-'a'];
			}
			else if(c >= 'A' && c <= 'Z') {
				++words[c-'A'+26];
			}
		}

	}

	for(i = 0; i < 55; i++)	{
		for(j = 0; j < words[i]; j++){
			printf("*");
		}
		printf("\n");
	}

}