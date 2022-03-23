#include "stdio.h"
int strend(char *s, char *t);

int main(int argc, char const *argv[])
{
	char s[] = "I am a student.";
	char t[] = "I am a student.";

	char *ps = &s[0];
	char *pt = &t[0];
	int result = strend(ps, pt);
	printf("%d\n", result);
	return 0;
}

int strend(char *s, char *t) {
	char *bs = s;
	char *bt = t;
	//For the beginning.
	
	while(*s)
		s++;

	while(*t)
		t++;

	for( ; *s == *t && s != bs && t != bt; *s--,*t--) ;
		//判断指针s和t指向的值是否相等，判断指针s的位置，判断指针t的位置。
		

	if (*t == *s && t == bt)	//当退出循环之后不清楚因为哪个条件而退出，所以继续判定。
		return 1;
	else {
		return 0;
	}
}