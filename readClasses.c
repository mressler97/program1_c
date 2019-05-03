
#include <stdio.h>
#include <string.h>
#include "classes.h"
#include <stdlib.h>


int readClasses(classes_t item[]) {


char line[81];

FILE *inp;
inp = fopen("/public/csci112sp19/pgm1/classes.txt", "r");

if (inp == NULL)
{
	fprintf(stderr, "\nNo contents in file\n");
	exit(1);
}

int i = 0;
while (fgets(line, 80, inp) != NULL) {
	parse(&item[i], line); //parse function from parse file to parse the line read in into classes_t data
	i++;
}
int num_item = i;

fclose(inp);
return(num_item);
}
