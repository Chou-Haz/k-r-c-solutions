#include "stdio.h"
#define InComment 1
#define OutComment 0
#define Quote 2

int main(int argc, char const *argv[])
{
	int c, state, quo;

	state = OutComment;
	quo = 0;
	while((c=getchar()) != EOF) {

		if(state == OutComment) {	//刚开始的状态是在注释外，需要判定将要设置为另外两个状态的哪一个。
			if(c == '\'' || c == '\"') {
			state = Quote;
			quo = c;
			putchar(c);
			}
			else if(c == '/') {	//如果出现斜杆，则进一步判定是否后面带有星号。
				c = getchar();
				if(c == '*') 
					state = InComment;
				else {
					putchar('/');	//如果“/”之后不是跟着“*”，说明不是注释，则将“/”原样输出。
					putchar(c);
				} 
			}
			else {	//默认操作，如果没有引号或者斜杆则直接输出。
				putchar(c);
				// putchar(c);
			}
		}

		else if(state == InComment) {			
			// c = getchar();
			if(c == '*') {
				c = getchar();
				if(c == '/') 
					state = OutComment;
				else {
					putchar('*');
					putchar(c);
				} 	
			}	
		}

		else if(state == Quote) {
			putchar(c);
			if(c == quo) 
				state = OutComment;
			//在状态处于OutComment时，记录了引号的性质（可能是单引号也可能是双引号），
			//当此时的引号与之前的引号能够配对时，则返回到OutComment状态。
		}
	}
	return 0;
}