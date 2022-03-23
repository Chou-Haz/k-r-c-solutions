#include "stdio.h"
#define MAXLINE 20

int any(char s1[] , char s2[]);
int getLine(char s[],int length);

int main(int argc, char const *argv[])
{
	char s1[MAXLINE] = "abcdefg";
	char s2[MAXLINE] = "ggfdezmnnm";

	printf("%d", any(s1,s2));
	return 0;
}

int any(char s1[],char s2[]) {
	int i, j;
	i = j = 0;
	for(i = j = 0 ;s1[i] != '\0' ;++i) {	
		while(s1[i] != s2[j++] && s2[j] != '\0') ;
		
		if(s2[j] != '\0') 
			return i;	

		j = 0;
	}
	return -1;

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
