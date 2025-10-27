// Shivaganesh Nagamandla
// Dr. Steinberg
// COP3223 Section 1
// Small Program 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 50

typedef struct {
    char *fname; // first name
    char *lname; // last name
    char *show;  // favorite show
} record_t;

// Function prototypes
record_t *createArray(int maxsize);
record_t *insert(record_t *myarray, int *maxsize, int *currentsize);
record_t *doubleIt(record_t *arr, int *size);
int removeRecord(record_t *arr, int size, int index);
void freeRecords(record_t *arr, int size);
void display(record_t *myarray, int currentsize);
void chomp(char word[]);

int main(void) {
    int maxsize;

    // Prompt user for the size of the dynamic array
    printf("Enter a size for the dynamic array: ");
    scanf("%d", &maxsize);

    // Create the dynamic array
    record_t *myarray = createArray(maxsize);

    int currentsize = 0;  // Initialize currentsize to 0
    int option = -1;

    // Menu for user interaction
    while (option != 0) {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Insert record option
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                // Display records option
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                // Remove record option
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removeRecord(myarray, currentsize, index);
                break;

            case 4:
                // Exit option
                printf("Exiting...\n");
                option = 0;
                break;

            default:
                // Invalid selection
                printf("Invalid Selection...\n");
        }
    }

    // Free allocated memory
    freeRecords(myarray, currentsize);
    free(myarray);
    myarray = NULL;

    return 0;
}

// Create a dynamic array of records
record_t *createArray(int maxsize) {
    record_t *arr = malloc(maxsize * sizeof(record_t));

    // Check for malloc error
    if (arr == NULL) {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }

    return arr;
}

// Insert a record into the dynamic array
record_t *insert(record_t *myarray, int *maxsize, int *currentsize) {
    // Check if the array is full and needs to be doubled
    if (*currentsize == *maxsize) {
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, maxsize);
    }

    // Prompt user for record details
    printf("Enter the first name: ");
    char fname[LIMIT];
    scanf(" %[^\n]s", fname);
    chomp(fname);

    printf("Enter the last name: ");
    char lname[LIMIT];
    scanf(" %[^\n]s", lname);
    chomp(lname);

    printf("Enter favorite show: ");
    char show[LIMIT];
    scanf(" %[^\n]s", show);
    chomp(show);

    // Assign values to the new record
    myarray[*currentsize].fname = strdup(fname);
    myarray[*currentsize].lname = strdup(lname);
    myarray[*currentsize].show = strdup(show);

    (*currentsize)++;

    return myarray;
}

// Double the size of the dynamic array
record_t *doubleIt(record_t *arr, int *size) {
    // Create a new dynamic array with double the size
    record_t *newArr = createArray((*size) * 2);

    // Copy content from the initial dynamic array
    for (int i = 0; i < *size; i++) {
        newArr[i] = arr[i];
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }

    // Free memory of the initial array
    free(arr);

    return newArr;
}

// Remove a record from the dynamic array
int removeRecord(record_t *arr, int size, int index) {
    // Check for invalid index
    if (index < 0 || index >= size) {
        printf("Invalid Index\n");
        return size;
    }

    // Free memory of the record to be removed
    free(arr[index].fname);
    free(arr[index].lname);
    free(arr[index].show);

    // Shift elements to remove the specified record
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Free memory allocated for records
void freeRecords(record_t *arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }
}

// Display records in the dynamic array
void display(record_t *myarray, int currentsize) {
    printf("---------------------------------\n");

    for (int x = 0; x < currentsize; ++x) {
        printf("myarray[%d].fname = %s\n", x, myarray[x].fname);
        printf("myarray[%d].lname = %s\n", x, myarray[x].lname);
        printf("myarray[%d].show = %s\n", x, myarray[x].show);
    }

    printf("---------------------------------\n");
}

// Remove trailing newline character from a string
void chomp(char word[]) {
    if (word[strlen(word) - 1] == '\n') {
        word[strlen(word) - 1] = '\0';
    }
}
