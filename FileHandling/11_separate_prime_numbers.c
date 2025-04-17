/*
Question 11: Write a program to read n integer numbers from keyboard and store them into a file All.txt.
From the file All.txt, separate prime numbers and store them in prime.txt. Display contents of all files.

This program demonstrates:
- Reading integers from user input
- Writing numbers to a text file
- Reading numbers from a file
- Identifying prime numbers
- Creating and writing to multiple files
- Displaying file contents
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
bool isPrime(int num);
void displayFileContents(const char* filename);

int main() {
    FILE *allFile, *primeFile;
    int n, num;
    
    printf("\nNumber Separation Program (All numbers vs Prime numbers):\n");
    printf("--------------------------------------------------\n");
    
    // Get count of numbers
    printf("Enter how many numbers you want to input: ");
    scanf("%d", &n);
    
    // Open All.txt in write mode
    allFile = fopen("All.txt", "w");
    if (allFile == NULL) {
        printf("Error opening All.txt!\n");
        return 1;
    }
    
    // Read numbers and write to All.txt
    printf("\nEnter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &num);
        fprintf(allFile, "%d\n", num);
    }
    
    fclose(allFile);
    
    // Open All.txt in read mode and prime.txt in write mode
    allFile = fopen("All.txt", "r");
    primeFile = fopen("prime.txt", "w");
    
    if (allFile == NULL || primeFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    // Read numbers from All.txt and write prime numbers to prime.txt
    while(fscanf(allFile, "%d", &num) == 1) {
        if(isPrime(num)) {
            fprintf(primeFile, "%d\n", num);
        }
    }
    
    // Close both files
    fclose(allFile);
    fclose(primeFile);
    
    // Display contents of both files
    printf("\nContents of All.txt:\n");
    printf("-------------------\n");
    displayFileContents("All.txt");
    
    printf("\nContents of prime.txt:\n");
    printf("---------------------\n");
    displayFileContents("prime.txt");
    
    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if(num <= 1) return false;
    
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    
    return true;
}

// Function to display contents of a file
void displayFileContents(const char* filename) {
    FILE *file = fopen(filename, "r");
    int num;
    
    if(file == NULL) {
        printf("Error opening %s!\n", filename);
        return;
    }
    
    while(fscanf(file, "%d", &num) == 1) {
        printf("%d\n", num);
    }
    
    fclose(file);
}