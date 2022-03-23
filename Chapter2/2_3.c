#include "stdio.h"
#include "math.h"

void htoi(char s[]);
int getLine(char s[],int length);

int main(int argc, char const *argv[])
{
	int c, len, num;
	char line[20];
	while((len=getLine(line,20)) > 0) {
		htoi(line);
	}
}

void htoi(char s[]) {
	int index, i, num;
	index = num = 0;
	// printf("in:%s", s[0]);

	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		index = index + 2;
	}

	while(s[index] != '\n') {

		num = num * 16;	//在新的一位要加上数之前前面的位数要先加一。

		if(s[index] >= 'A' && s[index] <= 'Z') {
			s[index] = s[index] + 'a' - 'A';
		}

		if(s[index] > '9' && s[index] <= 'f') {
			s[index] = 10 + s[index] - 'a';
			num = num + s[index];
		}
		else if(s[index] <= '9') {
			num = num + s[index];
		}
		else {
			printf("The data is illegal.\n");
			s[index+1] = '\n';
		}

		++index;
	}
	printf("%d\n", num);
	// return num;
}

int getLine(char s[] , int lim) {
	int c , i;

	for(i = 0; i<lim-1 && (c=getchar())!=EOF &&c !='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}