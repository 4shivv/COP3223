//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 3

#include <stdio.h>
#include <math.h>

//Problem 1 user-defined function 
double creditCheck (double price_of_item);

//Problem 2 user-defined function 
void universityAdmission (double grade_point_average, int admission_test_score);


//Problem 3 user-defined function 
void keyPad ();

//Problem 4 user-defined function 
double carpenter (); 

//main function 
int main()
{

//Problem 1 

    double price_of_item; 
    printf("Enter the price: ");
    scanf("%lf", &price_of_item);

    if (creditCheck(price_of_item) != 1)
    {

        printf("Not Approved!\n");

    }
    else if (creditCheck(price_of_item) == 1)
    {
                
        printf("Approved!\n");
    }

//Problem 1 ends 

//Problem 2 starts 

printf("Welcome to the University Admission System!\n");

double grade_point_average;
printf("Enter the GPA: ");
scanf("%lf", &grade_point_average);

int admission_test_score;
printf("Enter the test score: ");
scanf("%d", &admission_test_score);

universityAdmission(grade_point_average, admission_test_score);

//Problem 2 ends 

//Problem 3 starts 

keyPad(); 

//Problem 3 ends

//Problem 4 starts 

double price = carpenter();

if (price == -1.0)
{
    printf("Could not compute cost...\n");
}
else
{
    printf("Bruce will charge $%.2lf.", price); 

}

//Problem 4 ends

    return 0; 
}

//user-defined functions in use
double creditCheck (double price_of_item)
{
     if (price_of_item < 0.0)
    {
    printf("Error!\n");
    } 
    else if (price_of_item <= 9000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void universityAdmission (double grade_point_average, int admission_test_score)
{

    if (grade_point_average < 0.0 || grade_point_average > 4.0 || admission_test_score < 0) 
    {
    printf("Invalid Input!\n");
    return; 
    }

    if (grade_point_average >= 3.00 && admission_test_score >= 60)
    {
        printf("Admissions is Approved!\n");

        if (grade_point_average >= 3.50 && admission_test_score >= 70)
        {
            printf("Consider for Scholarship Award!\n");
        }
        
    }
    else if (grade_point_average > 2.00 && grade_point_average < 3.00 && admission_test_score >= 60)
    {
        printf("Admissions is Approved!\n");
    }
    else
    {
        printf("Admissions is Denied!\n");

    }
}

void keyPad ()
{

int option_selected;
printf("Welcome to the Crazy Keypad!\n");
printf("Select one of the following options for a message.\n");
printf("Option 1\n");
printf("Option 2\n");
printf("Option 3\n");
printf("Option 4\n");
printf("Option 5\n");
printf("Option Selected: ");
scanf("%d", &option_selected);

switch (option_selected)
{

case 1: 
    printf("Opening Vault 712...\n");
    break;

case 2: 
    printf("Opening Secret Elevator...\n");
    break; 

case 3: 
    printf("Calling the Boss...\n");
    break; 

case 4: 
    printf("Backup on the way...\n");
    break; 

case 5: 
    printf("Alarm activated...\n");
    break; 

default: 
    printf("System Locked...\n");

}

}

double carpenter()
{
    double base_charge = 30.00;

    printf("Welcome to Bruce's Carpentry Services!\n");

    char oak_on_sign;
    printf("Would you like the sign made out of oak?\n");
    printf("Enter y for yes or n for no: ");
    scanf(" %c", &oak_on_sign);  

     if (oak_on_sign != 'y' && oak_on_sign != 'Y' && oak_on_sign != 'n' && oak_on_sign != 'N') {
        return -1.0;
    }

    int characters_on_sign;
    printf("Enter the number of characters on the sign: ");
    scanf("%d", &characters_on_sign);

    if (characters_on_sign <= 0) {
        return -1.0;
    }

    char leaf_on_sign;
    printf("Would you like gold-leaf lettering?\n");
    printf("Enter y for yes or n for no: ");
    scanf(" %c", &leaf_on_sign);  


    if (leaf_on_sign != 'y' && leaf_on_sign != 'Y' && leaf_on_sign != 'n' && leaf_on_sign != 'N') {
        return -1.0;
    }

    if (oak_on_sign == 'y' || oak_on_sign == 'Y') {
        base_charge += 15.00;
    }

    if (characters_on_sign > 5) {
        base_charge += (characters_on_sign - 5) * 2.00;
    }

    if (leaf_on_sign == 'y' || leaf_on_sign == 'Y') {
        base_charge += 12.00;
    }

    return base_charge;
}
