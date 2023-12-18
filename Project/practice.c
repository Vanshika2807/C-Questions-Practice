int addStudent(struct Student students[], int numStudents, int rollNumber, const char *name, float cgpa, const char *courses);

int deleteStudent(struct Student students[], int numStudents, int rollNumber);

bool displayStudentsByCourse(struct Student students[], int numStudents, char ch[]);

void displayAllStudent(struct Student students[], int numStudents);

void sortByRoll(struct Student students[], int numStudents);

int searchByRoll(struct Student students[], int numStudents, int rollNumber);

void sortByName(struct Student students[], int numStudents);

int searchByName(struct Student students[], int numStudents, const char *name);

float calculateAverage(struct Student students[], int n);

#define max_students 100



struct Student * students = (struct Student *)malloc(max_students*sizeof(struct Student));
if (students == NULL) {

       printf("Memory allocation failed.\n");

       return 1;

	 }

if(numStudents == max_students){

				int new_size = max_students*2;

				max_students = new_size;

				students = realloc(students,max_students*sizeof(struct Student));

			  }




Student Management System
Problem Statement
The main aim is to perform various operations on students present in a class . This code is written in linux terminal in C using static libraries

Various operations that are performed in this code are:
add a new student in a class
delete a student by its roll number
sort the students in class using name and roll number
search the students in class by their name and roll number
display details of all students enrolled in a particular course
display details of all students in class
find average cgpa of all students present in class I have used static libraries . There are total 3 files present .
Various steps to create static library or link our archive folder with main.c file
1.nano main.c 2. nano add.h (having declaration of all functions ) 3.nano addStudent.c (make a file having defination of all functions used in main.c) 4. gcc addStudent.c -o add_output 5. ar rcs archive.a add_output 6. gcc -o main_output main.c -L. archive.a now at last execute your main_output file

