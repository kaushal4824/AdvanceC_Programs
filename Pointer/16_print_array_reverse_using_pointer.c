/*
Question 16: Write a program in C to print the elements of an array in reverse order using pointers.

This program demonstrates:
- How to traverse an array in reverse order using pointer arithmetic
- How to access array elements from end to beginning
- How to handle array bounds when moving backwards

Questions to consider:
1. How does pointer arithmetic work when moving backwards through an array?
2. Why might we want to traverse an array in reverse order?
3. What are the potential risks of accessing array elements in reverse?
4. How can we optimize reverse traversal using pointers?
5. How does this compare to using array indexing for reverse traversal?
*/

#include <stdio.h>

// Function prototypes
void inputArray(int *arr, int size);
void displayArrayReverse(const int *arr, int size);
void displayArrayReverseUsingPtr(const int *arr, int size);

int main() {
    int size;
    
    printf("\nPrinting Array Elements in Reverse Order Using Pointer:\n");
    printf("------------------------------------------------\n");
    
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
    
    // Display array in reverse order using array indexing
    printf("\nArray elements in reverse order (using array indexing):\n");
    displayArrayReverse(arr, size);
    
    // Display array in reverse order using pointer arithmetic
    printf("\nArray elements in reverse order (using pointer arithmetic):\n");
    displayArrayReverseUsingPtr(arr, size);
    
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

// Function to display array elements in reverse order using array indexing
void displayArrayReverse(const int *arr, int size) {
    for(int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display array elements in reverse order using pointer arithmetic
void displayArrayReverseUsingPtr(const int *arr, int size) {
    const int *ptr = arr + size - 1;  // Point to last element
    
    while(ptr >= arr) {
        printf("%d ", *ptr);
        ptr--;  // Move backwards
    }
    printf("\n");
}