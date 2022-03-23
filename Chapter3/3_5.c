#include "stdio.h"
#include "math.h"
int i;
void itob(int n, int b, char s[]);
void reverse();

int main(int argc, char const *argv[])
{
	int num = -15;
	char res[10];
	itob(num, 2, res);
	printf("%s\n", res);
	return 0;
}

void itob(int n, int b, char s[]) {
	extern int i;
	int sign;

	i = 0;
	sign = n;
	do {
		s[i++] = fabs(n%b) + '0';
	} while((n /= b) != 0);

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