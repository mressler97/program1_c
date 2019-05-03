/* Name:         Michael Ressler
 * Class:        CSCI112 Programming with C
 * Assignment:   Program 1
 * Date:	 4/08/19
*/

#include <stdio.h>
#include "classes.h"
#include <stdlib.h>
#include <string.h>

#define BYCLASS "class"


int main(void) {

int num = 0;
classes_t classes[20];

num = readClasses(classes); //populates array with data structures, calls parse function from file

query(classes, num); //user query, calls to prints file and other functions

}

