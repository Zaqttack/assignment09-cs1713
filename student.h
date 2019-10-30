#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student_struct {
    int id;
    char fName[10];
    int age;
    double gpa;
} Student;

// Write code such that the input is taken from a file
void getStudentInformation(Student*,FILE*, int);

// Write code for sorting the student data by ID in increasing order – use Merge Sort
void sortStudentByID(Student*, int, int);
void mergeStudentByID(Student*, int, int, int);

// Write code for sorting the student data by GPA in increasing order – use any sorting algorithm except merge sort
void sortStudentByGPA(Student*, int);

#endif