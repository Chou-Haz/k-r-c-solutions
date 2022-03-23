#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define NUMBER '0'
#define OPERATOR '+'
#define INVALID  'N'

int exp_type(char *s, double *value, char *op);

/* expr evaluate a reverse Polish expression from the command line per time. 
 * This is the solution to K&R C 5-10 */
int main(int argc, char* argv[])
{
	double value;
	char op;
	double opr2;

	if (argc == 1)
	{
		printf("Please input the RPN expression!\n");
		return -1;
	}
	while (--argc > 0)
	{
		switch (exp_type(*++argv, &value, &op))
		{
		case NUMBER:
			push(value);
			break;
		case OPERATOR:
			if (op == '+')
				push(pop() + pop());
			else if (op == '-'){
				opr2 = pop();
				push(pop() - opr2);
			}
			else if (op == '*')
			{
				push(pop() * pop());
			}
			else if (op == '/')
			{
				opr2 = pop();
				push(pop() / opr2);
			}
			else{
				clearstack();
				printf("Invalid RPN expression!\n");
				return -1;
			}
			break;
		default:
			clearstack();
			printf("Invalid RPN expression!\n");
			return -1;
		}
	}
    
	printf("%g", pop());
	return 0;
}
/* exp_type: identify the type of tokens in a RPN expression */
int exp_type(char *s, double *value, char *op)
{
	int len = strlen(s);
	char *endp;

	*value = strtod(s, &endp);	/* check if it's a number */
	if (*endp == '\0')
		return NUMBER;
	else if (strlen(endp) == 1)
	{
		switch (*s)
		{
		case '+':
			*op = '+';
			return OPERATOR;
		case '-':
			*op = '-';
			return OPERATOR;
		case '*':
			*op = '*';
			return OPERATOR;
		case '/':
			*op = '/';
			return OPERATOR;
		default:
			return INVALID;
		}
	}
	else
		return INVALID;
}

#include <stdio.h>

#define MAXVAL 100 /*maximum depth of val stack */

static int sp = 0;
static double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n");
}

/* pop: pop and return the top value of the stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty, can't pop\n");
		return 0.0;
	}
}

/* top: return the top element of the stack */
double top(void)
{	
	if (sp > 0)
		return val[sp - 1];
	else{
		printf("error: stack empty, no top element!\n");
		return 0.0;
	}
}

/* duptop: dup the top element of the stack */
void duptop(void)
{
	if (sp == 0){
		printf("error: stack empty, can't duplicate!\n");
		return;
	}
	if (sp == MAXVAL){
		printf("error: stack full, can't duplicate %g\n", top());
		return;
	}

	push(top());
}

/* swtop: swap the top 2 elements of the stack */
void swtop(void)
{
	double temp;
	if (sp > 1){
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else
		printf("error: no enough elements to perform swap.\n");
}

/* clearstack: clear the stack. This maybe useful when the 
 * the status of the calculator is in chaos. */
void clearstack(void)
{
	sp = 0;
}