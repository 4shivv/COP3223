//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 203
//Large Program 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRIKES 6
#define MAX_WORD_SIZE 20
#define WORDS_FILE "words.txt"

// Function prototypes
void maskWord(char starword[], int size);
int playRound(char starword[], char answer[]);
int occurrencesInWord(char userguess, char answer[]);
void updateStarWord(char starword[], char answer[], char userguess);
int guessTheWord(char answer[]);
void playAgain(int *play);

int main() {
    char words[100][MAX_WORD_SIZE];
    char starword[MAX_WORD_SIZE];
    char answer[MAX_WORD_SIZE];
    int play = 1;
    int wordCount = 0;
    int currentWordIndex = 0;

    // Read words from file
    FILE *file = fopen(WORDS_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s.\n", WORDS_FILE);
        return 1;
    }

    // Read words into the array
    while (fscanf(file, "%s", words[wordCount]) == 1 && wordCount < 100) {
        wordCount++;
    }
    fclose(file);

    // Main game loop
    while (play) {
        if (currentWordIndex == wordCount) {
            printf("You've played all available words. Restarting from the beginning.\n");
            currentWordIndex = 0;
        }

        // Check if the word length exceeds the maximum allowed
        if (strlen(words[currentWordIndex]) > MAX_WORD_SIZE) {
            printf("Error: Word '%s' exceeds the maximum word length of %d.\n", words[currentWordIndex], MAX_WORD_SIZE);
            return 1;
        }

        // Initialize starword with '*' characters
        maskWord(starword, strlen(words[currentWordIndex]));

        // Game introduction and rules
        printf("Welcome to the Hangman Game!\n");
        printf("************************************************************************\n");
        printf("Here are the rules.\n");
        printf("I will provide you a set of * characters for each round.\n");
        printf("Each * represents a letter in the English Alphabet.\n");
        printf("You must figure out each letter of the missing word.\n");
        printf("For every correct letter guessed, I will reveal its place in the word.\n");
        printf("Each mistake will result in a strike.\n");
        printf("%d strikes will result in a loss that round.\n", MAX_STRIKES);
        printf("Are you ready? Here we go!\n");
        printf("************************************************************************\n");

        // Start a new round
        playRound(starword, words[currentWordIndex]);

        // Move to the next word for the next round
        currentWordIndex++;
        // Ask the player if they want to play again
        playAgain(&play);
    }

    // End of the game
    printf("Thank you for playing today!\n");

    return 0;
}

// Function to initialize starword with '*' characters
void maskWord(char starword[], int size) {
    for (int i = 0; i < size; i++) {
        starword[i] = '*';
    }
    starword[size] = '\0';  // Null-terminate the string
}

// Function to handle the logic for a round of the game
int playRound(char starword[], char answer[]) {
    int strikes = 0;
    char guessedLetters[MAX_WORD_SIZE] = {0};
    int consecutiveCorrectGuesses = 0;

    // Round introduction
    printf("Welcome to the Round!\n");
    printf("The size of the word has %lu letters.\n", strlen(answer));

    while (1) {
        // Display current state of the round
        printf("You currently have %d strike(s).\n", strikes);
        printf("Letter(s) you have guessed:");

        // Display guessed letters
        for (int i = 0; i < strlen(guessedLetters); i++) {
            printf(" %c", guessedLetters[i]);
        }

        printf("\n%s\n", starword);

        // Check if the player has guessed all letters correctly
        if (consecutiveCorrectGuesses == strlen(answer)) {
            printf("Congratulations! You won! The word was %s.\n", answer);
            return 1;
        }

        char userGuess;
        printf("Enter your guess: ");
        // Validate user input
        if (scanf(" %c", &userGuess) != 1 || !isalpha(userGuess)) {
            printf("Invalid input. Please enter a valid letter.\n");
            // Clear the input buffer to prevent infinite loop
            while (getchar() != '\n');
            continue;
        }

        userGuess = tolower(userGuess);

        // Check if the user has already guessed the letter
        if (occurrencesInWord(userGuess, guessedLetters) == 0) {
            guessedLetters[strlen(guessedLetters)] = userGuess;
            int occurrences = occurrencesInWord(userGuess, answer);

            // Handle correct and incorrect guesses
            if (occurrences > 0) {
                updateStarWord(starword, answer, userGuess);
                consecutiveCorrectGuesses++;

                printf("The letter %c is in the word.\n", userGuess);
                printf("You currently have %d strike(s).\n", strikes);
                printf("Letter(s) you have guessed:");

                // Display guessed letters again
                for (int i = 0; i < strlen(guessedLetters); i++) {
                    printf(" %c", guessedLetters[i]);
                }

                printf("\n%s\n", starword);

                // Ask the player if they want to guess the whole word after 2 consecutive correct guesses
                if (consecutiveCorrectGuesses >= 2) {
                    int guessWordOption;
                    printf("You have made at least 2 consecutive correct guesses. "
                           "Would you like to guess the word (0 for no and 1 for yes): ");
                    scanf("%d", &guessWordOption);

                    if (guessWordOption == 1) {
                        if (guessTheWord(answer)) {
                            printf("Congratulations! You won! The word was %s.\n", answer);
                            return 1;
                        } else {
                            printf("Sorry. That is not the word.\n");
                            consecutiveCorrectGuesses = 0;
                        }
                    }
                }
            } else {
                strikes++;
                printf("The letter %c is NOT in the word.\n", userGuess);
                printf("You currently have %d strike(s).\n", strikes);
            }

            // Check if the player has reached the maximum number of strikes
            if (strikes == MAX_STRIKES) {
                printf("Sorry you did not win the round. The word was %s.\n", answer);
                return 0;
            }
        } else {
            printf("You already guessed the letter %c. Try again.\n", userGuess);
        }
    }
}

// Function to count occurrences of a letter in the word
int occurrencesInWord(char userguess, char answer[]) {
    int occurrences = 0;
    for (int i = 0; i < strlen(answer); i++) {
        if (answer[i] == userguess) {
            occurrences++;
        }
    }
    return occurrences;
}

// Function to update starword with correctly guessed letters
void updateStarWord(char starword[], char answer[], char userguess) {
    for (int i = 0; i < strlen(answer); i++) {
        if (answer[i] == userguess) {
            starword[i] = userguess;
        }
    }
}

// Function for the player to guess the whole word
int guessTheWord(char answer[]) {
    char userGuess[MAX_WORD_SIZE];
    printf("Enter your guess: ");
    scanf("%s", userGuess);

    // Compare the guessed word with the actual word
    return strcmp(answer, userGuess) == 0;
}

// Function to ask the player if they want to play again
void playAgain(int *play) {
    int choice;
    printf("Would you like to play another round?\n");
    printf("1: Yes\n2: No\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        *play = 1;
    } else if (choice == 2) {
        *play = 0;
    }
}
