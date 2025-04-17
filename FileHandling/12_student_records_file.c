/*
Question 12: Write a program in C to create a structure of student. Create five instances and write them in file.

This program demonstrates:
- Structure definition for student records
- Creating multiple structure instances
- Writing structure data to a file
- Basic file operations with structures
- Error handling for file operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define student structure
typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

// Function prototypes
void inputStudent(Student *s);
void displayStudent(const Student *s);
void writeStudentsToFile(const Student *students, int count, const char *filename);
void displayFileContents(const char *filename);

int main() {
    Student students[5];  // Array of 5 student records
    const char *filename = "students.txt";
    
    printf("\nStudent Record Management System:\n");
    printf("------------------------------\n");
    
    // Input 5 student records
    for(int i = 0; i < 5; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        inputStudent(&students[i]);
    }
    
    // Write records to file
    writeStudentsToFile(students, 5, filename);
    
    // Display file contents
    printf("\nContents of %s:\n", filename);
    printf("--------------------\n");
    displayFileContents(filename);
    
    return 0;
}

// Function to input student details
void inputStudent(Student *s) {
    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", s->name);
    
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

// Function to display a single student record
void displayStudent(const Student *s) {
    printf("Roll No: %d, Name: %s, Marks: %.2f\n",
           s->roll_no, s->name, s->marks);
}

// Function to write student records to file
void writeStudentsToFile(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Write each student record to file
    for(int i = 0; i < count; i++) {
        fprintf(file, "Roll No: %d\nName: %s\nMarks: %.2f\n\n",
                students[i].roll_no,
                students[i].name,
                students[i].marks);
    }
    
    fclose(file);
    printf("\nStudent records have been written to %s successfully!\n", filename);
}

// Function to display file contents
void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[100];
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Read and display file contents line by line
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
}