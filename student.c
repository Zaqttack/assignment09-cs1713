#include<stdio.h>
#include<string.h>
#include"student.h"

// Write code such that the input is taken from a file
void getStudentInformation(Student *s,FILE *infp, int N) {
	int i;
	
	for ( i = 0; i < N; i++) {
		fscanf(infp, "%d %s %d %lf", &s[i].id, s[i].fName, &s[i].age, &s[i].gpa);
	}
}

//using merge sort
void sortStudentByID(Student *s, int low, int high) {
	int mid;
	
	if(low < high) {
		mid = (low + high) / 2;
		
		sortStudentByID(s, low, mid);
		sortStudentByID(s, mid + 1, high);
		
		mergeStudentByID(s, low, mid, high);
	}
}

void mergeStudentByID(Student *s, int low , int mid , int high) {
	int mergedSize = high - low + 1;
	Student mergedNames[mergedSize];
	int mergePos = 0;
	int leftPos = low;
	int rightPos = mid + 1;
	
	while(leftPos <= mid && rightPos <= high) {
		if(s[leftPos].id < s[rightPos].id) {
			mergedNames[mergePos++] = s[leftPos++];
		}
		else {
			mergedNames[mergePos++] = s[rightPos++];
		}
	}
	
	while(leftPos <= mid) {
		mergedNames[mergePos++] = s[leftPos++];
	}
	
	while(rightPos <= high) {
		mergedNames[mergePos++] = s[rightPos++];
	}
	
	for(mergePos = 0; mergePos < mergedSize; ++mergePos) {
		s[low + mergePos] = mergedNames[mergePos];
	}
}

// using selection sort
void sortStudentByGPA(Student *s, int length) {
	int i, j;
	int indexSmallest;
	Student temp;      // Temporary variable for swap
	
	for (i = 0; i < length - 1; ++i) {
		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < length; ++j) {
			if ( strcmp(s[j].fName, s[indexSmallest].fName) > 0) {
				indexSmallest = j;
			}
		}
		
		// Swap s[i] and s[indexSmallest]
		temp = s[i];
		s[i] = s[indexSmallest];
		s[indexSmallest] = temp;
	}
}