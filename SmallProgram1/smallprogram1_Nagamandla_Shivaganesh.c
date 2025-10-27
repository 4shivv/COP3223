//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Small Program 1

#include <stdio.h>
#include <math.h>

int main() {

//problem 1 begins


    printf("--          --\n");
    printf("--          --\n");
    printf("--          --\n");
    printf("--          --\n");
    printf("--------------\n");
    printf("--------------\n");
    printf("--          --\n");
    printf("--          --\n");
    printf("--          --\n");
    printf("--          --\n");

//problem 1 ends 

//problem 2 begins...

	
    //get inputs 
	printf("Enter the amount of eggs laid for each of the 5 chickens.\n");
	
    int chicken1;
	printf("Chicken 1: ");
    scanf("%d", &chicken1);
	
    int chicken2;
	printf("Chicken 2: ");
    scanf("%d", &chicken2);
	
    int chicken3;
	printf("Chicken 3: ");
    scanf("%d", &chicken3);

    int chicken4;
	printf("Chicken 4: ");
    scanf("%d", &chicken4);

    int chicken5;
	printf("Chicken 5: ");
    scanf("%d", &chicken5);

    //add up values of all eggs 
    int total_eggs = chicken1 + chicken2 + chicken3 + chicken4 + chicken5;
    
    //get amount of eggs in dozen 
    int total_eggs_dozen = (total_eggs) / (12);

    //get remainder of eggs 
    int total_eggs_remainder = (total_eggs) % (12);


    //print eggs in dozen and remainder 
    printf ("There are %d dozen(s) and %d egg(s) total.\n", total_eggs_dozen, total_eggs_remainder);

//problem 2 ends


//problem 3 begins...


	printf("Let's calculate simple interest for an amount based on a duration of 5 years\nwith a rate of interest equal to 12.5%%.\n");
	
    double principal; 
	printf("Enter the amount: ");
	scanf("%lf", &principal);
	
    double simpleinterest = (principal * 12.5 * 5) / 100;

    printf("The interest for a principal amount of $%.2lf is $%.2lf.\n", principal, simpleinterest);

    double totalbalance = principal + simpleinterest;
    printf("The total balance will be $%.2lf.\n", totalbalance);

//problem 3 ends...

//problem 4 begins...
    

    //declare constants 

    const double pi = 3.141592;

	//get input values
	printf("Let's calculate the area of the 2D car drawing.\n");
	
	printf("Let's start with the 4 circles.\n");
	
    int circleradius;
	printf("Enter the radius: ");
	scanf("%d", &circleradius);

	printf("Now lets get the info on the parallelogram.\n");
	
    int parallelogram_base;
	printf("Enter the base: ");
	scanf("%d", &parallelogram_base);

    int parallelogram_height;
	printf("Enter the height: ");
	scanf("%d", &parallelogram_height);

	printf("Last, lets enter the information on the triangle.\n");
	
    int triangle_base;
	printf("Enter the base: ");
	scanf("%d", &triangle_base);

    int triangle_height;
	printf("Enter the height: ");
	scanf("%d", &triangle_height);

    //calculate areas of respective shapes
    double area_four_circles = 4.0 * (pi * pow(circleradius, 2.0));

    double area_parallelogram = parallelogram_base * parallelogram_height;

    double area_triangle = (triangle_base * triangle_height) / 2.0;

    double area_car = area_four_circles + area_parallelogram + area_triangle; 

    printf("The area of the 2D car is %.5lf units.", area_car);

    //problem 4 ends...

return 0;


}