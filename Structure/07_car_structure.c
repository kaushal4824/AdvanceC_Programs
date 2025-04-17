/*
Question 7: Design a structure named "Car" to store details like car ID, model, and rental rate per day.
Write a C program to input data for three cars, calculate the total rental cost for a specified number of days, and display the results.

This program demonstrates:
- Structure definition for car rental details
- Array of structures
- Cost calculation based on rental duration
- Input validation
- Formatted output display
*/

#include <stdio.h>
#include <string.h>

// Define Car structure
typedef struct {
    int car_id;
    char model[50];
    float rental_rate;
} Car;

// Function prototypes
void inputCar(Car *c, int car_number);
void displayCar(const Car *c, int car_number);
void calculateAndDisplayRental(const Car *c, int car_number, int days);

int main() {
    Car cars[3];  // Array of 3 cars
    int rental_days;
    
    printf("\nCar Rental Management System:\n");
    printf("---------------------------\n");
    
    // Input data for three cars
    for(int i = 0; i < 3; i++) {
        printf("\nEnter details for Car %d:\n", i + 1);
        inputCar(&cars[i], i + 1);
    }
    
    // Get rental duration
    do {
        printf("\nEnter number of rental days: ");
        scanf("%d", &rental_days);
        
        if(rental_days <= 0) {
            printf("Invalid number of days! Days must be greater than 0.\n");
        } else {
            break;
        }
    } while(1);
    
    // Display results
    printf("\nRental Cost Calculation:\n");
    printf("----------------------\n");
    for(int i = 0; i < 3; i++) {
        displayCar(&cars[i], i + 1);
        calculateAndDisplayRental(&cars[i], i + 1, rental_days);
        printf("\n");
    }
    
    return 0;
}

// Function to input car details
void inputCar(Car *c, int car_number) {
    printf("Enter Car ID: ");
    scanf("%d", &c->car_id);
    
    printf("Enter Car Model: ");
    scanf(" %[^\n]s", c->model);
    
    do {
        printf("Enter Rental Rate per Day: ");
        scanf("%f", &c->rental_rate);
        
        if(c->rental_rate <= 0) {
            printf("Invalid rental rate! Rate must be greater than 0.\n");
        } else {
            break;
        }
    } while(1);
}

// Function to display car details
void displayCar(const Car *c, int car_number) {
    printf("\nCar %d Details:\n", car_number);
    printf("Car ID: %d\n", c->car_id);
    printf("Model: %s\n", c->model);
    printf("Rental Rate per Day: $%.2f\n", c->rental_rate);
}

// Function to calculate and display rental cost
void calculateAndDisplayRental(const Car *c, int car_number, int days) {
    float total_cost = c->rental_rate * days;
    printf("Total Rental Cost for %d days: $%.2f\n", days, total_cost);
}