#include "stdio.h"

void ungetch(int);
int getfloat(float *pn);

int main(int argc, char const *argv[])
{
	float number = 0.0;

	while(getfloat(&number) != 0)
		printf("%.1f\n", number);

	return 0;
}

#include "ctype.h"

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
	int c, d, sign;
	float power;

	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	
	if(c == '+' || c == '-')
		c = getch();

	for(*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');

	if(c == '.')
		c = getch();

	for(power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}

	*pn = *pn * sign / power;
	if(c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100
float buf[BUFSIZE];	
//用于ungetch()里的缓冲区，getch()也可以使用。
//将buf数组的类型修改为int，这样就不会导致‘EOF’
//从char型转换为int型时不再是-1的问题。
int bufp = 0;	//缓冲区下一个空闲位置。

int getch(void) {	//取出一个数，如果缓冲区有数则先取出缓冲区的。
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters.\n");
	else 
		buf[bufp++] = c;
}