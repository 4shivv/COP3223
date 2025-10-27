//Shivaganesh Nagamandla
//Dr. Steinberg
//COP3223 Section 001
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round


int main()
{

    greeting(); //display greeting message

    //setup random generator
    int seed;
    printf("Before we start, pick a number to determine how random I will be.\n");
    scanf("%d", &seed);
    srand(seed);
    printf("All set now!\n");

    for(int x = 0; x < ROUNDS; ++x)
    {
        playRound(x + 1);
    }

    printf("********************************************************\n");
    printf("Thank you for playing!\n");
    return 0;
}

void greeting()
{

    //Display Welcome Message & Rules 
    printf("*********************************************************\n"); 
    printf("Welcome to rock paper scissor game!\n");    
    printf("Here are the rules.\n");   
    printf("You and I will get to choose rock, paper, or scissor.\n");
    printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
    printf("Rock beats Scissor!\n");
    printf("Paper beats Rock!\n");
    printf("Scissor beats Paper!\n");
    printf("If we both pick the same option, then it is a tie.\n");
    printf("Ready to play?... Here we go!\n");
    printf("*********************************************************\n");
}
void playRound(int round)
{
    printf("Welcome to a new round %d!\n", round);
    printf("Best out of three...Let's go!\n");
    int p1wins = 0;
    int p2wins = 0;

    //loop that keeps track of wins until respective player reaches 3. 
    while(p1wins != 3 && p2wins != 3)
    {
        printf("********************************************************\n");
        printf("Player 1 has won %d time(s).\n", p1wins);
        printf("Player 2 has won %d time(s).\n", p2wins);

        int p1_choice = pickOne(); //user guess
        int p2_choice = computerPick(); //computer guess
        int result = battle(p1_choice, p2_choice); //the final verdict
      
      //who won?
      if (result == 1)
      {
        p1wins++;
      }
      else if (result == -1)
      {
        p2wins++;
      }
    }

    result(p1wins, p2wins);
}
int pickOne()
{
    //printf("********************************************************\n");
    int p1choice;
    //printf("Player 1 has won 0 time(s).\n");
    //printf("Player 2 has won 0 time(s).\n");
    printf("1 - Rock\n"); 
    printf("2 - Paper\n"); 
    printf("3 - Scissor\n"); 
    printf("Make your selection: \n"); 
    scanf("%d", &p1choice);

    if (p1choice < 1 || p1choice > 3)
    {
        printf("I'm making my decision now.\n"); 
        printf("Someone made an invalid choice.\n"); 
        printf("********************************************************\n");
        return pickOne();
    }
    else
    {
        return p1choice;
    }
}
int computerPick()
{
    //computer guessing
    printf("I'm making my decision now.\n");
    return (rand() % 3) + 1;
}
int battle(int player1, int player2)
{

    //if draw
    if (player1 == player2) 
    {
        printf("Player 1 and Player 2 both used ");
        
        if (player1 == 1) 
        {
            printf("Rock!\n");
        } 
        else if (player1 == 2) 
        {
            printf("Paper!\n");
        } 
        else 
        {
            printf("Scissor!\n");
        }
        printf("Draw!\n");
        printf("********************************************************\n");
        return 0;
    } 
    //if player 1 won
    else if ((player1 == 1 && player2 == 3) || (player1 == 2 && player2 == 1) || (player1 == 3 && player2 == 2)) 
    {
        printf("Player 1 used ");
        if (player1 == 1) 
        {
            printf("Rock");
        } 
        else if (player1 == 2) 
        {
            printf("Paper");
        } 
        else
        {
            printf("Scissor");
        }
        printf(" and Player 2 used ");
        if (player2 == 1) 
        {
            printf("Rock!\n");
        } 
        else if (player2 == 2) 
        {
            printf("Paper!\n");
        } 
        else 
        {
            printf("Scissor!\n");
        }
        printf("Paper beats Rock!\n");
        printf("********************************************************\n");
        return 1;
    } 
    //if player 2 won
    else 
    {
        printf("Player 1 used ");
        if (player1 == 1) 
        {
            printf("Rock");
        } else if (player1 == 2) 
        {
            printf("Paper");
        } else 
        {
            printf("Scissor");
        }
        printf(" and Player 2 used ");
        if (player2 == 1) 
        {
            printf("Rock!\n");
        } 
        else if (player2 == 2) 
        {
            printf("Paper!\n");
        } 
        else 
        {
            printf("Scissor!\n");
        }
        printf("Rock beats Scissor!\n");
        printf("********************************************************\n");
        return -1;
    }
}

void result(int player1, int player2) 
{
    //The winner's response 
    if (player1 > player2) 
    {
        printf("You won the round! I'll let you have this one.\n");
    } 
    else 
    {
        printf("I won the round! Haha better luck next time!\n");
    }
}
