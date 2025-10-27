//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 5

#include <stdio.h>

// Function prototypes
void pickButton(int *selected);
void match();
void blockbuster();
void numberFacts();

int main() {
    int selectedButton;

    // Call the pickButton function to choose a button
    pickButton(&selectedButton);

    // Call the match function
    match();

    // Call the blockbuster function to process sales records
    blockbuster();

    // Call the numberFacts function to determine number facts
    numberFacts();

    return 0;
}

// Function to select a button
void pickButton(int *selected) {
    printf("Choose a button.\n");
    // Display button options
    printf("1. Blue Button\n");
    printf("2. Green Button\n");
    printf("3. Yellow Button\n");
    printf("4. Red Button\n");
    printf("5. Gold Button\n");
    printf("6. Black Button\n");
    printf("7. White Button\n");
    printf("Selection: ");

    int choice;
    scanf("%d", &choice);

    // Determine the selected button and provide feedback
    switch (choice) {
        case 1:
            *selected = 1;
            printf("Blue Button Selected!\n");
            break;
        case 2:
            *selected = 2;
            printf("Green Button Selected!\n");
            break;
        case 3:
            *selected = 3;
            printf("Yellow Button Selected!\n");
            break;
        case 4:
            *selected = 4;
            printf("Red Button Selected!\n");
            break;
        case 5:
            *selected = 5;
            printf("Gold Button Selected!\n");
            break;
        case 6:
            *selected = 6;
            printf("Black Button Selected!\n");
            break;
        case 7:
            *selected = 7;
            printf("White Button Selected!\n");
            break;
        default:
            *selected = 0;
            printf("Invalid Button Selected!\n");
    }
}

// Function to match data in three files
void match() {
    // Attempt to open three files
    FILE *file1 = fopen("grades1.txt", "r");
    FILE *file2 = fopen("grades2.txt", "r");
    FILE *file3 = fopen("grades3.txt", "r");

    // Check if any file could not be opened
    if (file1 == NULL || file2 == NULL || file3 == NULL) {
        printf("No Match!\n");
        return;
    }

    int ch1, ch2, ch3;
    int isMatch = 1;

    while (1) {
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);
        ch3 = fgetc(file3);

        if (ch1 != ch2 || ch1 != ch3 || ch2 != ch3) {
            isMatch = 0;
            break;
        }

        if (ch1 == EOF) {
            break;
        }
    }

    // Close the files
    fclose(file1);
    fclose(file2);
    fclose(file3);

    // Display the result of the match
    if (isMatch) {
        printf("Match!\n");
    } else {
        printf("No Match!\n");
    }
}

// Function to process sales records
void blockbuster() {
    // Attempt to open input and output files
    FILE *salesFile = fopen("sales.txt", "r");
    FILE *recordsale = fopen("recordsales.txt", "w");

    // Check if either file could not be opened
    if (salesFile == NULL || recordsale == NULL) {
        printf("Failed to open files.\n");
        return;
    }

    double totalSales = 0.0;
    int customer, videos;

    printf("Retrieving the Records from today's sale!\n");

    while (fscanf(salesFile, "%d %d", &customer, &videos) == 2) {
        double cost = videos * 2.99;
        totalSales += cost;

        printf("Customer: %d\tSpent: $%.2lf\n", customer, cost);
        fprintf(recordsale, "Customer: %d\tSpent: $%.2lf\n", customer, cost);
    }

    printf("-----------------------------\n");
    fprintf(recordsale, "-----------------------------\n");

    printf("$%.2lf was made today.\n", totalSales);
    fprintf(recordsale, "$%.2lf was made today.\n", totalSales);

    // Close the files
    fclose(salesFile);
    fclose(recordsale);
}

// Function to determine number facts
void numberFacts() {
    // Attempt to open a file for writing
    FILE *fptr = fopen("numfact.txt", "w");

    // Check if the file could not be opened
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (1) {
        printf("Enter a positive integer: ");
        int num;
        scanf("%d", &num);

        if (num <= 0) {
            break;
        }

        fprintf(fptr, "Number\tPart A\tPart B\tPart C\n");
        fprintf(fptr, "%d\t", num);

        // Part A: Check if the number is a multiple of 7, 11, or 13
        if (num % 7 == 0 || num % 11 == 0 || num % 13 == 0) {
            printf("%d\tYes!\t", num);
            fprintf(fptr, "Yes!\t");
        } else {
            printf("%d\tNo!\t", num);
            fprintf(fptr, "No!\t");
        }

        // Part B: Check if the number is even or odd
        if (num % 2 == 0) {
            printf("Even\t");
            fprintf(fptr, "Even\t");
        } else {
            printf("Odd\t");
            fprintf(fptr, "Odd\t");
        }

        // Part C: Check if the number is prime or composite
        int isPrime = 1;
        if (num <= 1) {
            isPrime = 0;
        } else if (num <= 3) {
            isPrime = 1;
        } else if (num % 2 == 0 || num % 3 == 0) {
            isPrime = 0;
        } else {
            for (int i = 5; i * i <= num; i += 6) {
                if (num % i == 0 || num % (i + 2) == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime) {
            printf("Prime\n");
            fprintf(fptr, "Prime\n");
        } else {
            printf("Composite\n");
            fprintf(fptr, "Composite\n");
        }
    }

    // Close the file
    fclose(fptr);
}