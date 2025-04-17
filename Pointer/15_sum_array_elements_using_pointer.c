/*
Question 15: Write a program in C to compute the sum of all elements in an array using pointers.

This program demonstrates:
- How to traverse an array using pointer arithmetic
- How to accumulate values using pointers
- How to handle array bounds and validation

Questions to consider:
1. How does pointer arithmetic help in array traversal?
2. Why might we want to use pointers instead of array indexing?
3. How can we optimize the summation process using pointers?
4. What are the advantages of using pointers for array operations?
5. How can we handle potential overflow in the sum calculation?
*/

#include <stdio.h>

// Function prototypes
void inputArray(int *arr, int size);
void displayArray(const int *arr, int size);
int calculateSum(const int *arr, int size);

int main() {
    int size;
    
    printf("\nComputing Sum of Array Elements Using Pointer:\n");
    printf("----------------------------------------\n");
    
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
    
    // Display array
    printf("\nArray elements are:\n");
    displayArray(arr, size);
    
    // Calculate and display sum
    int sum = calculateSum(arr, size);
    printf("\nSum of all elements: %d\n", sum);
    
    // Demonstrate pointer arithmetic
    printf("\nDemonstrating pointer arithmetic:\n");
    int *ptr = arr;
    printf("First element: %d\n", *ptr);
    ptr += size - 1;  // Move to last element
    printf("Last element: %d\n", *ptr);
    
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
    const int *ptr = arr;
    
    for(int i = 0; i < size; i++) {
        printf("%d ", *ptr);
        ptr++;  // Move to next element
    }
    printf("\n");
}

// Function to calculate sum of array elements
int calculateSum(const int *arr, int size) {
    const int *ptr = arr;
    int sum = 0;
    
    for(int i = 0; i < size; i++) {
        sum += *ptr;  // Add current element to sum
        ptr++;       // Move to next element
    }
    
    return sum;
}