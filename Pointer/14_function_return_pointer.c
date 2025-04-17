/*
Question 14: Write a C program to demonstrate how a function returns a pointer.

This program demonstrates:
- How to return a pointer from a function
- How to handle memory allocation for returned pointers
- How to manage memory to prevent leaks

Questions to consider:
1. What are the risks of returning a pointer from a function?
2. How do we ensure proper memory management when returning pointers?
3. What happens if we return a pointer to a local variable?
4. When should we use pointer return values instead of regular return values?
5. How can we prevent memory leaks when working with returned pointers?
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* createArray(int size);
int* findMax(int *arr, int size);
int* duplicateValue(int value);

int main() {
    int size = 5;
    int value = 42;
    
    printf("\nDemonstrating Function Return Pointers:\n");
    printf("----------------------------------\n");
    
    // Example 1: Function returning dynamically allocated array
    printf("\n1. Creating and returning an array:\n");
    int *arr = createArray(size);
    if(arr != NULL) {
        printf("Created array elements: ");
        for(int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    // Example 2: Function returning pointer to maximum element
    printf("\n2. Finding maximum element:\n");
    int *max = findMax(arr, size);
    if(max != NULL) {
        printf("Maximum value: %d\n", *max);
        printf("Address of maximum value: %p\n", (void*)max);
    }
    
    // Example 3: Function returning pointer to duplicated value
    printf("\n3. Duplicating a value:\n");
    int *dup = duplicateValue(value);
    if(dup != NULL) {
        printf("Original value: %d\n", value);
        printf("Duplicated value: %d\n", *dup);
        printf("Address of duplicated value: %p\n", (void*)dup);
    }
    
    // Clean up allocated memory
    free(arr);
    free(dup);
    
    return 0;
}

// Function to create and return a dynamically allocated array
int* createArray(int size) {
    // Allocate memory for array
    int *arr = (int*)malloc(size * sizeof(int));
    
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Initialize array with some values
    for(int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    
    return arr;
}

// Function to return pointer to maximum element in array
int* findMax(int *arr, int size) {
    if(arr == NULL || size <= 0) {
        return NULL;
    }
    
    int *max = arr;
    for(int i = 1; i < size; i++) {
        if(arr[i] > *max) {
            max = &arr[i];
        }
    }
    
    return max;
}

// Function to return pointer to duplicated value
int* duplicateValue(int value) {
    int *ptr = (int*)malloc(sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    *ptr = value;
    return ptr;
}