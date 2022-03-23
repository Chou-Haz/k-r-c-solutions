#include "stdio.h"

int main() {
	int space = 0;
	int tab = 0;
	int ln = 0;
	int c;
	while((c=getchar()) != EOF)	{
		if(c == ' ') {
			++space;
		}
		if(c == '\t') {
			++tab;
		}
		if(c == '\n') {
			++ln;
		}
	}
	printf("空格个数为：%d\n",space );
	printf("制表符个数为：%d\n",tab );
	printf("换行符个数为：%d\n",ln );
}