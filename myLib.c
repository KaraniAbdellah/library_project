#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "myLib.h"

// Start Loading
void loading() {
	printf("\t\t\t\t");
	const int sleepDuration = 500000;
	const int total_sleep = 30;
	printf("Loading : ");
	fflush(stdout); // Empty The Tompen
	for (int i = 0; i < total_sleep; i++) {
		printf("\rLoading : ["); // Uses \r to return to the beginning of the line and reprints "Loading : [" at each iteration
		for (int j = 0; j < total_sleep; j++) {
			if (i >= j) printf("%c", 219);
			else printf(" ");
		}
		printf("] %d%%", (i + 1) * 100 / total_sleep);
		fflush(stdout);
		usleep(sleepDuration);
	}
	printf("\n");
}
// End Loading




