#include <stdio.h>

//function prototypes
void countEvenOdd();
void drawShape();
void toyPhone();
void costPreview(int years, int rate);

//main function
int main() 
{
    countEvenOdd();
    drawShape();
    toyPhone();

    //for costPreview function
    int years;
    int percentage;

    while (1) 
    {
        printf("Enter the number of years to observe: ");
        scanf("%d", &years);

        printf("Enter the percentage rate to increase by per year: ");
        scanf("%d", &percentage);

        if (years > 0 && percentage > 0) 
        {
            costPreview(years, percentage);
            break;
        } else 
        {
            printf("Invalid input.\n");
        }
    }

    return 0;
}

//function definition for countEvenOdd
void countEvenOdd() 
{
    int evenCount = 0;
    int oddCount = 0;
    int evenSum = 0;
    int oddSum = 0;

    while (1) 
    {
        int num;
        printf("Enter a positive integer: ");
        scanf("%d", &num);

        if (num < 0) 
        {
            printf("That's a negative number!\n");
            continue; //continue the loop if a negative number is entered
        } else if (num == 0) 
        {
            break; //terminate the loop when 0 is entered
        }

        if (num % 2 == 0) 
        {
            evenCount++;
            evenSum += num;
        } else 
        {
            oddCount++;
            oddSum += num;
        }
    }

    if (evenCount > 0) 
    {
        printf("%d even integers entered and the average is %lf\n", evenCount, (double) evenSum / evenCount);
    }

    if (oddCount > 0) 
    {
        printf("%d odd integers entered and the average is %lf\n", oddCount, (double) oddSum / oddCount);
    }
}


//function definition for drawShape
void drawShape() 
{
    int numRows;

    while (1) 
    {
        printf("How many rows would you like the shape to have?: ");
        scanf("%d", &numRows);

        if (numRows <= 0) 
        {
            printf("Invalid Input. Please try again.\n");
        } else 
        {
            break; //break the loop when a valid input is provided
        }
    }

    for (int i = 1; i <= numRows; i++) 
    {
        for (int j = 1; j <= numRows; j++) 
        {
            if (i == 1 || i == numRows || j == 1 || j == numRows || j == i) 
            {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


//function definition for toyPhone
void toyPhone() 
{
    int button;

    printf("Welcome to the Toy Phone!\n");

    while (1) {
        printf("Enter a button: ");
        scanf("%d", &button);

        switch (button) 
        {
            case 1:
                printf("Hello!\n");
                break;
            case 2:
                printf("Loopy Loops!\n");
                break;
            case 3:
                printf("Programming is fun!\n");
                break;
            case 4:
                printf("Semicolons can be a pain to forget!\n");
                break;
            case 5:
                printf("Are you ready for pointers?\n");
                break;
            case 6:
                printf("Goodbye!\n");
                return; //exit the function when the user selects 6
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

//function definition for costPreview
void costPreview(int years, int percentage) 
{
    double tuition = 20000.0; // Initial tuition

    //input validation for the number of years and percentage increase
    if (years <= 0 || percentage <= 0) 
    {
        printf("Invalid input.\n");
        return;
    }

    printf("Current Tuition: $%.2lf\n", tuition);

    for (int year = 1; year <= years; year++) 
    {
        tuition *= (1 + percentage / 100.0); //calculate tuition for the next year
        printf("Year %d Tuition: $%.2lf\n", year, tuition);
    }
}
