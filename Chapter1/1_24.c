#include "stdio.h"
#define NoError 0
#define InComment 1
#define Quote 2
#define Brace 3
// #define MBrace 4
// #define BBrace 5

int main(int argc, char const *argv[])
{
	int c,state,quo,bra,line;

	state = NoError;
	quo = line = 0;
	while((c=getchar()) != EOF) {
		++line;
		if(state == NoError) {
			if(c == '/' && (c=getchar()) == '*') {	//注释部分最先判断，因为在注释中的内容不管是什么都没有语法错误。
				state = InComment;
			}

			else { 
				if(c == '(' || c == '[' || c == '{') {
				state = Brace;
				bra = c;
			}

				if(c == '\'' || c == '\"') {
				state = Quote;
				quo = c;
			}

			}
			


		}
		else if(state == InComment) {
			if(c == '*' && (c=getchar()) == '/')
				state = NoError;
		}
		else if(c == )


	}
	return 0;
}