#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

void cash(void);

int get_cents (void){
    int cents;
    
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1 || cents > 99);
    
    return cents;
}

int calculate_quarters (int cents){
     return (cents/25);
}

int calculate_dimes (int cents){
     return (cents%25/10);
}

int calculate_nickels (int cents){
     return (cents%25%10/5);
}

int calculate_pennies (int cents){
     return (cents%25%10%5);
}

int main(void)
{
    int cash = get_cents();
    printf("%d\n",calculate_quarters(cash)+calculate_dimes(cash)+calculate_nickels(cash)+calculate_pennies(cash));
    
}
