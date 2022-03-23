#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <string.h>

#define MAXOP 100
#define MAXLINE 100
#define MAXALP 26
#define NUMBER '0'
#define ALPHA '!'
#define SIN '@'
#define POW '#'
#define EXP '$'

void ungets(char s[]);
void clear(void);
int gettop(char []);
void push(double);
double pop(void);
double result, alp = 0.0;
int index1 = -1;
char digit[MAXALP];

int main(int argc, char const *argv[])
{
	int type;
	double op2;
	char s[MAXOP];
	double valBuff[26];
	int ch;

	// for(int i = 0; i < 26; i++) 
	// 	valBuff[i] = 0.0;

	while((type = gettop(s)) != EOF) {
		switch(type) {	
			case NUMBER:
				push(atof(s));
				break;
			// case ALPHA:
			// 	ch = s[0] - 'a';
			// 	push((valBuff[ch] == 0.0) ? ch : valBuff[ch]);
			// 	// if(valBuff[ch] != 0)
			// 	// push(valBuff[ch]);
			// 	break;
			// case SIN:
			// 	push(sin(pop()));
			// 	break;
			// case POW:
			// 	push(pow(pop(), pop()));
			// 	break;
			// case EXP:
			// 	push(exp(pop()));
			// 	break;
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
			case '=':	//提供变量的赋值。
				push(valBuff[(int)pop()] = pop());
				break;			
			case '\n':
				result = pop();
				printf("\t%.8g\n", result);
				// clear();
				// push(result);
				//存储结果，在下一次运算中如果只输入一个操作数则
				//默认将该结果参与运算。
				break;
			default :
				printf("Error: unknown command%s\n",s);	
				break;
		}
	}

	// double result = pop();
	// printf("%g\n", result);

	return 0;
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

void peek(void) {
	if(sp > 0) 
		printf("Top is %g\n", val[sp-1]);
	else
		printf("The stack is empty.\n");
}

void duplicate(void) {
	if(sp > 0) {
		int temp = pop();
		push(temp);
		push(temp);
	}
	else
		printf("The stack is empty\n");
}

void swap(void) {
	if(sp > 1) {
		double temp1, temp2;
		temp1 = pop();
		temp2 = pop();
		push(temp1);
		push(temp2);
	}
	else
		printf("Error: the number of parameters is not enough.\n");
}

void clear(void) {
	if(sp > 0) {
		val[0] = '\0';
		sp = 0;
	}
}

#include "ctype.h"
int li = 0;
char line[MAXLINE];
int getLine();

int gettop(char s[]) {
	int i, c;

	if(line[li] == '\0')
		if(getLine(line, MAXLINE) == 0) {
			return EOF;
		}
		else {
			li = 0;
		}
	// if(line[li] == '\0'){
	// 	if(getLine(line, MAXLINE) > 0) 
	// 		li = 0;
	// }

	while((s[0] = c = line[li++]) == ' ' || c == '\t')	
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = line[li++]))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	--li;
	return NUMBER;
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