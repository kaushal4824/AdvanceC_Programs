/*
Question 4: Define a structure named Circle to represent a circle with a radius.
Write a C program to calculate the area and perimeter of two circles and display the results.

This program demonstrates:
- Structure definition for geometric shapes
- Mathematical calculations with structure members
- Formatted output display
- Basic input validation
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Define Circle structure
typedef struct {
    float radius;
    float area;
    float perimeter;
} Circle;

// Function prototypes
void inputCircle(Circle *c, int circle_number);
void calculateCircleProperties(Circle *c);
void displayCircle(const Circle *c, int circle_number);

int main() {
    Circle circle1, circle2;
    
    printf("\nCircle Calculator:\n");
    printf("-----------------\n");
    
    // Input and calculate properties for both circles
    inputCircle(&circle1, 1);
    calculateCircleProperties(&circle1);
    
    inputCircle(&circle2, 2);
    calculateCircleProperties(&circle2);
    
    // Display results
    printf("\nCircle Properties:\n");
    printf("-----------------\n");
    displayCircle(&circle1, 1);
    displayCircle(&circle2, 2);
    
    return 0;
}

// Function to input circle radius with validation
void inputCircle(Circle *c, int circle_number) {
    do {
        printf("\nEnter radius for Circle %d: ", circle_number);
        scanf("%f", &c->radius);
        
        if(c->radius <= 0) {
            printf("Invalid radius! Radius must be greater than 0.\n");
        } else {
            break;
        }
    } while(1);
}

// Function to calculate circle properties
void calculateCircleProperties(Circle *c) {
    c->area = PI * c->radius * c->radius;
    c->perimeter = 2 * PI * c->radius;
}

// Function to display circle properties
void displayCircle(const Circle *c, int circle_number) {
    printf("\nCircle %d:\n", circle_number);
    printf("Radius: %.2f units\n", c->radius);
    printf("Area: %.2f square units\n", c->area);
    printf("Perimeter: %.2f units\n", c->perimeter);
}