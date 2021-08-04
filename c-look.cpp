#include <stdio.h>
#include <stdlib.h>
#define CYLINDERS 5000
#define REQUESTS 1000
int start = 0;
int ran_array[REQUESTS];
int test_array[REQUESTS];
int clook(int* ranArray) {

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start+1; i < REQUESTS; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	for(i = 0; i < start; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}	

	return head_movement;
}
int main (int argc, char *argv[]) {


	int i = 0;
	start = atoi(argv[1]);

	if(argc != 2) {

		printf("Please compile program with starting index from 0-4999. Ex. ./diskAlgorithms 423\n");
		exit(-1);
	}

	for(i = 0; i < REQUESTS; i++) {

		ran_array[i] = rand() % 5000;
	}

	printf("\nStart index: %d, start value: %d\n\n", start, ran_array[start]);
	printf("C-LOOK head movements: %d\n\n", clook(ran_array));

	return 0;
}
