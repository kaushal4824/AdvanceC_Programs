/*
Question 19: Write a program in C to find the largest element using Dynamic Memory Allocation.

This program demonstrates:
- How to use dynamic memory allocation with malloc()
- How to work with pointers for array operations
- How to handle memory management properly

Questions to consider:
1. Why do we need dynamic memory allocation?
2. How does malloc() work with pointers?
3. What are the advantages of dynamic arrays over static arrays?
4. How do we prevent memory leaks?
5. What are the best practices for memory management?
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* createDynamicArray(int size);
void inputArrayElements(int *arr, int size);
int findLargest(const int *arr, int size);
void displayArray(const int *arr, int size);

int main() {
    int size;
    int *arr;
    
    printf("\nFind Largest Element Using Dynamic Memory Allocation:\n");
    printf("----------------------------------------------\n");
    
    // Get array size from user
    printf("Enter the number of elements (1-100): ");
    scanf("%d", &size);
    
    // Input validation
    if(size <= 0 || size > 100) {
        printf("Invalid size! Please enter a number between 1 and 100.\n");
        return 1;
    }
    
    // Allocate memory dynamically
    arr = createDynamicArray(size);
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input array elements
    inputArrayElements(arr, size);
    
    // Display the array
    printf("\nThe array elements are:\n");
    displayArray(arr, size);
    
    // Find and display the largest element
    int largest = findLargest(arr, size);
    printf("\nThe largest element is: %d\n", largest);
    
    // Free allocated memory
    free(arr);
    printf("\nMemory has been freed successfully!\n");
    
    return 0;
}

// Function to create dynamic array using malloc
int* createDynamicArray(int size) {
    return (int*)malloc(size * sizeof(int));
}

// Function to input array elements
void inputArrayElements(int *arr, int size) {
    printf("\nEnter %d elements:\n", size);
    
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", arr + i);
    }
}

// Function to find largest element using pointer arithmetic
int findLargest(const int *arr, int size) {
    const int *ptr = arr;
    int largest = *ptr;  // Initialize with first element
    
    // Traverse array using pointer arithmetic
    for(int i = 1; i < size; i++) {
        if(*(ptr + i) > largest) {
            largest = *(ptr + i);
        }
    }
    
    return largest;
}

// Function to display array elements
void displayArray(const int *arr, int size) {
    const int *ptr = arr;
    
    for(int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}