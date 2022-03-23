#include "stdio.h"
#include "math.h"
#define MAXLENGTH 20
int i;
void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	int num = -16;
	char res[MAXLENGTH];
	// for(i = 0;i < MAXLENGTH;++i)
	// 	res[i] = 0;
	itoa(num, res);
	printf("%s\n", res);
	return 0;
}

void itoa(int n, char s[]) {
	extern int i;
	int sign;

	i = 0;
	sign = n;
	do {
		s[i++] = fabs(n%10) + '0';
	} while((n /= 10) != 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	extern int i;
	int j,temp;
	for(j=0,--i;i > j ; ++j,--i) {	//初始化j=0，i减去1(结束符)。
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	//只修改前面的数值，结束符不受影响。
}