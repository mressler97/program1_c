#ifndef CLASSES_H
	#define CLASSES_H

typedef struct {

	char classes[20];

	char number[10];

	char title[50];

	char day[10];

	char stime[10];

	char etime[10];

	int year;

} classes_t;

char *makeString(int w);

void printByTime(char ad[], char q[], int m, classes_t zx[]);

void printByYear(int y, int z, classes_t ac[]);

void printByDays(char days[], int x, classes_t ab[]);

void query(classes_t a[], int n);

void parse(classes_t*, char* b);

int readClasses();

void printByNum(classes_t classes[], int num);

#endif
