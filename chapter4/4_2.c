#include "stdio.h"
#include "ctype.h"

double atof(char s[]);

int main(int argc, char const *argv[])
{
	char s[] = "0.0000001e+10";
	double result = atof(s);
	printf("%f\n", result);
	return 0;
}

double atof(char s[]) {
	double val, power, exponentSign, exponent;
	int i, sign;

	for(i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		++i;

	for(val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		++i;

	for(power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if(s[i] == 'e' || s[i] == 'E')
		++i;

	exponent = 0;
	exponentSign = (s[i] == '-') ? 1 : 0;
	if(s[i] == '+' || s[i] == '-')
		++i;

	while(isdigit(s[i])) {	//考虑指数有多位的情况。
		exponent = exponent*10.0 + (s[i] - '0');
		++i;
	}

	while(exponent > 0) {
		if(exponentSign) {
			power *= 10;
		}
		else {
			power /= 10;
		}
		--exponent;
	}

	return sign * val / power;
}