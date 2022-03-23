#include "stdio.h"
#include "string.h"
#include "ctype.h"
int getLine(char *s, int lim);
void reverse(char *s);
void itoa(int n, char *s);
int atoi(char *);
int strindex(char *, char *);

int main(int argc, char const *argv[])
{
	char s1[20] = "I am a student.";
	char s2[20] = "am";
	// char *ps1 = &s1[0];
	// char *ps2 = &s2[0];

	// reverse(ps);
	// printf("%s\n", s);

	// int digit = -3231;
	// itoa(digit, s2);
	// printf("%s\n", s2);

	// char num[] = "-123";
	// // char *p = &num[0];
	// int result = atoi(num);
	// printf("%d\n", result);

	int result = strindex(s1, s2);
	printf("%d\n", result);

	// int len;
	// while(getLine(ps, 20) > 0) {
	// 	reverse(ps);
	// 	printf("%s", s);
	// }
	
	return 0;
}

int getLine(char *s, int lim) {
	int c;
	char *t = s;

	for(; --lim && (c = getchar())!=EOF && c != '\n'; s++) 
		*s = c;
	if(c == '\n') {
		*s = c;
		s++;
	}
	*s = '\0';
	return s - t;
}

void reverse(char *s) {
	int c;
	char *j;
	j = s + strlen(s) - 1 ;

	for(; s < j; s++, j--) {
		c = *s;
		*s = *j;
		*j = c;
	}
}

void reverse(char *);
void itoa(int n, char *s) {
	int sign;
	char *t = s;

	if((sign=n) < 0)
		n = -n;

	do {
		*s++ = n % 10 + '0';
	} while((n /= 10) > 0);

	if(sign < 0)
		*s++ = '-';

	*s = '\0';

	// s = t;
	reverse(t);
}

int atoi(char *s) {
	int n, sign;

	for( ; isspace(*s); s++)
		;

	sign = (*s == '-') ? -1 : 1;

	if(*s == '+' || *s == '-')
		s++;
	for(n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');

	return sign * n;
}

int strindex(char *s, char *t) {
	char *i = s;
	char *j;

	for( ; *s != '\0'; s++) {
		for(j = s;*t != '\0' && *j == *t; j++, t++)
			;
		if(j != s && *t == '\0')
			return s - i;
	}
	return -1;
}