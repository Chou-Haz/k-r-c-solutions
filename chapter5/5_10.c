#include "stdio.h"
#include "stdlib.h"
#define MAXOP 100
#define NUMBER '0'

int gettop(char []);
void push(double);
double pop(void);
void ungets(char *);
int main(int argc, char *argv[])
{
	int type;
	double op2;
	char s[MAXOP];
	int ch;
	
	while(--argc) {
		ungets(" ");
		ungets(*++argv);
		printf("%s\n", *argv);
		switch(gettop(s)) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();	//先获取第二个操作数，不能直接用(pop() - pop())。
				push(pop() - op2);	//因为出栈的次序跟减法运算(被减数在前，减数在后)的顺序刚好相反。
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else 
					printf("Error:Zero divisor.");
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("Error:Zero divisor.");
				break;		
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default :
				printf("Error: unknown command%s\n",s);	
				break;
		}
	}
	return 0;
}

#include "ctype.h"

int getch(void);
void ungetch(int);

int gettop(char s[]) {
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')	
		;
	// printf("%c\n", c);
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	// printf("ss\n");
	if(isdigit(c)){
		// printf("ss\n");
		while(isdigit(s[++i] = c = getch()))	//收集整数部分。
			;
	}
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
				;
	s[i] = '\0';	
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error:stack full,cant push %g\n", f);
}

double pop(void) {
	if(sp > 0)
		return val[--sp];	
	//栈指针先自减，因为在前面的push操作中，自动把指针指向了下一个空位置。
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

#define BUFSIZE 100
char buf[BUFSIZE];	

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

void ungets(char *p) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters.\n");
	else 
		buf[bufp++] = *p;
}