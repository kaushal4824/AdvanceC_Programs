/*
Question 3: Write a program in C to demonstrate the use of the &(address of) and *(value at address) operators.

This program demonstrates:
- How & operator gets the memory address of a variable
- How * operator dereferences a pointer to get the value
- Different ways to use these operators with variables and pointers
- Common use cases and examples of both operators
*/

#include <stdio.h>

int main() {
    // Declaring variables
    int x = 10;
    int y = 20;
    int *p1, *p2;
    
    printf("\nDemonstrating Address-of (&) and Value-at-address (*) Operators:\n");
    printf("----------------------------------------------------------\n");
    
    // Using & operator to get addresses
    p1 = &x;  // p1 now holds the address of x
    p2 = &y;  // p2 now holds the address of y
    
    printf("1. Using & (Address-of) Operator:\n");
    printf("   Value of x: %d\n", x);
    printf("   Address of x (&x): %p\n", (void*)&x);
    printf("   Value of p1 (same as &x): %p\n", (void*)p1);
    
    printf("\n2. Using * (Value-at-address) Operator:\n");
    printf("   Value pointed by p1 (*p1): %d\n", *p1);
    printf("   Value pointed by p2 (*p2): %d\n", *p2);
    
    // Modifying values using pointers
    *p1 = 30;  // Modifying x through p1
    *p2 = 40;  // Modifying y through p2
    
    printf("\n3. After Modifying Values Through Pointers:\n");
    printf("   New value of x: %d\n", x);
    printf("   New value of y: %d\n", y);
    
    // Demonstrating multiple indirection
    printf("\n4. Demonstrating Operator Combinations:\n");
    printf("   &(*p1) gives address of x: %p\n", (void*)&(*p1));
    printf("   *(&x) gives value of x: %d\n", *(&x));
    
    // Common mistake demonstration (commented out to prevent errors)
    printf("\n5. Common Mistakes to Avoid:\n");
    printf("   - Using * operator on a variable that's not a pointer\n");
    printf("   - Using & operator on a constant or expression\n");
    printf("   - Dereferencing an uninitialized pointer\n");
    
    return 0;
}