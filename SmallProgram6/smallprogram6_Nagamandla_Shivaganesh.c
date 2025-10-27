//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 6

#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void salesInfo(int salespeople[], int counts[]);
void testScoreInfo(double scores[], int numValues);
int removeDuplicates(int arr[]);
void mergeValues(int arr1[], int arr2[], int arr3[]);

int main() 
{
    // Problem 1: Sales Info
    int salespeople[250];
    int counts[9] = {0};

    int grossSale;
    int salespeopleCount = 0;

    while (1) 
    {
        printf("Enter gross sale: ");
        scanf("%d", &grossSale);
        if (grossSale < 0) {
            break;
        }
        salespeople[salespeopleCount] = grossSale;
        salespeopleCount++;
    }
    salesInfo(salespeople, counts);

    // Display counts
    for (int i = 0; i < 9; i++) 
    {
        printf("$%d-%d: %d\n", 200 + i * 100, 299 + i * 100, counts[i]);
    }

    // Problem 2: Test Score Info
    double quizScores[250];
    int scoreCount = 0;

    printf("\nProblem 2 - Test Score Info\n");
    printf("Enter quiz scores (negative value to exit):\n");
    while (1) 
    {
        double score;
        printf("Enter a score: ");
        scanf("%lf", &score);
        if (score < 0) {
            break;
        }
        quizScores[scoreCount] = score;
        scoreCount++;
    }
    testScoreInfo(quizScores, scoreCount);

    // Problem 3: Remove Duplicates
    int integerArray[15];

    printf("\nProblem 3 - Remove Duplicates\n");
    printf("Enter 15 integers:\n");
    for (int i = 0; i < 15; i++) 
    {
        printf("Enter an integer: ");
        scanf("%d", &integerArray[i]);
    }

    printf("Array before removing duplicates:\n");
    for (int i = 0; i < 15; i++) 
    {
        printf("%d ", integerArray[i]);
    }
    printf("\n");

    int uniqueCount = removeDuplicates(integerArray);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < uniqueCount; i++) 
    {
        printf("%d ", integerArray[i]);
    }
    printf("\n");

    // Problem 4: Merge Values
    int arr1[5], arr2[5], arr3[5];

    printf("\nProblem 4 - Merge Values\n");
    for (int x = 0; x < 5; x++) 
    {
        printf("Enter an integer for array1: ");
        scanf("%d", &arr1[x]);
    }
    for (int x = 0; x < 5; x++) 
    {
        printf("Enter an integer for array2: ");
        scanf("%d", &arr2[x]);
    }
    mergeValues(arr1, arr2, arr3);

    // Display merged values
    for (int x = 0; x < 5; x++) 
    {
        printf("arr1[%d] = %d\t", x, arr1[x]);
        printf("arr2[%d] = %d\t", x, arr2[x]);
        printf("arr3[%d] = %d\n", x, arr3[x]);
    }

    return 0;
}

// Problem 1: Sales Info
void salesInfo(int salespeople[], int counts[]) 
{
    for (int i = 0; i < 250; i++) 
    {
        if (salespeople[i] < 200) {
            counts[0]++;
        } else if (salespeople[i] >= 200 && salespeople[i] < 300) 
        {
            counts[1]++;
        } else if (salespeople[i] >= 300 && salespeople[i] < 400) 
        {
            counts[2]++;
        } else if (salespeople[i] >= 400 && salespeople[i] < 500) 
        {
            counts[3]++;
        } else if (salespeople[i] >= 500 && salespeople[i] < 600) 
        {
            counts[4]++;
        } else if (salespeople[i] >= 600 && salespeople[i] < 700) 
        {
            counts[5]++;
        } else if (salespeople[i] >= 700 && salespeople[i] < 800) 
        {
            counts[6]++;
        } else if (salespeople[i] >= 800 && salespeople[i] < 900) 
        {
            counts[7]++;
        } else {
            counts[8]++;
        }
    }
}

// Problem 2: Test Score Info
void testScoreInfo(double scores[], int numValues)
{
    if (numValues == 0) 
    {
        printf("No scores entered.\n");
        return;
    }

    double minScore = scores[0];
    double maxScore = scores[0];
    double total = scores[0];

    for (int i = 1; i < numValues; i++) 
    {
        if (scores[i] < minScore) {
            minScore = scores[i];
        }
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
        total += scores[i];
    }

    double average = total / numValues;
    printf("Lowest score: %.2lf\n", minScore);
    printf("Highest score: %.2lf\n", maxScore);
    printf("Average score: %.2lf\n", average);
}

// Problem 3: Remove Duplicates
int removeDuplicates(int arr[]) 
{
    int uniqueCount = 0;
    bool isDuplicate;

    for (int i = 0; i < 15; i++) 
    {
        isDuplicate = false;

        for (int j = 0; j < i; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    // Sort the unique values in ascending order
    for (int i = 0; i < uniqueCount - 1; i++) 
    {
        for (int j = 0; j < uniqueCount - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return uniqueCount;
}

// Problem 4: Merge Values
void mergeValues(int arr1[], int arr2[], int arr3[]) 
{
    for (int i = 0; i < 5; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}