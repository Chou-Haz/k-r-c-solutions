#include "stdio.h"
void strcat1(char *s, char *t);

int main(int argc, char const *argv[])
{
	char s[] = "I am a student.";
	char t[] = "Me too.";

	char *ps = &s[0];
	char *pt = &t[0];
	strcat1(ps, pt);
	printf("%s\n", s);
	return 0;
}

void strcat1(char *s, char *t) {
	while (*s++)
		;
	s--;
	while(*s++ = *t++)
		;
}