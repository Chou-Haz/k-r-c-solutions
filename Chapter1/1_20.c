#include "stdio.h"
#define MAXLINE 800
#define TABS 8

int main() {
	char text[MAXLINE];
	int length,tabLen,i,c;
	
	length = 0;
	while((c=getchar()) != EOF) {
		++length;
		if(c == '\n')
			length = 0;
		if(c == '\t') {
			--length;	//去掉'\t'的位置。
			tabLen = length;	
			//记录下这个位置，用于下面的循环。
			for(i = 0;i < TABS-tabLen%TABS;++i){
				printf("*");
				++length;
				//记录下每个空格占用的长度，
				//注意在这个位置本来是用\t代替，不占位置。
			}
		}
		else {
			putchar(c);
		}
	}
}