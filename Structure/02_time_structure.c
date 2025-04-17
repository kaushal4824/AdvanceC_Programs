/*
Question 2: Define a structure named Time with members hours, minutes, and seconds.
Write a C program to input two times, add them, and display the result in proper time format.

This program demonstrates:
- Structure definition for time representation
- Time input validation
- Time addition with carry over
- Proper time format display
*/

#include <stdio.h>

// Define Time structure
typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Function prototypes
void inputTime(Time *t, int time_number);
void addTimes(const Time *t1, const Time *t2, Time *result);
void displayTime(const Time *t, const char *label);
void normalizeTime(Time *t);

int main() {
    Time time1, time2, sum;
    
    printf("\nTime Addition Program:\n");
    printf("-------------------\n");
    
    // Input two times
    inputTime(&time1, 1);
    inputTime(&time2, 2);
    
    // Add times and normalize result
    addTimes(&time1, &time2, &sum);
    
    // Display results
    printf("\nResults:\n");
    printf("--------\n");
    displayTime(&time1, "Time 1");
    displayTime(&time2, "Time 2");
    displayTime(&sum, "Sum");
    
    return 0;
}

// Function to input time with validation
void inputTime(Time *t, int time_number) {
    do {
        printf("\nEnter Time %d (hours minutes seconds): ", time_number);
        scanf("%d %d %d", &t->hours, &t->minutes, &t->seconds);
        
        if(t->hours < 0 || t->minutes < 0 || t->seconds < 0 ||
           t->minutes >= 60 || t->seconds >= 60) {
            printf("Invalid time! Please enter valid values.\n");
            printf("Hours >= 0, 0 <= Minutes < 60, 0 <= Seconds < 60\n");
        } else {
            break;
        }
    } while(1);
}

// Function to add two times
void addTimes(const Time *t1, const Time *t2, Time *result) {
    // Add individual components
    result->seconds = t1->seconds + t2->seconds;
    result->minutes = t1->minutes + t2->minutes;
    result->hours = t1->hours + t2->hours;
    
    // Normalize the result
    normalizeTime(result);
}

// Function to normalize time (handle carry over)
void normalizeTime(Time *t) {
    // Handle seconds overflow
    if(t->seconds >= 60) {
        t->minutes += t->seconds / 60;
        t->seconds %= 60;
    }
    
    // Handle minutes overflow
    if(t->minutes >= 60) {
        t->hours += t->minutes / 60;
        t->minutes %= 60;
    }
}

// Function to display time in proper format
void displayTime(const Time *t, const char *label) {
    printf("%s: %02d:%02d:%02d\n", label, t->hours, t->minutes, t->seconds);
}