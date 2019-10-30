#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int main(int argc, char *argv[]) {
    // Write code such that the input is taken from the file - “inputData.txt”
	FILE *infp;
	int N, i;
	
	infp = fopen("inputData.txt", "r");
	if (fopen == NULL) {
		printf("Cannot Open File!\n");
		exit(-1);
	}
	
	fscanf(infp, "%d", &N);			//scans the first N of the .txt to determine the length of the array
	
	Student students[N];			//creating the student array struct
	
	getStudentInformation(students, infp, N);
	
    // Write code for sorting the student data by ID in increasing order – use Merge Sort
    sortStudentByID(students, 0, N - 1);
	
    printf("The names for students in sorted order of their IDs are ");
    for(i=0; i<N; i++) {
		if(i < N - 1)
			printf("%s, ", students[i].fName);
		else
			printf("%s", students[i].fName);
	}
	
    // Write code for sorting the student data by GPA in increasing order – useing selection sort
    sortStudentByGPA(students, N);
	
    printf("\nThe names for students in sorted order of their GPAs are ");
    for(i=0; i<N; i++) {
		if(i < N - 1)
			printf("%s, ", students[i].fName);
		else
			printf("%s", students[i].fName);
	}
	printf("\n");

    return 0;
}

