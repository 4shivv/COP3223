//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Large Program 2

#include <stdio.h>

//Function declarations
void greeting();
void order(double *balance);
void viewAccount(double *balance);
void transaction(double *balance, double price);
void reload(double *balance);
void displayMenu();

int main() 
{
    double balance = 0.0;
    char option;

    greeting(); //Call the greeting function to welcome the user

    while (1) 
    {
        printf("****************************************************\n");
        printf("Please select one of the following options.\n");
        printf("O: Order\n");
        printf("V: View Account Summary\n");
        printf("D: Display Menu\n");
        printf("R: Reload Account\n");
        printf("E: Exit\n");
        printf("****************************************************\n");
        printf("Please select what you would like to do.\nOption Selected: ");
        scanf(" %c", &option);

        switch (option) 
        {
            case 'O':
            case 'o':
                order(&balance); //Call the order function to place an order
                break;
            case 'V':
            case 'v':
                viewAccount(&balance); //Call the viewAccount function to display the account balance
                break;
            case 'D':
            case 'd':
                displayMenu(); //Call the displayMenu function to show the available menu items
                break;
            case 'R':
            case 'r':
                reload(&balance); //Call the reload function to add funds to the account
                break;
            case 'E':
            case 'e':
                printf("****************************************************\n");
                printf("Thank you for visiting Knightro's Coffee Shop!\n");
                printf("You have $%.2f in your account.\n", balance);
                printf("Have a great day!\nGo Knights! Charge On!\n");
                return 0;
            default:
                printf("****************************************************\n");
                printf("Invalid option. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

//Function to display a welcome message
void greeting() 
{
    printf("Welcome to the Knightro's Coffee Shop!\n");
    printf("We serve delicious coffee and snacks!\n");
    printf("How can we help you today?\n");
}

// Function to place an order and deduct the price from the balance
void order(double *balance) 
{
    printf("****************************************************\n");
    printf("Here are the options!\n");
    printf("1. Hot Coffee $3.53\n");
    printf("2. Iced Coffee $4.20\n");
    printf("3. Hot Latte $3.13\n");
    printf("4. Iced Latte $4.12\n");
    printf("5. Bagel (includes cream cheese) $3.99\n");
    printf("6. Big Scone $4.99\n");
    printf("7. Frozen Coffee $5.03\n");
    printf("8. Bottle Water $1.50\n");

    int choice;
    double price;

    printf("What would you like today?\nOption Selected: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            price = 3.53;
            break;
        case 2:
            price = 4.20;
            break;
        case 3:
            price = 3.13;
            break;
        case 4:
            price = 4.12;
            break;
        case 5:
            price = 3.99;
            break;
        case 6:
            price = 4.99;
            break;
        case 7:
            price = 5.03;
            break;
        case 8:
            price = 1.50;
            break;
        default:
            printf("Invalid option. Please select a valid item.\n");
            return;
    }

    transaction(balance, price); //Call the transaction function to handle the order
}

//Function to display the account balance
void viewAccount(double *balance) 
{
    printf("****************************************************\n");
    printf("Here is your current account balance.\n");
    printf("You have $%.2f in your account.\n", *balance);
}

//Function to handle a transaction and update the balance
void transaction(double *balance, double price) 
{
    printf("****************************************************\n");
    printf("Beginning Transaction Process.\n");

    if (*balance < price) 
    {
        printf("You do not have enough in your account.\n");
        printf("Please reload your account balance.\n");
        reload(balance); //Call the reload function to add funds to the account
    } else 
    {
        printf("Your account balance before the official transaction: $%.2f\n", *balance);
        printf("Billing $%.2f to your account.\n", price);
        *balance -= price;
        printf("Transaction was successful!\nYou have now $%.2f in your account balance.\n", *balance);
    }
}

//Function to add funds to the account balance
void reload(double *balance) 
{
    double amount;
    printf("How much would you like to reload to your account?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");
    printf("Option Selected: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            amount = 1.00;
            break;
        case 2:
            amount = 5.00;
            break;
        case 3:
            amount = 10.00;
            break;
        default:
            printf("Invalid option. Please select a valid reload amount.\n");
            return;
    }

    *balance += amount; //Update the account balance with the reload amount
    printf("****************************************************\n");
    printf("$%.2f has been added to your account successfully!\n", amount);
}

//Function to display the menu items
void displayMenu() 
{
    printf("****************************************************\n");
    printf("Here are the options!\n");
    printf("1. Hot Coffee $3.53\n");
    printf("2. Iced Coffee $4.20\n");
    printf("3. Hot Latte $3.13\n");
    printf("4. Iced Latte $4.12\n");
    printf("5. Bagel (includes cream cheese) $3.99\n");
    printf("6. Big Scone $4.99\n");
    printf("7. Frozen Coffee $5.03\n");
    printf("8. Bottle Water $1.50\n");
}