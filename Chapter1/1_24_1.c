#include "stdio.h"
#define MAXLENGTH 100
#define OUT 0
#define InComment 1
#define Quote 2
#define Error 3

int main(int argc, char const *argv[])
{
	int c , i, line ,state ,index;
	int notation[MAXLENGTH];
	int right[MAXLENGTH];

	index = 0;
	line = 1;
	state = OUT;
	for(i = 0;i < MAXLENGTH;i++)
		notation[i] = 0;

	while((c=getchar()) != EOF) {

		if(state == OUT) {
			if(c == '/' && (c=getchar()) == '*') {
				state = InComment;
			}
			//注释部分最先判断，因为在注释中的内容不管是什么都没有语法错误。
			//如果出现注释，则在下次循环时执行下面的注释判断部分。
			else if(c == '\'' || c == '\"') {	
				state = Quote;
				notation[index] = c;
				++index;
			}
			//因为引号没有左右之分，所以只需要判断接下来的引号与原来的保存的引号是否相等，不管是单引号还是双引号。
			else if(c == '(' || c == '[' || c == '{') {
				++index;
				if(c == '(') {
					// if(c[index] )
					notation[index] = '(';
					// right[index] = ')'
					// ++index;
				}
				else if(c == '[') {
					notation[index] = '[';
					// right[index] = ']'
					// ++index;
				}
				else if(c == '{') {
					notation[index] = '{';
					// right[index] = '}'
					// ++index;
				}
			}
			else if(c == ')' || c == ']' || c == '}') {
				if(c == ')' && notation[index] == '(') {
						notation[index]	= 0;
						--index;
				}
				else if(notation[index] == ']' && notation[index] == ']') {
						notation[index] = 0;
						--index;
				}
				else if(notation[index] == '}' && notation[index] == '{') {
						notation[index] = 0;
						--index;
				}
				else {
						// state = Error;
						printf("Error.A brace is expected in line%d\n", line);
				}
			}
		}				
		

		else if(state == InComment) {
			if(c == '*' && (c=getchar()) == '/')
				state = OUT;
		}

		else if(state == Quote) {
			if(c == notation[index]){
				state = OUT;
				--index;
			}
			else if(c == '\n') {
				printf("Error.Expected %d in line %d\n", notation[index] ,line);
			}
		}

	if(c == '\n')
			++line;

	}
	
	if(index > 0) 
		printf("There is a error of braces.Please check.\n");

	return 0;
}