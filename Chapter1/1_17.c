#include "stdio.h"
#define MAXLINE 200

int getLine(char line[], int maxline);
void copy(char to[] , char from[]);

int main() {
	int len;
	char line[MAXLINE];

	while((len=getLine(line,MAXLINE)) >= 0) {

		if(len > 0)
		printf("%s",line);
	}
}

int getLine(char s[] , int lim) {
	int c , i;

	for(i = 0; i < lim-1 && (c = getchar())!=EOF && c!='\n';++i)
		s[i] = c;

	if(c == '\n' && i >= 80) {
		s[i] = c;
		++i;
		s[i] = '\0';

		return i;

		}
	else {
		s[0] = '\0';
		return 0;
	}	

	
}