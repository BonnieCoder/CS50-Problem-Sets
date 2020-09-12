#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    int cents = round(dollars * 100); //converts dollars to cents and rounds it
    int coins = 0;
    for (int i = 0; i < 4; i++) //Greedy Algorithms
    {
        if (cents >= 25)
        {
            coins = coins + (cents / 25); //number of coins
            cents = cents % 25; //amount of remaining cents
        }
        else if (cents >= 10)
        {
            coins = coins + (cents / 10); //number of coins
            cents = cents % 10; //amount of remaining cents
        }
        else if (cents >= 5)
        {
            coins = coins + (cents / 5); //number of coins
            cents = cents % 5; //amount of remaining cents
        }
        else
        {
            coins = coins + (cents / 1); //number of coins
            cents = cents % 1; //amount of remaining cents
        }
    }
    printf("Minimum number of coins: %i\n", coins);
