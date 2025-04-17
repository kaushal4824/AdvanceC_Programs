/*
Question 1: Create a structure called "Student" with members name, age, and total marks.
Write a C program to input data for two students, display their information, and find the average of total marks.

This program demonstrates:
- Structure definition and declaration
- Structure member access
- Input/output operations with structures
- Basic calculations with structure members
*/

#include <stdio.h>
#include <string.h>

// Define Student structure
typedef struct {
    char name[50];
    int age;
    float total_marks;
} Student;

// Function prototypes
void inputStudent(Student *s, int student_number);
void displayStudent(const Student *s, int student_number);
float calculateAverage(const Student *s1, const Student *s2);

int main() {
    Student student1, student2;
    float average;
    
    printf("\nStudent Information System:\n");
    printf("-------------------------\n");
    
    // Input data for two students
    inputStudent(&student1, 1);
    inputStudent(&student2, 2);
    
    // Calculate average marks
    average = calculateAverage(&student1, &student2);
    
    // Display results
    printf("\nStudent Details:\n");
    printf("--------------\n");
    displayStudent(&student1, 1);
    displayStudent(&student2, 2);
    
    printf("\nAverage Total Marks: %.2f\n", average);
    
    return 0;
}

// Function to input student details
void inputStudent(Student *s, int student_number) {
    printf("\nEnter details for Student %d:\n", student_number);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", s->name);
    
    printf("Enter Age: ");
    scanf("%d", &s->age);
    
    printf("Enter Total Marks: ");
    scanf("%f", &s->total_marks);
}

// Function to display student details
void displayStudent(const Student *s, int student_number) {
    printf("\nStudent %d:\n", student_number);
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Total Marks: %.2f\n", s->total_marks);
}

// Function to calculate average marks
float calculateAverage(const Student *s1, const Student *s2) {
    return (s1->total_marks + s2->total_marks) / 2.0f;
}