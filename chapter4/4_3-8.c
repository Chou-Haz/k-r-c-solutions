#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <string.h>

#define MAXOP 100
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

int main(int argc, char const *argv[])
{
	int type;
	double op2, index;
	char s[MAXOP];
	double valBuff[26];
	int ch;

	for(int i = 0; i < 26; i++) 
		valBuff[i] = 0.0;

	while((type = gettop(s)) != EOF) {
		switch(type) {			
			case NUMBER:
				push(atof(s));
				break;
			case ALPHA:
				ch = s[0] - 'a';
				push((valBuff[ch] == 0.0) ? ch : valBuff[ch]);
				// if(valBuff[ch] != 0)
				// push(valBuff[ch]);
				break;
			case SIN:
				push(sin(pop()));
				break;
			case POW:
				push(pow(pop(), pop()));
				break;
			case EXP:
				push(exp(pop()));
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
			case '=':	//提供变量的赋值。
				push(valBuff[(int)pop()] = pop());
				break;				
			case '\n':
				result = pop();
				printf("\t%.8g\n", result);
				clear();
				push(result);	
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

int getch(void);
void ungetch(int);

int gettop(char s[]) {
	int i, c, sign;

	while((s[0] = c = getch()) == ' ' || c == '\t')	
		;	//获取将要输入的数据，直到不是空白符为止，
			// 循环结束时s[0]将存储第一个非空白的字符。
	//为了能够将同一个值用于两种判断，
	//将获得的值存储于变量c，用于第二个判定。
	//而s[0]储存第一个有效数字的
	s[1] = '\0';
	

	if(c >= 'a' && c <= 'z'){
		// push(c);
		// alp = c;
		s[1] = getch();
		s[2] = getch();
		if(s[0] == 's' && s[1] == 'i' && s[2] == 'n') 
			return SIN;
		else if(s[0] == 'e' && s[1] == 'x' && s[2] == 'p')
			return EXP;
		else if(s[0] == 'p' && s[1] == 'o' && s[2] == 'w')
			return POW;
		else {
			ungetch(s[2]);
			ungetch(s[1]);
			s[1] = '\0';
		}

		return ALPHA;
	}

	//先在s[1]中存入结束符，接着会判定s[0]存入的数(c)是不是数或者小数点，
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	//如果都不是就说明不是一个有效的数字，可能是一个运算符号
	//直接将其看作一个只有单个字符的字符串返回。
	//反之，s[0]存储的是一个有效的数字的一部分。
	//而如果是'-'，则可能代表负号也可能代表减法运算。
	i = 0;
	if(c == '-') {
		s[++i] = c = getch();
	}

	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))	//收集整数部分。
			;	//这里数组s的下标先自增再使用，
				//因为先将i初始化为0，而s[0]本来是有值的。
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
				;
	s[i] = '\0';	
		//当循环退出时s[i]保存的就不是数字，可能是'\0',也可能不是，
		//所以直接明确填充'\0',标志数组已结束。
	if(c != EOF)
		ungetch(c);
		//当读取到第一个非数字的字符时，判断是否为结束标识符，
		//如果不是则说明该字符是下一次读入需要使用的数据，
		//需要把它重新压回栈中，留待下次读入使用。
		//而如果是'\0'，则不用做处理。
	return NUMBER;	
}

#define BUFSIZE 100
int buf[BUFSIZE];	
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

void ungets(char s[]) {
	int len = strlen(s);
	while(len > 0) {
		ungetch(s[--len]);
	}
}