//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 6

#include <stdio.h>
#include <ctype.h>

//Function prototypes
void chomp(char *str);
void clearBuff();

void lastWordLength(char *sentence);
void truncateSentence(char *sentence, int n);
int strongPasswordCheck(char *password);
int romanNumber(char *romanNumeral);

int main() 
{
    
    //Problem 1
    printf("Enter a sentence: ");
    char sentence1[500];
    fgets(sentence1, sizeof(sentence1), stdin);
    chomp(sentence1);
    lastWordLength(sentence1);

    //Problem 2
    printf("Enter a sentence: ");
    char sentence2[500];
    fgets(sentence2, sizeof(sentence2), stdin);
    chomp(sentence2);
    printf("Truncate sentence to how many words: ");
    int n;
    scanf("%d", &n);
    truncateSentence(sentence2, n);

    //Problem 3
    printf("Enter your password: ");
    char password[100];
    scanf("%s", password);
    int result = strongPasswordCheck(password);
    if (result) 
    {
        printf("The password is strong.\n");
    } else 
    {
        printf("The password is not strong.\n");
    }

    //Problem 4
    printf("Enter a roman numeral: ");
    char romanNumeral[30];
    scanf("%s", romanNumeral);
    int numericValue = romanNumber(romanNumeral);
    printf("The numerical value is: %d\n", numericValue);

    return 0;
}

//Chomp and clearBuff functions
void chomp(char *str) 
{
    while (*str != '\n' && *str != '\0') 
    {
        str++;
    }
    if (*str == '\n') 
    {
        *str = '\0';
    } else 
    {
        clearBuff();
    }
}

void clearBuff() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Problem 1
void lastWordLength(char *sentence) 
{
    int length = 0;
    int lastWordLength = 0;

    for (int i = 0; sentence[i] != '\0'; i++) 
    {
        if (isspace(sentence[i]) || ispunct(sentence[i])) 
        {
            //Check for the last word at the end of the sentence
            if (length > 0) 
            {
                lastWordLength = length;
                length = 0;
            }
        } else 
        {
            length++;
        }
    }

    printf("Length of the last word in \"%s\" is %d.\n", sentence, lastWordLength);
}

//Problem 2
void truncateSentence(char *sentence, int n) 
{
    int words = 0;

    for (int i = 0; sentence[i] != '\0'; i++) 
    {
        if (sentence[i] == ' ') 
        {
            words++;
            if (words == n) 
            {
                sentence[i] = '\0';
                break;
            }
        }
    }

    printf("Truncated sentence is \"%s\"\n", sentence);
}

//Problem 3
int strongPasswordCheck(char *password) 
{
    int length = 0;
    int lowercase = 0, uppercase = 0, digits = 0;
    char prev = '\0', prevprev = '\0';

    for (int i = 0; password[i] != '\0'; i++) 
    {
        length++;

        if (islower(password[i])) 
        {
            lowercase = 1;
        } 
        else if (isupper(password[i])) 
        {
            uppercase++;
            if (prev == password[i]) 
            {
                prevprev = prev;
                prev = password[i];
            } 
            else if (prevprev == prev && prev == password[i]) 
            {
                return 0;  //Three repeating characters in a row
            } 
            else 
            {
                prevprev = prev;
                prev = password[i];
            }
        } 
        else if (isdigit(password[i])) 
        {
            digits++;
        }
    }

    return (length >= 6 && length <= 20 && lowercase && uppercase >= 2 && digits >= 3);
}

//Problem 4
int romanNumber(char *romanNumeral) 
{
    int result = 0;
    int prevValue = 0;

    for (int i = 0; romanNumeral[i] != '\0'; i++) 
    {
        int value = 0;

        switch (romanNumeral[i]) 
        {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
            case 'X':
                value = 10;
                break;
            case 'L':
                value = 50;
                break;
            case 'C':
                value = 100;
                break;
            case 'D':
                value = 500;
                break;
            case 'M':
                value = 1000;
                break;
        }

        result += value;

        if (prevValue < value) 
        {
            result -= 2 * prevValue;
        }

        prevValue = value;
    }

    return result;
}