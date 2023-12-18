#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//add time and space complexity
#define MAX_STUDENTS 100

struct Student {
    int rollNumber;
    char name[50];
    float cgpa;
    char courses[100];
};

// Function to add a student to the array
int addStudent(struct Student students[], int numStudents, int rollNumber, const char *name, float cgpa, const char *courses) {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return numStudents;
    }

    struct Student newStudent;
    newStudent.rollNumber = rollNumber;
    strcpy(newStudent.name, name);
    newStudent.cgpa = cgpa;
    strcpy(newStudent.courses, courses);

    students[numStudents] = newStudent;

    printf("Student added successfully.\n");
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

// Function to display all students in the array
void displayStudents(struct Student students[], int numStudents) {
    printf("List of students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("Courses: %s\n", students[i].courses);
        printf("\n");
    }
}

// Function to sort students based on their roll numbers
void sortByRollNumber(struct Student students[], int numStudents) {
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
int searchByRollNumber(struct Student students[], int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
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

// Function to get a random student using Fisher-Yates shuffle

// struct Student getRandomStudent(struct Student students[], int numStudents) {
//     if (numStudents == 0) {
//         struct Student emptyStudent = {0, "", 0.0, ""};
//         return emptyStudent;
//     }

//     int randomIndex = rand() % numStudents;
//     struct Student temp = students[randomIndex];
//     students[randomIndex] = students[numStudents - 1];
//     students[numStudents - 1] = temp;

//     return students[numStudents - 1];
// }

void fisherYatesShuffle(struct Student students[], int numStudents) {
    for (int i = numStudents - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
    }
}

float calculateAverage(struct Student students[], int n) {
    if (n == 0) {
        return 0.0;
    } else {
        return (students[n - 1].cgpa + (n - 1) * calculateAverage(students, n - 1)) / n;
    }
}

struct Student getRandomStudent(struct Student students[], int numStudents, int rollNumber, const char *name) {
    fisherYatesShuffle(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        if ((rollNumber == 0 || students[i].rollNumber == rollNumber) &&
            (strcmp(name, "") == 0 || strcmp(students[i].name, name) == 0)) {
            return students[i];
        }
    }

    struct Student emptyStudent = {0, "", 0.0, ""};
    return emptyStudent;
}


int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        int choice;
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Sort Students by Roll Number\n");
        printf("5. Search Student by Roll Number\n");
        printf("6. Exit\n");
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
                printf("Enter Roll Number to delete: ");
                scanf("%d", &rollNumber);
                numStudents = deleteStudent(students, numStudents, rollNumber);
                break;

            case 3:
                displayStudents(students, numStudents);
                break;

            case 4:
                sortByRollNumber(students, numStudents);
                break;

            case 5:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNumber);
                int searchResult = searchByRollNumber(students, numStudents, rollNumber);
                if (searchResult != -1) {
                    printf("Student found:\n");
                    printf("Roll Number: %d\n", students[searchResult].rollNumber);
                    printf("Name: %s\n", students[searchResult].name);
                    printf("CGPA: %.2f\n", students[searchResult].cgpa);
                    printf("Courses: %s\n", students[searchResult].courses);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

        float averageCGPA = calculateAverage(students, numStudents);

    printf("Average CGPA: %.2f\n", averageCGPA);
    }

    return 0;
}
