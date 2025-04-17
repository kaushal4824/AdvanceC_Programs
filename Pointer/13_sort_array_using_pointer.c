/*
Question 13: Write a program in C to sort an array using a pointer.

This program demonstrates:
- How to use pointers for array sorting
- How to implement bubble sort using pointer arithmetic
- How to swap elements using pointers

Questions to consider:
1. How does pointer arithmetic help in array traversal during sorting?
2. Why might we want to use pointers instead of array indexing?
3. How can we optimize the sorting algorithm using pointers?
4. What are the advantages and disadvantages of using pointers for sorting?
5. How can we modify this program to sort different data types?
*/

#include <stdio.h>

// Function prototypes
void inputArray(int *arr, int size);
void displayArray(const int *arr, int size);
void bubbleSort(int *arr, int size);
void swap(int *a, int *b);

int main() {
    int size;
    
    printf("\nSorting Array Using Pointers:\n");
    printf("---------------------------\n");
    
    // Get array size from user
    printf("Enter the number of elements (1-100): ");
    scanf("%d", &size);
    
    // Input validation
    if(size <= 0 || size > 100) {
        printf("Invalid size! Please enter a number between 1 and 100.\n");
        return 1;
    }
    
    // Declare array
    int arr[size];
    
    // Input elements
    inputArray(arr, size);
    
    // Display original array
    printf("\nOriginal array:\n");
    displayArray(arr, size);
    
    // Sort array using bubble sort
    bubbleSort(arr, size);
    
    // Display sorted array
    printf("\nSorted array:\n");
    displayArray(arr, size);
    
    return 0;
}

// Function to input array elements
void inputArray(int *arr, int size) {
    printf("\nEnter %d elements:\n", size);
    
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", arr + i);
    }
}

// Function to display array elements
void displayArray(const int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Function to sort array using bubble sort
void bubbleSort(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            // Compare adjacent elements using pointer arithmetic
            if(*(arr + j) > *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}