#include <stdio.h>
#include <string.h>

// Function to add the suffix to the cat's name based on the rules
void adoptCat(char cat[], int week, int family) {
    char suffix[4];  // To store the family-specific suffix

    // Assign the suffix based on the family
    switch (family) {
        case 1:
            strcpy(suffix, "Lee");
            break;
        case 2:
            strcpy(suffix, "Lyn");
            break;
        case 3:
            strcpy(suffix, "Eve");
            break;
    }

    // Add the suffix to the cat's name
    strcat(cat, suffix);

    // Move the cat to the appropriate position based on the rules
    int move = 0;
    switch (family) {
        case 1:
            move = 2;
            break;
        case 2:
            move = 3;
            break;
        case 3:
            move = 5;
            break;
    }

    // Update the position considering circular arrangement
    int len = strlen(cat);
    int newPos = (week * move) % len;

    // Shift the characters to the left to get the new arrangement
    for (int i = 0; i < len; i++) {
        cat[i] = cat[(newPos + i) % len];
    }

    // Null-terminate the string at the new position
    cat[len] = '\0';
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Array to store the original names of cats
    char cats[N][20];

    // Input the original names of cats
    for (int i = 0; i < N; i++) {
        scanf("%s", cats[i]);
    }

    // Process each week
    for (int week = 1; week <= K; week++) {
        // Process each family
        for (int family = 1; family <= 3; family++) {

            // Calculate the index of the cat based on the rules
            int catIndex = (week - 1) * 3 + family - 1;

            // Check if the cat is within the array bounds
            if (catIndex < N) {

                // Adopt the cat and print the name
                adoptCat(cats[catIndex], week, family);
                printf("%s", cats[catIndex]);
            } else {
                
                // No cat found for this family and week
                printf("No cat found");
            }

            // Print a space between cat names
            if (family < 3) {
                printf(" ");
            }
        }

        // Move to the next line after processing each week
        printf("\n");
    }

    return 0;
}
