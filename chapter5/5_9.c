#include "stdio.h"
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *month, int *pday);

int main(int argc, char const *argv[])
{
	// int day = day_of_year(2011, 1, 23);
	// printf("%d\n", day);
	
	int day;
	int month;
	month_day(2012, 34, &month, &day);
	printf("month: %d,day: %d\n", month, day);
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
	// int i;
	int leap;
	leap = (year%4 == 0 && year&100 != 0) || year&400 == 0;

	char *dayp;
	dayp = daytab[leap];

	while (--month) {
		day += *dayp;
		dayp++;
	}

	// for(i = 1; i < month; i++)
	// 	day += daytab[leap][i];
	return day;
	
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	// int i;
	int leap;

	leap = year % 4 == 0 && year & 100 != 0 || year &400 == 0;

	char *dayp = daytab[leap];
	while(yearday > *++dayp) {
		yearday -= *dayp;
	}

	// for(i = 1; yearday > daytab[leap][i]; i++)
	// 	yearday -= daytab[leap][i];

	// *pmonth = dayp - *(daytab + leap);
	*pmonth = dayp - daytab[leap];	//两种写法。
	*pday = yearday;
}