#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <stdbool.h>

#define max_students 100



struct Student {

	int rollNumber;

	char name[50];

	float cgpa;

	char courses[100];

};



int addStudent(struct Student students[], int numStudents, int rollNumber, const char *name, float cgpa, const char *courses) {

    if (numStudents >= max_students) {

        printf("Maximum number of students reached.\n");

        return numStudents;

    }



    struct Student newStudent;

    newStudent.rollNumber = rollNumber;

    strcpy(newStudent.name, name);

    newStudent.cgpa = cgpa;

    strcpy(newStudent.courses, courses);



    students[numStudents] = newStudent;



    printf("Student added successfully.\n\n");

    return numStudents + 1;

}



// Function to delete a student from the array

int deleteStudent(struct Student students[], int numStudents, int rollNumber) {

    int foundIndex = -1;



    for (int i = 0; i < numStudents; i++) {

        if (students[i].rollNumber == rollNumber) {

            foundIndex = i;

            break;

        }

    }



    if (foundIndex != -1) {

        for (int i = foundIndex; i < numStudents - 1; i++) {

            students[i] = students[i + 1];

        }

        printf("Student deleted successfully.\n");

        return numStudents - 1;

    } else {

        printf("Student not found.\n");

        return numStudents;

    }

}





bool displayStudentsByCourse(struct Student students[], int numStudents, char ch[]){

	bool flag=false;

	for (int i = 0; i < numStudents; i++) {

        	if (strcmp(students[i].courses, ch) == 0) {

                    printf("Roll Number: %d\n", students[i].rollNumber);

                    printf("Name: %s\n", students[i].name);

                    printf("CGPA: %.2f\n", students[i].cgpa);

                    printf("Courses: %s\n", students[i].courses);

                    flag = true;

        	}

    	}

    return flag;

}





// Function to display all students in the array

void displayAllStudent(struct Student students[], int numStudents) {

    if(numStudents==0){
        printf("no student to display\n");
        return;
    }
    printf("List of students:\n");

    for (int i = 0; i < numStudents; i++) {

        printf("Roll Number: %d  ", students[i].rollNumber);

        printf("Name: %s  ", students[i].name);

        printf("CGPA: %.2f  ", students[i].cgpa);

        printf("Courses: %s  ", students[i].courses);

        printf("\n");

    }

}



// Function to sort students based on their roll numbers

void sortByRoll(struct Student students[], int numStudents) {

    for (int i = 0; i < numStudents - 1; i++) {

        for (int j = 0; j < numStudents - i - 1; j++) {

            if (students[j].rollNumber > students[j + 1].rollNumber) {

                struct Student temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;

            }

        }

    }

    printf("Students sorted by Roll Number.\n");

}



// Function to search student by roll number

int searchByRoll(struct Student students[], int numStudents, int rollNumber) {

    for (int i = 0; i < numStudents; i++) {

        if (students[i].rollNumber == rollNumber) {

            return 0;

        }

    }

    return -1; // Not found

}





// Function to sort students based on their names

void sortByName(struct Student students[], int numStudents) {

    for (int i = 0; i < numStudents - 1; i++) {

        for (int j = 0; j < numStudents - i - 1; j++) {

            if (strcmp(students[j].name, students[j + 1].name) > 0) {

                struct Student temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;

            }

        }

    }

    printf("Students sorted by Name.\n");

}



// Function to search student by name

int searchByName(struct Student students[], int numStudents, const char *name) {

    for (int i = 0; i < numStudents; i++) {

        if (strcmp(students[i].name, name) == 0) {

            return i;

        }

    }

    return -1; // Not found

}



float calculateAverage(struct Student students[], int n) {

    if (n == 0) {

        return 0.0;

    } else {

        return (students[n - 1].cgpa + (n - 1) * calculateAverage(students, n - 1)) / n;

    }

}



int main() {

	struct Student students[max_students];

	int numStudents = 0;



		printf("Student Management System\n");

		printf("1. Add Student\n");

		printf("2. Delete Student by their roll number\n");

		printf("3. Display Student by their courses\n");

		printf("4. Sort by Name\n");

		printf("5. Sort by Roll Number\n");

		printf("6. Search by Roll Number\n");

		printf("7. calculate average of all students  \n");

		printf("8. display details of all students \n");

		printf("9. exit \n");
        printf("\n");

		int choice = 0;

      

	while(1) {

		printf("Enter your choice: ");
		scanf("%d", &choice);
       
		switch (choice) {

			case 1:

			  int rollNumber;

			  char name[50];

			  float cgpa;

			  char courses[100];

			  printf("Enter Roll Number: ");

                	  scanf("%d", &rollNumber);

                	  printf("Enter Name: ");

                	  scanf("%s", name);

                	  printf("Enter CGPA: ");

                	  scanf("%f", &cgpa);

                	  printf("Enter Courses: ");

                	  scanf("%s", courses);

			  numStudents = addStudent(students, numStudents, rollNumber, name, cgpa, courses);

                	  break;

			

			case 2:

			  printf("Enter the roll number you want to remove\n");

			  int roll;

			  scanf("%d",&roll);

			  numStudents = deleteStudent(students, numStudents, roll);

			break;



			case 3:

			  printf("enter the course for which you want to see students");

			  char ch[100];
              scanf("%s",&ch);

			  if(!(displayStudentsByCourse(students, numStudents , ch)))

			       printf("there is no student with this course");

			  break;

			

			case 4:

			  sortByName(students, numStudents);

			  break;



			case 5:

			  sortByRoll(students, numStudents);

			  break;





			case 6:

			  printf("enter the roll number want to search");

			  int roll2;

			  scanf("%d",&roll2);

			  int searchResult = searchByRoll(students, numStudents, roll2);

			  if(searchResult != -1){

				printf("student found:\n");

				printf("Roll Number: %d\n", students[searchResult].rollNumber);

                    		printf("Name: %s\n", students[searchResult].name);

                    		printf("CGPA: %.2f\n", students[searchResult].cgpa);

                    		printf("Courses: %s\n", students[searchResult].courses);

                		} else {

                    			printf("Student not found.\n");

                		}

                		break;



			case 7:

			  float avgCGPA= calculateAverage(students, numStudents);

			  printf("Average cgpa : %.2f\n", avgCGPA);

			  break;



			case 8:

			  displayAllStudent(students,numStudents);

			  break;



			case 9:

			  printf("program finished successfully");

			  return 0;



			default:

			  printf("Invalid choice");
              break;


			} 

               }

		return 0;

}

