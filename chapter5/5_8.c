#include "stdio.h"
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *month, int *pday);

int main(int argc, char const *argv[])
{
	int day = day_of_year(2011, 1, 23);
	printf("%d\n", day);
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = (year%4 == 0 && year&100 != 0) || year&400 == 0;

	// switch(month) {
	// 	case 1:case 3:case 
	// }
	if(month < 1 || month > 12) {
		return -1;
	}
	else if(day > daytab[leap][month] || day < 1){
		return -1;
	}

	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
	
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year % 4 == 0 && year & 100 != 0 || year &400 == 0;

	if(yearday < 1){
		*pmonth = -1;
		*pday = -1;
		return;
	}	//检查年份是否小于1.

	for(i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
		//在循环条件中通过判断年份是否已经大于i,
		//来加上判断是否yearday超出了一年的天数。
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}