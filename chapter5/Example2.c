#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAXLINES 5000
#define null 0
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(char *lineptr[], int left, int right);

int main(int argc, char const *argv[])
{
	int nlines;

	if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		quick_sort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error.\n");
		return 1;
	}
}

#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;

	while((len = getLine(line,MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == null)
			return -1;
		else {
			// printf("%d\n", len);
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

int getLine(char *s, int lim) {
	int c;
	char *t = s;

	for(; --lim > 0 && (c = getchar())!=EOF && c != '\n'; s++) 
		*s = c;
	if(c == '\n') {
		*s = c;
		s++;
	}
	*s = '\0';
	return s - t;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
	if(allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

void afree(char *p) {
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

void writelines(char *lineptr[], int nlines) {
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void quick_sort(char *v[], int left, int right) {
	int i, last;
	int strncmp1(char *s, char *t);
	void swap(char *v[], int i, int j);

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quick_sort(v, left, last-1);
	quick_sort(v, last+1, right);
}

int strncmp1(char *s, char *t) {
	for( ; *s == *t; s++, t++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}

void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}