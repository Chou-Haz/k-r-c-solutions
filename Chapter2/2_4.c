#include "stdio.h"
#define MAXLINE 20

void squeeze(char s1[] , char s2[]);
int getLine(char s[],int length);

int main(int argc, char const *argv[])
{
	char s1[MAXLINE] = "abcdefg";
	char s2[MAXLINE] = "ggfdezmnnm";

	squeeze(s1,s2);
	printf("%s\n", s1);
	return 0;
}

void squeeze(char s1[],char s2[]) {
	int i,j,k;

	for(i = j = k = 0 ;s1[i] != '\0' ;++i) {	//遍历数组s1。
		while(s1[i] != s2[j++] && s2[j] != '\0') ;	
		//用另外一个循环，遍历数组s2，使其与每个数组s1的元素比较。
		//当两个数组中有某个元素相等时，或者数组s2被遍历完则退出循环。
		
		if(s2[j] == '\0') //利用刚才循环遍历递增的变量j，如果j已经到达了数组末尾位置的下标，则说明不相等。
			s1[k++] = s1[i];	//k记录将要被保留下来的数组的下标。
		j = 0;	//每次循环之后j初始化。
	}	
	s1[k] = '\0';	//当遍历完数组s1，k也到了目标数组的结尾位置，用'\0'结束。
			
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
