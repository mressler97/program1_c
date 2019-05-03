#include <stdio.h>
#include "classes.h"
#include <string.h>
#include <stdlib.h>

#define BYCLASS "number"


int compare(const void * a, const void * b) {
	classes_t *classesA = (classes_t *)a;
	classes_t *classesB = (classes_t *)b;

	return (strcmp(classesA->number, classesB->number));
}

char *makeString(int yr) {
		char *str = malloc(15);
		if(yr == 1) {
			strcpy(str, "Freshman");
		}
		else if(yr == 2) {
			strcpy(str, "Sophomore");
		}
		else if(yr == 3) {
			strcpy(str,"Junior");
		}
		else {
			strcpy(str, "Senior");
		}
		return(str);
}

void printByNum(classes_t results[], int num_item){

	qsort(results, num_item, sizeof(classes_t), compare);

	FILE *outp;
	outp = fopen("output.txt", "a");

	fprintf(outp, "List of all classes: \n");
	for(int i = 0; i < num_item; ++i) {
		char str1[15];
		strcpy(str1, makeString(results[i].year));
		fprintf(outp, "%-50s %-7s %-10s %-3s %s-%s\n", results[i].title, results[i].number, str1,
		results[i].day, results[i].stime, results[i].etime);
	}

	fclose(outp);

}

void printByDays(char days[], int num_item, classes_t results[]) {

	FILE *outp;
	outp = fopen("output.txt", "a");

	fprintf(outp, "\nList of classes for days :%s\n", days);

	for(int i = 0; i < num_item; ++i) {

		if(strcmp(results[i].day, days) == 0) {
			char str1[15];
			strcpy(str1, makeString(results[i].year));
			fprintf(outp, "%-50s %-7s %-10s %-3s %s-%s\n", results[i].title, results[i].number, str1, results[i].day,
			 results[i].stime, results[i].etime);
		}

	}
	fclose(outp);

}

void printByYear(int y, int num_item, classes_t results[]) {

	FILE *outp;
	outp = fopen("output.txt", "a");

	fprintf(outp, "\nList of classes for students in year %d\n", y);

	for(int i = 0; i < num_item; ++i) {

		if((int)results[i].year == y) {
			char str1[15];
			strcpy(str1, makeString(results[i].year));
			fprintf(outp, "%-50s %-7s %-10s %-3s %s-%s\n", results[i].title, results[i].number, str1, results[i].day,
			 results[i].stime, results[i].etime);

		}
   	}
	fclose(outp);
}

void printByTime(char days1[], char sttime[], int num_item, classes_t results[]) {

	FILE *outp;
	outp = fopen("output.txt", "a");

	fprintf(outp, "\nList of classes by day and time: %s ", days1);
	fprintf(outp, "%s\n", sttime);

	for(int i = 0; i < num_item; ++i) {

		if((strcmp(results[i].day, days1) == 0) && (strcmp(results[i].stime, sttime) == 0)) {
			char str1[15];
			strcpy(str1, makeString(results[i].year));
			fprintf(outp, "%-50s %-7s %-10s %-3s %s-%s\n", results[i].title, results[i].number, str1, results[i].day,
			 results[i].stime, results[i].etime);
		}
	}
	fclose(outp);
}
