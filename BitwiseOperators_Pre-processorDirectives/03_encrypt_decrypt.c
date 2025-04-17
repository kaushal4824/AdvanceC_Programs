/*
Program 3: Message encryption and decryption using bitwise XOR operator
This program demonstrates:
- Simple XOR encryption/decryption
- String handling
- Input validation
- Bitwise operations for cryptography
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
void encryptDecrypt(char *message, char key);
void displayMessage(const char *message, const char *label);

int main() {
    char message[MAX_LENGTH];
    char key;
    char encrypted[MAX_LENGTH];
    
    printf("\nMessage Encryption/Decryption Program\n");
    printf("----------------------------------\n");
    
    // Get the message
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline
    
    // Get the encryption key
    printf("Enter a single character as encryption key: ");
    key = getchar();
    
    // Copy original message to encrypted array
    strcpy(encrypted, message);
    
    // Display original message
    displayMessage(message, "Original");
    
    // Encrypt the message
    encryptDecrypt(encrypted, key);
    displayMessage(encrypted, "Encrypted");
    
    // Decrypt the message (XOR with same key)
    encryptDecrypt(encrypted, key);
    displayMessage(encrypted, "Decrypted");
    
    return 0;
}

// Function to encrypt/decrypt message using XOR
void encryptDecrypt(char *message, char key) {
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] ^ key; // XOR each character with key
    }
}

// Function to display message with label
void displayMessage(const char *message, const char *label) {
    printf("\n%s message: ", label);
    for(int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}