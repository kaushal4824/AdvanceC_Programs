/*
Question 6: Define a structure named "Date" with members day, month, and year.
Write a C program to input two dates and find the difference in days between them.

This program demonstrates:
- Structure definition for date representation
- Date input validation
- Date difference calculation
- Leap year handling
*/

#include <stdio.h>
#include <stdbool.h>

// Define Date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function prototypes
void inputDate(Date *d, int date_number);
void displayDate(const Date *d, const char *label);
int calculateDaysDifference(const Date *d1, const Date *d2);
bool isValidDate(int day, int month, int year);
bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int convertToTotalDays(const Date *d);

int main() {
    Date date1, date2;
    int difference;
    
    printf("\nDate Difference Calculator:\n");
    printf("------------------------\n");
    
    // Input two dates
    inputDate(&date1, 1);
    inputDate(&date2, 2);
    
    // Calculate difference in days
    difference = calculateDaysDifference(&date1, &date2);
    
    // Display results
    printf("\nResults:\n");
    printf("--------\n");
    displayDate(&date1, "Date 1");
    displayDate(&date2, "Date 2");
    printf("\nDifference: %d days\n", difference);
    
    return 0;
}

// Function to input date with validation
void inputDate(Date *d, int date_number) {
    do {
        printf("\nEnter Date %d (day month year): ", date_number);
        scanf("%d %d %d", &d->day, &d->month, &d->year);
        
        if(!isValidDate(d->day, d->month, d->year)) {
            printf("Invalid date! Please enter a valid date.\n");
        } else {
            break;
        }
    } while(1);
}

// Function to display date
void displayDate(const Date *d, const char *label) {
    printf("%s: %02d/%02d/%04d\n", label, d->day, d->month, d->year);
}

// Function to check if a year is leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get days in a month
int getDaysInMonth(int month, int year) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Function to validate date
bool isValidDate(int day, int month, int year) {
    if(year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    
    return day <= getDaysInMonth(month, year);
}

// Function to convert date to total days since year 1
int convertToTotalDays(const Date *d) {
    int totalDays = 0;
    int i;
    
    // Add days for years
    for(i = 1; i < d->year; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    
    // Add days for months
    for(i = 1; i < d->month; i++) {
        totalDays += getDaysInMonth(i, d->year);
    }
    
    // Add days of current month
    totalDays += d->day;
    
    return totalDays;
}

// Function to calculate difference between two dates
int calculateDaysDifference(const Date *d1, const Date *d2) {
    int days1 = convertToTotalDays(d1);
    int days2 = convertToTotalDays(d2);
    
    return abs(days2 - days1);
}