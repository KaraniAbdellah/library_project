#include <stdio.h>
#include <unistd.h>

// #include <windows.h> --> Use Sleep But in Millesecond
int main() {
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
	return 0;
}

/*
	printf("%c", 219);
	fflush(stdout);
	// sleep(1);
	usleep(sleepDuration); // take in microsecond
*/


