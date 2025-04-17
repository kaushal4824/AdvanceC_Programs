/*
Question 14: Write a program in C to check whether a record is in the file or not.
(Assume a file named item.dat having 5 records of type item. Item has three members itemcode, name, price)

This program demonstrates:
- Structure definition for item records
- Binary file operations with structures
- Record searching in binary files
- File positioning and reading
- Error handling for file operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define item structure
typedef struct {
    int itemcode;
    char name[50];
    float price;
} Item;

// Function prototypes
void inputItem(Item *item);
void displayItem(const Item *item);
void createSampleRecords(const char *filename);
bool searchItem(const char *filename, int searchCode);

int main() {
    const char *filename = "item.dat";
    int searchCode;
    
    printf("\nItem Record Search Program:\n");
    printf("------------------------\n");
    
    // Create sample records first
    createSampleRecords(filename);
    
    // Get item code to search
    printf("\nEnter item code to search: ");
    scanf("%d", &searchCode);
    
    // Search for the item
    if(searchItem(filename, searchCode)) {
        printf("\nItem with code %d found in the file!\n", searchCode);
    } else {
        printf("\nItem with code %d not found in the file.\n", searchCode);
    }
    
    return 0;
}

// Function to input item details
void inputItem(Item *item) {
    printf("Enter Item Code: ");
    scanf("%d", &item->itemcode);
    
    printf("Enter Item Name: ");
    scanf(" %[^\n]s", item->name);
    
    printf("Enter Item Price: ");
    scanf("%f", &item->price);
}

// Function to display item details
void displayItem(const Item *item) {
    printf("Item Code: %d, Name: %s, Price: %.2f\n",
           item->itemcode, item->name, item->price);
}

// Function to create sample records
void createSampleRecords(const char *filename) {
    FILE *file = fopen(filename, "wb");
    Item items[5] = {
        {101, "Laptop", 999.99},
        {102, "Mouse", 29.99},
        {103, "Keyboard", 49.99},
        {104, "Monitor", 299.99},
        {105, "Printer", 199.99}
    };
    
    if(file == NULL) {
        printf("Error creating sample records!\n");
        return;
    }
    
    // Write sample records
    fwrite(items, sizeof(Item), 5, file);
    fclose(file);
    
    printf("Sample records created successfully!\n");
    printf("\nAvailable items:\n");
    for(int i = 0; i < 5; i++) {
        displayItem(&items[i]);
    }
}

// Function to search for an item by item code
bool searchItem(const char *filename, int searchCode) {
    FILE *file = fopen(filename, "rb");
    Item item;
    bool found = false;
    
    if(file == NULL) {
        printf("Error opening file for searching!\n");
        return false;
    }
    
    // Read records one by one and check item code
    while(fread(&item, sizeof(Item), 1, file) == 1) {
        if(item.itemcode == searchCode) {
            printf("\nFound item details:\n");
            displayItem(&item);
            found = true;
            break;
        }
    }
    
    fclose(file);
    return found;
}