#include "stdio.h"
int binsearch();

int main(int argc, char const *argv[])
{
	// int a[] = {0,1};
	int a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int mid = binsearch(1,a,15);
	printf("%d\n", mid);
	return 0;
}

int binsearch(int x, int v[] ,int n) {
	int low ,high, mid,count;

	low = count = 0;
	high = n-1;
	while(low <= high) {
		mid = (low + high)/2;
		if(x < v[mid]) 
			high = mid - 1;
		else 
			low = mid + 1;
		// ++count;
	}
	// printf("count:%d\n", count);
	// printf("%d %d\n", low-1,high);
	// printf("mid:%d\n", mid);

	if(x == v[high])	//这里也可以写（low-1),但不能写mid,因为在(x == v[mid])的时候
		return high;	//循环实际上还会继续执行，直到high > low 才会退出。
	else 
		return -1;

}