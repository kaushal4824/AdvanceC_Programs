/*
Question 13: Write a program in C to create a structure of student. Create five instances and write them in binary file. Append a new record in binary file.

This program demonstrates:
- Structure definition for student records
- Binary file operations (fwrite, fread)
- Appending records to binary files
- Error handling for binary file operations
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
void writeStudentsToBinaryFile(const Student *students, int count, const char *filename);
void appendStudentToBinaryFile(const Student *student, const char *filename);
void displayBinaryFileContents(const char *filename);

int main() {
    Student students[5];  // Array of 5 student records
    Student newStudent;    // New student record to append
    const char *filename = "students.bin";
    
    printf("\nStudent Record Management System (Binary File):\n");
    printf("------------------------------------------\n");
    
    // Input 5 student records
    for(int i = 0; i < 5; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        inputStudent(&students[i]);
    }
    
    // Write records to binary file
    writeStudentsToBinaryFile(students, 5, filename);
    
    // Display current file contents
    printf("\nCurrent contents of %s:\n", filename);
    printf("-------------------------\n");
    displayBinaryFileContents(filename);
    
    // Input and append new student record
    printf("\nEnter details for new student to append:\n");
    inputStudent(&newStudent);
    appendStudentToBinaryFile(&newStudent, filename);
    
    // Display updated file contents
    printf("\nUpdated contents of %s:\n", filename);
    printf("-------------------------\n");
    displayBinaryFileContents(filename);
    
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

// Function to write student records to binary file
void writeStudentsToBinaryFile(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");  // Open in binary write mode
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Write all student records at once
    size_t written = fwrite(students, sizeof(Student), count, file);
    
    if(written != count) {
        printf("Error writing to file!\n");
    } else {
        printf("\nStudent records have been written to %s successfully!\n", filename);
    }
    
    fclose(file);
}

// Function to append a student record to binary file
void appendStudentToBinaryFile(const Student *student, const char *filename) {
    FILE *file = fopen(filename, "ab");  // Open in binary append mode
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Append the new student record
    size_t written = fwrite(student, sizeof(Student), 1, file);
    
    if(written != 1) {
        printf("Error appending to file!\n");
    } else {
        printf("\nNew student record has been appended to %s successfully!\n", filename);
    }
    
    fclose(file);
}

// Function to display binary file contents
void displayBinaryFileContents(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open in binary read mode
    Student student;
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Read and display each student record
    while(fread(&student, sizeof(Student), 1, file) == 1) {
        displayStudent(&student);
    }
    
    fclose(file);
}