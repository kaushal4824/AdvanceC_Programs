/*
Question 15: Write a program in C to create a structure of student. Create five instances and write them in file. Update 3rd record with the help of fseek().

This program demonstrates:
- Structure definition for student records
- Binary file operations with structures
- File positioning using fseek()
- Record updating in binary files
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
void writeStudentsToBinaryFile(const Student *students, int count, const char *filename);
void updateThirdRecord(const char *filename);
void displayBinaryFileContents(const char *filename);

int main() {
    Student students[5];  // Array of 5 student records
    const char *filename = "students.dat";
    
    printf("\nStudent Record Management System (Update Record):\n");
    printf("------------------------------------------\n");
    
    // Input 5 student records
    for(int i = 0; i < 5; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        inputStudent(&students[i]);
    }
    
    // Write records to binary file
    writeStudentsToBinaryFile(students, 5, filename);
    
    // Display current file contents
    printf("\nOriginal contents of %s:\n", filename);
    printf("-------------------------\n");
    displayBinaryFileContents(filename);
    
    // Update third record
    updateThirdRecord(filename);
    
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

// Function to update third record
void updateThirdRecord(const char *filename) {
    FILE *file = fopen(filename, "rb+");  // Open in binary read/write mode
    Student newStudent;
    
    if(file == NULL) {
        printf("Error opening file for update!\n");
        return;
    }
    
    // Move file pointer to third record
    fseek(file, 2 * sizeof(Student), SEEK_SET);
    
    // Input new student details
    printf("\nEnter new details for third record:\n");
    inputStudent(&newStudent);
    
    // Write the new record
    if(fwrite(&newStudent, sizeof(Student), 1, file) != 1) {
        printf("Error updating record!\n");
    } else {
        printf("\nThird record updated successfully!\n");
    }
    
    fclose(file);
}

// Function to display binary file contents
void displayBinaryFileContents(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open in binary read mode
    Student student;
    int count = 0;
    
    if(file == NULL) {
        printf("Error opening file %s!\n", filename);
        return;
    }
    
    // Read and display each student record
    while(fread(&student, sizeof(Student), 1, file) == 1) {
        printf("Record %d: ", ++count);
        displayStudent(&student);
    }
    
    fclose(file);
}