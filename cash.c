#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    do
    {
        change = get_float("How much change is owed?\n");
    }
    while (change < .01); //run loop until positive number is input

    int cents = round(change * 100); //convert all change into cents
    int coins = 0; //tracker for number of coins to return
    int currentChange = cents;

    while (currentChange >= 25) //quarters
    {
        currentChange = currentChange - 25;
        coins++;
    }

    while (currentChange >= 10) //dimes
    {
        currentChange = currentChange - 10;
        coins++;
    }

    while (currentChange >= 5) //nickels
    {
        currentChange = currentChange - 5;
        coins++;
    }

    while (currentChange >= 1) //pennies
    {
        currentChange = currentChange - 1;
        coins++;
    }

    printf("%i\n", coins);
}