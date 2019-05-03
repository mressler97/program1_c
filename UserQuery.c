#include <stdio.h>
#include "classes.h"
#include <string.h>
#include <stdlib.h>

void query(classes_t results[], int num){

	char userinput;
	char newLine;

	printf("Choices: \n");
	printf("a - print all classes\n");
	printf("d - print all classes for a given day combo\n");
	printf("t - print all classes for a given time\n");
	printf("s - print all classes for a given student type\n");
	printf("q - quit\n");

do {
	userinput = getchar();

	switch (userinput) {

	case 'a':

		printByNum(results, num);
		break;

	case 'd':

		printf("Enter class days to print (MWF or TR): ");
		char days[3];
		scanf("%255s", days);

		//Compares if entry is 'MWF' or 'TR', breaks if it is not.
		if((strcmp("MWF", days) != 0) && strcmp("TR", days) != 0){
			printf("invalid Entry!\n");
			break;
		}
		//sends to function to print classes by entered days.
		printByDays(days, num, results);
	break;

	case 'q':
	break;

	case 't':

		printf("Enter class day and start time to print\n ");
		char days1[3];
		char sttime[10];

		printf("Class day: ");
		scanf("%255s", days1);

		//checks for entry to equal "MWF" or "TR".
		if((strcmp("MWF", days1) != 0) && (strcmp("TR", days1) != 0)){
			printf("invalid Entry!\n");
			break;
		}

		printf("Start Time: ");
		scanf("%s", &sttime);

		if((strcmp("0900", sttime) != 0) && (strcmp("1000", sttime) != 0) && (strcmp("1100", sttime) != 0) &&
		(strcmp("1200", sttime) != 0) && (strcmp("1300", sttime) != 0) && (strcmp("1400", sttime) != 0) && (strcmp("1500", sttime) != 0)) {
			printf("Invalid Entry!\n");
			break;
		}

		printByTime(days1, sttime, num, results);
		break;

	case 's':

		printf("Enter student year (1-4): ");
		int y; //year entered to sort classes
		scanf("%d", &y);

		if((y > 4) || (y < 1)) {
			printf("Invalid Entry\n");
			break;
		}
	printByYear(y, num, results);
	break;
}

} while(userinput != 'q');


}
