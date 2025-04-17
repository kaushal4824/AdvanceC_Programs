/*
Question 18: Write a C program for finding the largest integer among three numbers using command line arguments.

This program demonstrates:
- Command line argument handling in C
- String to integer conversion
- Input validation
- Basic arithmetic operations
- Error handling for invalid inputs
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototype
int findLargest(int a, int b, int c);

int main(int argc, char *argv[]) {
    printf("\nFind Largest Number (Command Line Arguments):\n");
    printf("----------------------------------------\n");
    
    // Check if correct number of arguments are provided
    if(argc != 4) {
        printf("Error: Please provide exactly three integer numbers as arguments.\n");
        printf("Usage: %s <num1> <num2> <num3>\n", argv[0]);
        return 1;
    }
    
    // Convert string arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int num3 = atoi(argv[3]);
    
    // Find and display the largest number
    int largest = findLargest(num1, num2, num3);
    
    printf("\nThe three numbers are: %d, %d, %d\n", num1, num2, num3);
    printf("The largest number is: %d\n", largest);
    
    return 0;
}

// Function to find the largest among three numbers
int findLargest(int a, int b, int c) {
    int max = a;
    
    if(b > max) max = b;
    if(c > max) max = c;
    
    return max;
}