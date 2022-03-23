#include "stdio.h"
#include "math.h"
#include "limits.h"

int main(int argc, char const *argv[])
{
	// printf("char类型最大值：%d\n", CHAR_MAX);
	// printf("char类型最小值：%d\n", CHAR_MIN);

	// printf("short类型最大值：%d\n", SHRT_MAX);
	// printf("short类型最小值：%d\n", SHRT_MIN);

	// printf("int类型最大值：%d\n", INT_MAX);
	// printf("int类型最小值：%d\n", INT_MIN);

	// printf("long类型最大值：%d\n", LONG_MAX);
	// printf("long类型最小值：%d\n", LONG_MIN);

	// printf("unsigned char类型最大值：%d\n", UCHAR_MAX);

	printf("unsigned short类型最大值：%d\n", USHRT_MAX);	

	// printf("unsigned int类型最大值：%u\n", UINT_MAX);

	// printf("unsigned long类型最大值：%u\n", ULONG_MAX);

	unsigned short sh = 0;
	int i;
	sh = pow(2,16) - 1;
	// for(i = 0; i < 16;i++) {
	// 	sh = sh + pow(2,i);
	// 	printf("%d ", sh);
	// }
	printf("%u\n", sh);

	// unsigned char c;
	// c = ~0;
	// c >>= 1;
	// printf("%u\n", c);
	// return 0;

	// signed short sh = -1;
	// sh >>= 2;
	// printf("%d\n", sh);
}