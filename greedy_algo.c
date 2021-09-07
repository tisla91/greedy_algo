#include <stdio.h>
#include <cs50.h>
#include <math.h>
// Greedy Algorithm: Determines minimum number of coins found in a currency amount

float change_amt(void);      // Declares change_amt function

int main(void)
{

    int cents_change = round(change_amt() * 100);     // round function converts float from user into a whole number-int.
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    int min_coin = 0;
    int coins_count = 0;
    while (cents_change > 0)
    // Algorithm divides by the highest currency(coin) at every iteration and updates cent_change input variable until cent_change is zero.
    {
        if (cents_change > quarters || cents_change == quarters)
        {
            coins_count = cents_change / quarters;
            cents_change = cents_change % quarters;
        }
        else if (cents_change > dimes || cents_change == dimes)
        {
            coins_count = cents_change / dimes;
            cents_change = cents_change % dimes;
        }
        else if (cents_change > nickels || cents_change == nickels)
        {
            coins_count = cents_change / nickels;
            cents_change = cents_change % nickels;
        }
        else // if (cents_change > pennies || cents_change == pennies)
        {
            coins_count = cents_change / pennies;
            cents_change = cents_change % pennies;
        }

        min_coin = min_coin + coins_count;     // Updates coins count at each iteration to get the final nimber of minimum coins at the end.
    }

    printf("%i\n", min_coin);
}



float change_amt(void)
// Function prompts user for a positive number
{
    float n;
    do
    {
        n = get_float("How much is your change? \n");
    }
    while (n < 0);
    return n;
}
