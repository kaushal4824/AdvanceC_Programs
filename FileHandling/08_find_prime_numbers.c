/*
Question 8: Write a program to read n integer numbers from keyboard and store them into a file All.txt.
From the file All.txt, separate prime numbers and store them into file prime.txt.
Display contents of all the files.

This program demonstrates:
- How to handle multiple files for number processing
- How to identify prime numbers
- How to manage file operations for number storage
- Error handling for multiple file operations

Concepts covered:
1. Multiple file pointer management
2. Prime number identification
3. File reading and writing operations
4. Error handling for multiple files
5. File content display techniques
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
bool isPrime(int num);
void displayFileContents(const char* filename);

int main() {
    FILE *all_file, *prime_file;
    int num, count;
    
    printf("\nPrime Number Separation Demonstration:\n");
    printf("--------------------------------\n");
    
    // Get count of numbers
    printf("How many numbers do you want to enter? (1-100): ");
    scanf("%d", &count);
    
    // Input validation
    if(count <= 0 || count > 100) {
        printf("Invalid count! Please enter between 1 and 100.\n");
        return 1;
    }
    
    // Open All.txt in write mode
    all_file = fopen("All.txt", "w");
    if (all_file == NULL) {
        printf("Error creating All.txt!\n");
        return 1;
    }
    
    // Input numbers and write to All.txt
    printf("\nEnter %d numbers:\n", count);
    for(int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(all_file, "%d\n", num);
    }
    
    fclose(all_file);
    
    // Reopen All.txt in read mode
    all_file = fopen("All.txt", "r");
    if (all_file == NULL) {
        printf("Error opening All.txt for reading!\n");
        return 1;
    }
    
    // Open prime.txt in write mode
    prime_file = fopen("prime.txt", "w");
    if (prime_file == NULL) {
        printf("Error creating prime.txt!\n");
        fclose(all_file);
        return 1;
    }
    
    // Read numbers from All.txt and find primes
    while (fscanf(all_file, "%d", &num) == 1) {
        if (isPrime(num)) {
            fprintf(prime_file, "%d\n", num);
        }
    }
    
    // Close all files
    fclose(all_file);
    fclose(prime_file);
    
    // Display contents of all files
    printf("\nContents of All.txt:\n");
    printf("-------------------\n");
    displayFileContents("All.txt");
    
    printf("\nContents of prime.txt (Prime Numbers):\n");
    printf("----------------------------------\n");
    displayFileContents("prime.txt");
    
    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

// Function to display contents of a file
void displayFileContents(const char* filename) {
    FILE *file = fopen(filename, "r");
    int num;
    
    if (file == NULL) {
        printf("Error opening %s!\n", filename);
        return;
    }
    
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d\n", num);
    }
    
    fclose(file);
}