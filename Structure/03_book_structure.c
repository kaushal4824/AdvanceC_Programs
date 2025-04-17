/*
Question 3: Create a structure named Book to store book details like title, author, and price.
Write a C program to input details for three books, find the most expensive and the lowest priced books, and display their information.

This program demonstrates:
- Structure definition for book details
- Array of structures
- Finding maximum and minimum values
- Comparing structure members
- Formatted output display
*/

#include <stdio.h>
#include <string.h>

// Define Book structure
typedef struct {
    char title[100];
    char author[50];
    float price;
} Book;

// Function prototypes
void inputBook(Book *b, int book_number);
void displayBook(const Book *b, const char *label);
void findPriceExtremes(const Book *books, int count, Book **most_expensive, Book **least_expensive);

int main() {
    Book books[3];  // Array of 3 books
    Book *most_expensive, *least_expensive;
    
    printf("\nBook Information System:\n");
    printf("----------------------\n");
    
    // Input data for three books
    for(int i = 0; i < 3; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);
        inputBook(&books[i], i + 1);
    }
    
    // Find most and least expensive books
    findPriceExtremes(books, 3, &most_expensive, &least_expensive);
    
    // Display results
    printf("\nBook Price Analysis:\n");
    printf("-----------------\n");
    displayBook(most_expensive, "Most Expensive Book");
    displayBook(least_expensive, "Least Expensive Book");
    
    return 0;
}

// Function to input book details
void inputBook(Book *b, int book_number) {
    printf("Enter Title: ");
    scanf(" %[^\n]s", b->title);
    
    printf("Enter Author: ");
    scanf(" %[^\n]s", b->author);
    
    do {
        printf("Enter Price: ");
        scanf("%f", &b->price);
        
        if(b->price <= 0) {
            printf("Invalid price! Price must be greater than 0.\n");
        } else {
            break;
        }
    } while(1);
}

// Function to display book details
void displayBook(const Book *b, const char *label) {
    printf("\n%s:\n", label);
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Price: $%.2f\n", b->price);
}

// Function to find most and least expensive books
void findPriceExtremes(const Book *books, int count, Book **most_expensive, Book **least_expensive) {
    *most_expensive = (Book*)&books[0];
    *least_expensive = (Book*)&books[0];
    
    for(int i = 1; i < count; i++) {
        if(books[i].price > (*most_expensive)->price) {
            *most_expensive = (Book*)&books[i];
        }
        if(books[i].price < (*least_expensive)->price) {
            *least_expensive = (Book*)&books[i];
        }
    }
}