#include "stdio.h"
#define MAXLINE 100

int getLine(char line[], int maxline);
void copy(char to[], char from[]);


int main() {
	int len,curlen;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while((curlen = getLine(line,MAXLINE)) > 0) {

		len = 0;
		while((line[curlen-1]) != '\n' && (curlen == MAXLINE-1)) {
			len = len + curlen;	
			printf("%s", line);		
			curlen = getLine(line , MAXLINE);
		}
		len = curlen + len;
		if(len > max) {
			max = len;
			copy(longest,line);
		}
	}
	// if(max > 0) {
	// 	printf("The longest line is: \"%s\"", longest);
	// 	printf("%d", max);
	// }
	printf("%d", max);
	return 0;
}

int getLine(char s[] , int lim) {
	int c , i;

	for(i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		// printf("i:%d", i);
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}