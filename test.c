#include <stdio.h>

int main() {
    // Declare an array of integers with size 5
    int myArray[5];

    // Use a loop to store values in the array
    for (int i = 0; i < 5; i++) {
        printf("Enter value for index %d: ", i);
        scanf("%d", &myArray[i]);
    }

    // Display the stored values
    printf("Values stored in the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}


