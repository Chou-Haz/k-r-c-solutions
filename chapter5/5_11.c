#include "stdio.h"
#include "stdlib.h"
#define MAXLINE 800
#define TABS 8

int main(int argc, char *argv[]) {
	int count,tabLen,length,i,c;

	length = 0;
	count = 0;

	char *a;

	if(argc == 1) {
		a = "\t";
	}
	else {
		a = argv[1];
	}

	while((c=getchar()) != EOF) {
		++length;
		if(c == '\n'){
			length = 0;
			count = 0;
		}


		if(c == ' ') {
			++count;		
			if(length % TABS == 0) {
				printf(a);
				count = 0;
			}
		}
		else {
			//当在记录空格的过程中，发现在还未到制表符终止位置
			//的时候已经出现非空格的字符，就将原来的空格打印出来，并将该位置的字符输出。
			for(i = 0;i < count;i++)	
				printf(" ");
			putchar(c);
			count = 0;
		}
	}
}