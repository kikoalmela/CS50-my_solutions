#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt and validate user imput
    int minutes;
    do
    {
        printf("Minutes: ");
        minutes = get_int();
    }
    while (minutes < 0);

    // Calculate equivalent bottles
    int bottles = minutes * 12;

    // Print equivalent bottles
    printf("Bottles: %i\n", bottles);
}