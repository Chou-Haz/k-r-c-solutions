#include "stdio.h"

int main() {
	int c,i,j,max;
	int words[55];
	max = 0;

		for(i = 0; i < 55;i++) {	//initial
			words[i] = 0;
		}

		while((c = getchar()) != EOF) {	//for the length of every word.

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

		for(i = 0; i < 55; ++i){	//for the max.
			if(max < words[i]) 
				max  = words[i];
		}

		for(i = max; i > 0; --i) {	//for histogram. i is column and j is rank.
			for(j = 0; j < 55; ++j) {
				if(words[j] >= i) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}

	// for(int i = 0; i < 55; i++)	{
	// 	for(int j = 0; j < words[i]; j++){
	// 		printf("*");
	// 	}
	// 	printf("\n");
	// }
// }

}