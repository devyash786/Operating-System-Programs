#include <stdio.h>
 
int size = 8; 
int disk_size = 200; 
void CLOOK(int arr[], int head) 
{ 
	int seek_count = 0; 
	int distance, cur_track; 
	std:vector<int> left, right; 
	std:vector<int> seek_sequence; 
	for (int i = 0; i < size; i++) { 
		if (arr[i] < head) 
			left.push_back(arr[i]); 
		if (arr[i] > head) 
			right.push_back(arr[i]); 
	} 


	std::sort(left.begin(), left.end()); 
	std::sort(right.begin(), right.end()); 

	
	for (int i = 0; i < right.size(); i++) { 
		cur_track = right[i]; 

	
		seek_sequence.push_back(cur_track); 

		
		distance = abs(cur_track - head); 

		
		seek_count += distance; 

	
		head = cur_track; 
	} 

	
	seek_count += abs(head - left[0]); 
	head = left[0]; 


	for (int i = 0; i < left.size(); i++) { 
		cur_track = left[i]; 

		
		seek_sequence.push_back(cur_track); 

	
		distance = abs(cur_track - head); 

		
		seek_count += distance; 

		
		head = cur_track; 
	} 

	printf("Total number of seek operations = ");
	printf("%d",seek_count) ; 

	printf("Seek Sequence is"); 

	for (int i = 0; i < seek_sequence.size(); i++) { 
	printf(" seek_sequence[i]"); 
	} 
} 


int main() 
{ 
	
	int arr[size] = { 176, 79, 34, 60, 
					92, 11, 41, 114 }; 
	int head = 50; 

printf( "Initial position of head: %d" , head ); 

	CLOOK(arr, head); 

	return 0; 
} 

