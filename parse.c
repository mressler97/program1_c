#include "classes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse(classes_t* item, char* line) {

	char *result;
	char copy_line[81];

	strcpy(copy_line, line);
	result = strtok(copy_line, " ");
	sscanf(result, "%49s", item->number);
	result = strtok(NULL, "$");
	sscanf(result, "%99[^\n]", item->title);
	result = strtok(NULL, " ");
	sscanf(result, "%49s", item->day);
	result = strtok(NULL, "-");
	sscanf(result, "%49s", item->stime);
	result = strtok(NULL, " ");
	sscanf(result, "%49s", item->etime);
	result = strtok(NULL, " ");
	sscanf(result, "%d", &item->year);
	return;
}
