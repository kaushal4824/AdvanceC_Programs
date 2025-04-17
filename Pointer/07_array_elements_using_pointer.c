/*
Question 7: Write a program in C to store n elements in an array and print the elements using a pointer.

This program demonstrates:
- How to use pointers with arrays
- How to perform array operations using pointer arithmetic
- Dynamic array size based on user input

Questions to consider:
1. What is the relationship between arrays and pointers in C?
2. How does pointer arithmetic work with arrays?
3. Why can we use array notation with pointers and vice versa?
4. What are the advantages of using pointers to access array elements?
5. What happens if we try to access elements beyond the array bounds?
*/

#include <stdio.h>

void inputArrayElements(int *arr, int size);
void displayArrayElements(const int *arr, int size);

int main() {
    int size;
    
    printf("\nStoring and Printing Array Elements Using Pointer:\n");
    printf("---------------------------------------------\n");
    
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
    
    // Input elements using pointer arithmetic
    inputArrayElements(arr, size);
    
    // Display elements using pointer arithmetic
    printf("\nArray elements are:\n");
    displayArrayElements(arr, size);
    
    // Demonstrate pointer arithmetic
    printf("\nDemonstrating pointer arithmetic:\n");
    int *ptr = arr;
    printf("First element: %d\n", *ptr);       // First element
    printf("Second element: %d\n", *(ptr+1)); // Second element
    printf("Last element: %d\n", *(ptr+(size-1))); // Last element
    
    return 0;
}

// Function to input array elements using pointer
void inputArrayElements(int *arr, int size) {
    printf("\nEnter %d elements:\n", size);
    
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", arr + i);  // Using pointer arithmetic
    }
}

// Function to display array elements using pointer
void displayArrayElements(const int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));  // Using pointer arithmetic
    }
    printf("\n");
}