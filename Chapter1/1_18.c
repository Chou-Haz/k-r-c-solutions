#include "stdio.h"
#define MAXLINE 100

int getLine(char s[] , int length);

int main() {
	int len;
	char line[MAXLINE];

	while((len=getLine(line,MAXLINE)) >= 0) {
		printf("%s", line);
	}
}

int getLine(char s[] , int lim) {
	int c , i , count;

	count = 0;
	for(i=0 ; i<lim-1 && (c=getchar())!=EOF && c!='\n' ; ++i) {
		if(c == ' ' || c == '\t')
			++count;
		else	count = 0;
//如果出现空格或者制表符就计数，当后面又出现其他字符时
//说明不是在末尾，把计数值重新置0.
		s[i] = c;

	}

	if(c == '\n' && i != count) {	//如果到了换行符的位置且这一行不是全为制表符或者空格。
		i = i - count;
		s[i] = c;
		//若含有空格或者制表符，就把这些字符的
		//其实位置用换行符和结束符替代，
		//标志着数组达到末尾。
		++i;
	}
	else if(i == count) {
		s[0] = '\0';
	}

	s[i] = '\0';
	return 0;
}