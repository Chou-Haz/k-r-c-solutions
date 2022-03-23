#include "stdio.h"
#include "string.h"
void strncpy1(char *s, char *t, int n);
void strcat1(char *s, char *t, int n);
int strncmp1(char *s, char *t, int n);

int main(int argc, char const *argv[])
{
	char s[] = "abc";
	char t[] = "aaa";

	char *ps = &s[0];
	char *pt = &t[0];

	// strncpy1(s, t, 5);
	// printf("%s\n", s);
	
	// strcat1(s, t, 4);
	// printf("%s\n", s);
	
	int result = strncmp1(ps, pt, 4);
	printf("%d\n", result);
	return 0;
}

void strncpy1(char *s, char *t, int n) {

	while(*t && *s && n-- > 0)
		*s++ = *t++;

}

void strcat1(char *s, char *t, int n) {
	while (*s++)
		;
	s--;
	while((*s++ = *t++) && n-- > 0 && *t)
		;
}


int strncmp1(char *s, char *t, int n) {
	for(; (*s == *t) != 0 && n > 0; s++,t++,n--)
		if(*s == '\0')
			return 0;
	return *s - *t;
}


// void strcat2(char *s, char *t, int n) {
// 	void strncpy1(char *s, char *t, int n);

// 	strncpy1(s+strlen(s), t, n);
// }