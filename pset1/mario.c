#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for the half-pyramids' height, a non-negative integer no greater than 23 and validate
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    // generate the half-pyramids
    for (int i = 0; i < height; i++)
    {
        // print spaces for left pyramid
        for (int j = 1 ; j < height - i; j++)
        {
            printf(" ");
        }
        // print hashes for left pyramid
        for (int j = 0; j <= i; j++ )
        {
            printf("#");
        }
        // print gap
        printf("  ");
        // print hashes for right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }

}