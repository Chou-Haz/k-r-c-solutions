#include "stdio.h"

int main() {
	int c = getchar() != EOF;
	printf("%d",c);
}
/*

当输入任意数字或者不输入只按回车键时，结果为1，
若键入ctrl+z，结果为0.

 */