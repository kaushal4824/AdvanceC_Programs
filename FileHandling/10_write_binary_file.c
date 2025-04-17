/*
Question 10: Write a C program to write to a Binary file using fwrite().

This program demonstrates:
- How to write data to a binary file using fwrite()
- How to handle structure data in binary format
- How to manage binary file operations
- Error handling for binary file operations

Concepts covered:
1. Binary file operations
2. Structure data handling
3. fwrite() function usage
4. Error checking for binary operations
5. File mode for binary operations ('wb')
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for demonstration
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

int main() {
    FILE *file;
    Student students[3];  // Array of student records
    int i;
    
    printf("\nBinary File Writing Demonstration:\n");
    printf("------------------------------\n");
    
    // Initialize some student records
    students[0] = (Student){1, "John Doe", 85.5};
    students[1] = (Student){2, "Jane Smith", 92.0};
    students[2] = (Student){3, "Bob Johnson", 78.5};
    
    // Open file in binary write mode
    file = fopen("students.bin", "wb");
    
    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: Cannot create binary file!\n");
        return 1;
    }
    
    // Write student records to binary file
    size_t records_written = fwrite(students, sizeof(Student), 3, file);
    
    // Check if write was successful
    if (records_written != 3) {
        printf("Error: Failed to write all records!\n");
        fclose(file);
        return 1;
    }
    
    // Close the file
    fclose(file);
    
    printf("\nStudent records written to binary file successfully!\n");
    printf("Records written: %zu\n", records_written);
    
    // Display the written records
    printf("\nWritten Records:\n");
    printf("--------------\n");
    for(i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Score: %.1f\n\n", students[i].score);
    }
    
    printf("You can find the binary file 'students.bin' in the current directory.\n");
    
    return 0;
}