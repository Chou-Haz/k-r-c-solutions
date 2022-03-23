#include "stdio.h"
#define MAXLINE 100

int getLine(char line[], int maxline);
void reverse(char s[]);

int main() {
	int len;
	char line[MAXLINE];

	while((len = getLine(line,MAXLINE)) > 0){
		reverse(line);
		printf("%s", line);
	}
}

int getLine(char s[] , int lim) {
	int c , i;

	for(i = 0; i<lim-1 && (c=getchar())!=EOF &&c !='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[]) {
	int i,length,temp;
	char reverse[MAXLINE];

	for(i = 0;s[i] != '\n';++i) {
		reverse[i] = s[i];//使用辅助数组进行倒置。
	}
	length = i;

	for(i = 0;i < length;++i) {
		s[i] = reverse[length-i-1];//注意长度要减一。
	}
}