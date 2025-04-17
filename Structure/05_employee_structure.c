/*
Question 5: Create a structure named "Employee" to store employee details such as employee ID, name, and salary.
Write a program to input data for three employees, find the highest salary employee, and display their information.

This program demonstrates:
- Structure definition for employee records
- Array of structures
- Finding maximum value
- Comparing structure members
- Formatted output display
*/

#include <stdio.h>
#include <string.h>

// Define Employee structure
typedef struct {
    int emp_id;
    char name[50];
    float salary;
} Employee;

// Function prototypes
void inputEmployee(Employee *e, int emp_number);
void displayEmployee(const Employee *e, const char *label);
Employee* findHighestSalaryEmployee(const Employee *employees, int count);

int main() {
    Employee employees[3];  // Array of 3 employees
    Employee *highest_salary;
    
    printf("\nEmployee Information System:\n");
    printf("--------------------------\n");
    
    // Input data for three employees
    for(int i = 0; i < 3; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        inputEmployee(&employees[i], i + 1);
    }
    
    // Find employee with highest salary
    highest_salary = findHighestSalaryEmployee(employees, 3);
    
    // Display results
    printf("\nEmployee with Highest Salary:\n");
    printf("---------------------------\n");
    displayEmployee(highest_salary, "Highest Salary Employee");
    
    return 0;
}

// Function to input employee details
void inputEmployee(Employee *e, int emp_number) {
    printf("Enter Employee ID: ");
    scanf("%d", &e->emp_id);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", e->name);
    
    do {
        printf("Enter Salary: ");
        scanf("%f", &e->salary);
        
        if(e->salary <= 0) {
            printf("Invalid salary! Salary must be greater than 0.\n");
        } else {
            break;
        }
    } while(1);
}

// Function to display employee details
void displayEmployee(const Employee *e, const char *label) {
    printf("\n%s:\n", label);
    printf("Employee ID: %d\n", e->emp_id);
    printf("Name: %s\n", e->name);
    printf("Salary: $%.2f\n", e->salary);
}

// Function to find employee with highest salary
Employee* findHighestSalaryEmployee(const Employee *employees, int count) {
    const Employee *highest = &employees[0];
    
    for(int i = 1; i < count; i++) {
        if(employees[i].salary > highest->salary) {
            highest = &employees[i];
        }
    }
    
    return (Employee*)highest;
}