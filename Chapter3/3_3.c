#include "stdio.h"
#include "ctype.h"
#define MAXLENGTH 30
void expend(char s1[],char s2[]);
int getText();

int main(int argc, char const *argv[])
{
	char s1[MAXLENGTH] , s2[MAXLENGTH];
	int len,i;
	for(i=0 ;i < MAXLENGTH;++i)
		s2[i] = 0;

	if((len = getText(s1,MAXLENGTH)) > 0) {
		
		expend(s1,s2);
		printf("%s", s2);
	}
	return 0;
}

void expend(char s1[], char s2[]) {
	int i,j;
	for(i = 0,j =0;s1[i] != EOF;++i,++j) {
		
		if(s1[i] == '-' && isalnum(s1[i-1]) && isalnum(s1[i+1] && s1[i+1] >= s1[i-1])) {
			int k;
			for(k = s1[i-1]+1;k < s1[i+1]; ++k) {
				s2[j++] = k;
			}
			--j;
		}
			
		else {
			s2[j] = s1[i];
		}
	}
	s2[j] = '\0';
}

int getText(char s[] , int lim) {
	int c , i;

	for(i = 0; i<lim-1 && (c=getchar())!=EOF; ++i)
		s[i] = c;
	
	s[i] = '\0';
	return i;
}