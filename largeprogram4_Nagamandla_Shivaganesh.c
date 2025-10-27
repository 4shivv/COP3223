//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 1
//Large Program 4

#include <stdio.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 5

// Define the weights for assessments
#define HOMEWORK_WEIGHT 0.5
#define QUIZ_WEIGHT 0.2
#define EXAM_WEIGHT 0.3

// Define the struct for a student
typedef struct {
    char fullName[50];
    double homeworkAverage;
    double quizAverage;
    double examAverage;
} Student;

// Function prototypes
int findStudentIndexById(Student students[], int id);
void printStudentGrades(Student student);
void printAllStudents(Student students[], int size);
void exportToFile(Student students[], int size);
void addStudent(Student students[], int *size);
void removeStudent(Student students[], int *size);
void updateStudentGrades(Student students[], int size);
void printMissingGrades(Student students[], int size);
void searchStudentById(Student students[], int size);

int main() 

{
    // Initialize the array of students
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    char choice;

    printf("Welcome to your gradebook management system!\n");
    printf("************************************\n");

    do 
    {
        // Menu options
        printf("A: Add   R: Remove   P: Print   U: Update   M: Missing   S: Search   D: Display   E: Exit\n");
        printf("************************************\n");
        printf("Selection: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case 'A': case 'a':
                addStudent(students, &studentCount);
                break;

            case 'R': case 'r':
                removeStudent(students, &studentCount);
                break;

            case 'P': case 'p':
                printAllStudents(students, studentCount);
                break;

            case 'U': case 'u':
                updateStudentGrades(students, studentCount);
                break;

            case 'M': case 'm':
                printMissingGrades(students, studentCount);
                break;

            case 'S': case 's':
                searchStudentById(students, studentCount);
                break;

            case 'D': case 'd':
                printAllStudents(students, studentCount);
                break;

            case 'E': case 'e':
                exportToFile(students, studentCount);
                printf("Exiting and exporting all records to gradebook.txt\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } 
    while (choice != 'E' && choice != 'e');

    return 0;
}

// Function to find the index of a student by ID
int findStudentIndexById(Student students[], int id) 
{
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (students[i].examAverage > 0 && i + 1 == id) 
        {
            return i;
        }
    }
    return -1;  // ID not found
}

// Function to print a student's grades
void printStudentGrades(Student student) 
{
    printf("************************************\n");
    printf("Name: %s\n", student.fullName);
    printf("Homework: %.2f%%   Quiz: %.2f%%   Exam: %.2f%%\n", student.homeworkAverage, student.quizAverage, student.examAverage);

    // Calculate weighted average
    double weightedAverage = (student.homeworkAverage * HOMEWORK_WEIGHT +
                              student.quizAverage * QUIZ_WEIGHT +
                              student.examAverage * EXAM_WEIGHT) * 100.0 / (HOMEWORK_WEIGHT + QUIZ_WEIGHT + EXAM_WEIGHT);

    printf("Weighted Avg: %.2f%%\n", weightedAverage);
}

// Function to print all students' grades
void printAllStudents(Student students[], int size) 
{
    printf("List of students and IDs:\n");

    for (int i = 0; i < size; ++i) {
        if (students[i].examAverage > 0) {
            printf("ID: %d  %s\n", i + 1, students[i].fullName);
        }
    }
}

// Function to export all records to a file
void exportToFile(Student students[], int size) 
{
    FILE *file = fopen("gradebook.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < size; ++i) 
    {
        // Export student records to file
        fprintf(file, "Name: %s\n", students[i].fullName);
        fprintf(file, "Homework: %.2f%%   Quiz: %.2f%%   Exam: %.2f%%\n", students[i].homeworkAverage, students[i].quizAverage, students[i].examAverage);

        // Calculate weighted average for export
        double weightedAverage = (students[i].homeworkAverage * HOMEWORK_WEIGHT +
                                  students[i].quizAverage * QUIZ_WEIGHT +
                                  students[i].examAverage * EXAM_WEIGHT) * 100.0 / (HOMEWORK_WEIGHT + QUIZ_WEIGHT + EXAM_WEIGHT);

        fprintf(file, "Weighted Avg: %.2f%%\n\n", weightedAverage);
    }

    fclose(file);
}

// Function to add a student to the gradebook
void addStudent(Student students[], int *size) 
{
    if (*size >= MAX_STUDENTS) 
    {
        printf("Gradebook is full!\n");
        return;
    }

    printf("Enter Student's Full Name: ");
    scanf(" %[^\n]s", students[*size].fullName);

    (*size)++;
}

// Function to remove a student from the gradebook
void removeStudent(Student students[], int *size) 
{
    printf("List of students and IDs:\n");
    printAllStudents(students, *size);

    printf("Enter ID of student to remove: ");
    int id;
    scanf("%d", &id);

    int index = findStudentIndexById(students, id);

    if (index != -1) 
    {
        printf("Removing %s from gradebook.\n", students[index].fullName);
        memset(&students[index], 0, sizeof(Student));  // Reset student data
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to update a student's grades
void updateStudentGrades(Student students[], int size) 
{
    printf("List of students and IDs:\n");
    printAllStudents(students, size);

    printf("Enter ID of the student: ");
    int id;
    scanf("%d", &id);

    int index = findStudentIndexById(students, id);

    if (index != -1) 
    {
        printf("Enter Homework Avg: ");
        scanf("%lf", &students[index].homeworkAverage);

        printf("Enter Quiz Avg: ");
        scanf("%lf", &students[index].quizAverage);

        printf("Enter Exam Avg: ");
        scanf("%lf", &students[index].examAverage);

        printf("Grades updated for %s.\n", students[index].fullName);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to print students with missing grades
void printMissingGrades(Student students[], int size) 
{
    printf("Students with Missing Grades:\n");

    for (int i = 0; i < size; ++i) 
    {
        if (students[i].examAverage <= 0) {
            printf("ID %d: %s\n", i + 1, students[i].fullName);
        }
    }
}

// Function to search for a student by ID
void searchStudentById(Student students[], int size) 
{
    printf("Enter ID of the student: ");
    int id;
    scanf("%d", &id);

    int index = findStudentIndexById(students, id);

    if (index != -1) 
    {
        printStudentGrades(students[index]);
    } else 
    {
        printf("Student with ID %d not found.\n", id);
    }
}