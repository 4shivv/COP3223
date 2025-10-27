#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 10000

// Function to multiply matrices and perform modulo 26
void matrixMultiply(int key[][9], int n, int* block, int* result) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += key[i][j] * block[j];
        }
        result[i] %= 26; // Apply modulo 26 for Hill cipher
    }
}

// Function to clean and prepare the plaintext (lowercase letters only)
int preparePlaintext(char* rawText, char* cleanedText, int n) {
    int length = 0;
    for (int i = 0; rawText[i] != '\0'; i++) {
        if (isalpha(rawText[i])) {
            cleanedText[length++] = tolower(rawText[i]);
        }
    }
    
    // Pad with 'x' if necessary
    while (length % n != 0) {
        cleanedText[length++] = 'x';
    }
    
    cleanedText[length] = '\0'; // Null terminate the cleaned text
    return length;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <key_file> <plaintext_file>\n", argv[0]);
        return 1;
    }

    // Open key file and read the key matrix
    FILE *keyFile = fopen(argv[1], "r");
    if (!keyFile) {
        perror("Error opening key file");
        return 1;
    }
    
    int n;
    fscanf(keyFile, "%d", &n); // Read the size of the matrix

    if (n < 2 || n > 9) {
        printf("Invalid matrix size. Must be between 2 and 9.\n");
        return 1;
    }

    int keyMatrix[9][9]; // Matrix size up to 9x9
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(keyFile, "%d", &keyMatrix[i][j]);
        }
    }
    fclose(keyFile);
    
    // Open plaintext file
    FILE *plainFile = fopen(argv[2], "r");
    if (!plainFile) {
        perror("Error opening plaintext file");
        return 1;
    }

    // Read raw text from plaintext file
    char rawText[MAX_TEXT_SIZE];
    fread(rawText, sizeof(char), MAX_TEXT_SIZE, plainFile);
    fclose(plainFile);
    
    // Prepare the cleaned text (only lowercase letters)
    char cleanedText[MAX_TEXT_SIZE];
    int cleanedLength = preparePlaintext(rawText, cleanedText, n);

    // Display the key matrix
    printf("Key matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", keyMatrix[i][j]);
        }
        printf("\n");
    }

    // Display the cleaned plaintext
    printf("\nPlaintext:\n%s\n", cleanedText);

    // Encrypt the plaintext in blocks of size n
    printf("\nCiphertext:\n");
    for (int i = 0; i < cleanedLength; i += n) {
        int block[9], result[9]; // To hold plaintext block and cipher block

        // Convert letters to numbers (a = 0, b = 1, ..., z = 25)
        for (int j = 0; j < n; j++) {
            block[j] = cleanedText[i + j] - 'a';
        }

        // Perform matrix multiplication and modulo 26
        matrixMultiply(keyMatrix, n, block, result);

        // Output the ciphertext (convert numbers back to letters)
        for (int j = 0; j < n; j++) {
            printf("%c", result[j] + 'a');
        }

        // Newline after 80 characters of ciphertext
        if ((i + n) % 80 == 0) {
            printf("\n");
        }
    }

    // Newline at the end of output
    printf("\n");

    return 0;
}
