#include <conio.h> 
#include <dir.h> 
#include <process.h> 
#include <stdio.h> 
int main() 
{ 
	int check; 
	char* dirname = "dev_yash"; 
	check = mkdir(dirname); 
    if (!check) 
		printf("Directory created\n"); 
	else { 
		printf("Unable to create directory\n"); 
		exit(1); 
	} 

	getch(); 
    system("dir/p"); 
	getch(); 
} 

