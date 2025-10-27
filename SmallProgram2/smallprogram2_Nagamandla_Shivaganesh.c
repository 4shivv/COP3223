//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 1

#include <stdio.h>
#include <math.h>

//problem 1 user-defined function
double calcHypotenuse (double side_a, double side_b);

//problem 2 user-defined function
void rentalPrices();

//problem 3 user-defined function
void timeDisplay (int seconds);

//problem 4 user-defined function
double mathFunction (int n);

int main()
{ 

    //problem 1 starts 
    double side_a;
    printf("Enter the value for a: ");
    scanf("%lf", &side_a);

    double side_b;
    printf("Enter the value for b: ");
    scanf("%lf", &side_b);

    double hypotenuse = calcHypotenuse(side_a, side_b);

    printf ("If a = %.3lf and b = %.3lf, then that means the hypotenuse is %.3lf.\n", side_a, side_b, hypotenuse);
    //problem 1 ends 

    //problem 2 starts 
    rentalPrices();
    //problem 2 ends

    //problem 3 starts 
    int seconds; 
    printf("Enter the seconds: ");
    scanf("%d", &seconds);

    timeDisplay(seconds);
    //problem 3 ends 

    //problem 4 starts 
    
    int n;
    printf("Enter the value for n: ");
    scanf("%d", &n);

    double function_result = mathFunction(n);

    printf("The function computes the value %.3lf.", function_result);
    //problem 4 ends 

    return 0;
}

//user-defined functions in use 
double calcHypotenuse (double side_a, double side_b)
{

    double hypotenuse_part_1 = (pow(side_a, 2)) + (pow(side_b, 2));
    double result = sqrt(hypotenuse_part_1);

    return result; 
}

void rentalPrices()
{

    printf("Hello Luis!\n");
    printf("Thank you for considering Hertz for your car rental needs.\n");
    printf("You have asked to compare prices for three vehicles.\n");
    
    int number_of_days;
    printf("Please enter the number of days you plan to rent the vehicle: ");
    scanf("%d", &number_of_days);

    double tesla_model_3 = (46.48) * (number_of_days);
    double chevrolet_malibu = (49.53) * (number_of_days) ;
    double nissan_rogue = (50.72) * (number_of_days); 

    printf("Here are the prices excluding tax.\n");

    printf("Tesla Model 3 Standard Range: $%.2lf\n", tesla_model_3);
    printf("Chevrolet Malibu: $%.2lf\n", chevrolet_malibu);
    printf("Nissan Rogue: $%.2lf\n", nissan_rogue);
}

void timeDisplay(int seconds)
{
    int hours = (seconds) / (3600);
    int minutes = ((seconds) %  (3600)) / 60;
    int seconds_left = ((seconds) %  (3600)) % 60;

  printf("%d seconds is %d hours, %d minutes, and %d seconds.\n", seconds, hours, minutes, seconds_left);

}

double mathFunction (int n)
{

    double power_n = n - 2.0;  

    double function_part_1 = (pow(n, n)) - (pow(2.0, n));
    
    double function_part_2 = ((sqrt(n)) * (pow(n, 4.0))) / ((exp(power_n)) + (9.0));

    double function_result = (function_part_1) / (function_part_2) - ((8.0) * (n));

    return function_result;

}
