/*
Program 9: Calculate average of n numbers using variable length arguments
This program demonstrates:
- Use of variable length arguments
- Use of stdarg.h header
- Input validation
*/

#include <stdio.h>
#include <stdarg.h>

// Function prototype
double calculateAverage(int count, ...);

int main() {
    printf("\nVariable Arguments Average Calculator\n");
    printf("--------------------------------\n");
    
    // Test cases with different number of arguments
    printf("Average of 2 numbers (5, 10): %.2f\n", 
           calculateAverage(2, 5, 10));
    
    printf("Average of 3 numbers (15, 20, 25): %.2f\n", 
           calculateAverage(3, 15, 20, 25));
    
    printf("Average of 4 numbers (2, 4, 6, 8): %.2f\n", 
           calculateAverage(4, 2, 4, 6, 8));
    
    printf("Average of 5 numbers (1, 3, 5, 7, 9): %.2f\n", 
           calculateAverage(5, 1, 3, 5, 7, 9));
    
    return 0;
}

// Function to calculate average using variable arguments
double calculateAverage(int count, ...) {
    va_list args;
    double sum = 0.0;
    
    // Initialize variable argument list
    va_start(args, count);
    
    // Calculate sum of all numbers
    for(int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    
    // Clean up argument list
    va_end(args);
    
    // Return average
    return (count > 0) ? (sum / count) : 0;
}