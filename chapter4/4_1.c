#include "stdio.h"
#include "string.h"
int strindex(char s[], char t[]);

int main(int argc, char const *argv[])
{
	char src[] = "Could you tell me?Could you and I?";
	char target[] = "ould";
	int index = strindex(src, target);

	if(index != -1)
		printf("%d\n", index);
	else 
		printf("Error.");

	return 0;
}

int strindex(char s[], char t[]) {
	int i, j, k, index = -1;
	
	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if(k > 0 && t[k] == '\0') {
		index = i;
	}
	}

	if(index != -1) {
		return index;
	}
	
	return -1;

	// int tLen = strlen(t);
	// 
	// for(i = strlen(s)-1; i >= 0; --i) {
	// 	for(j = i, k=tLen-1; k >= 0 && s[j]==t[k]; --j,--k) 
	// 		;
	// 	if(k == -1){
	// 		return i-tLen+1;
	// 	}
	// }
	// 
	// return -1;

}