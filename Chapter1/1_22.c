#include <stdio.h>
#define MAXLINE 100
#define COLUMN 15
#define TABS 8

int i;

int main() {
	int c,i,col,count;
	char s[MAXLINE];

	col = count = 0;
	while((c = getchar()) != EOF) {
		++col;
		if(c == '\t') {
			col = col + (TABS - (col % TABS));
			if(col > COLUMN)	
				col = col - col%COLUMN;
			//如果换行符缩进之后已经到了指定列之后，
			//则将记录列数的col中超过指定列的部分删掉，
			//以便在下方适配(col == COLUMN)。
		}

		if(c == ' ') {
			++count;
		}

		if(c == '\n') {
			col = 0;
		}

		if(col == COLUMN) { 
		//当列数到达指定列数时，加上换行符；
			if(c != ' ' || c != '\t')	//如果在指定列前的字符不是空格或者换行符就把它输出，再换行。
			putchar(c);			
			printf("\n");

			// if(count > 1)
			// for(i = 0; i < count-1; i++){
			// //因为下面还有一个putchar()，所以count-1；
			// //如果只有一个空格的话，就只会在下面的putchar()输出。
			// 	printf(" ");
			// }
			col = count = 0;
		}
		else if(c != ' '){	
		//如果还没到达指定列(else)且当前字符已经不是空格的话，就把之前记录的空格打印出来。
		//而如果出现连续空格且到达指定列则不打印空格(34列)。
			for(i = 0; i < count; i++)
				printf(" ");
			putchar(c);
			count = 0;
		}
	
}
}