#include "stdio.h"
#define MAXLENGTH 20
void escape();
void unescape();
int getText();

int main(int argc, char const *argv[])
{
	char test[MAXLENGTH], result[MAXLENGTH];
	int i;
	for(i = 0;i < MAXLENGTH; ++i) 
		test[i] = result[i] = 0;
	getText(test,MAXLENGTH);
	unescape(test,result);

	printf("%s\n", result);
	return 0;
}

void escape(char s[], char t[MAXLENGTH]) {
	int c ,i,j;

	for(i = 0;i < MAXLENGTH; ++i) 
		t[i] = 0;

	for(i = j = 0; s[i] != EOF; i++) {
		switch(s[i]) {
			case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;

			case '\t':
			t[j++] = '\\'; 
			t[j++] = 't';
			break;

			default:
			t[j++] = s[i];
			break;
		}

	}

}

void unescape(char s[], char t[]) {
	int c ,i,j;

	for(i = 0;i < MAXLENGTH; ++i) 
		t[i] = 0;

	for(i = j = 0; s[i] != EOF; i++) {
		switch(s[i]) {
			case '\\':

			switch(s[++i]) {
				case 't':
				t[j++] = '\t';
				break;

				case 'n':
				t[j++] = '\n';
				break;

			}
			break;

			default:
			t[j++] = s[i];
			break;
			
		}

	}

}

int getText(char s[] , int lim) {
	int c , i;

	for(i = 0; i<lim-1 && (c=getchar())!=EOF; ++i)
		s[i] = c;
	
	s[++i] = '\0';
	return i;
}