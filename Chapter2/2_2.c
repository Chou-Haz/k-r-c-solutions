#include "stdio.h"
#define true 1
#define false 0

int getLine(char[] , int length);

int main(int argc, char const *argv[])
{
	int len;
	char s[20];
	while((len=getLine(s,20)) > 0) {
		printf("%s", s);
	}
	return 0;
}

int getLine(char s[] , int lim) {
	int c , i , valid;
	i = 0;
	valid = true;

	while(valid) {
		if(i < lim-1) {
			if((c=getchar()) != '\n'){
				if(c != EOF) {
					s[i] = c;
					++i;
				}
				else 
					valid = false;
			}
			else 
				valid = false;
		}
		else 
			valid = false;	
	}

	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}