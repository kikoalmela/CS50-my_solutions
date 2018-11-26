#include <cs50.h>
#include <stdio.h>

#define SIZE 9

bool search(int value, int values[], int n)
{
    // Index of first element in the range to search
    int l = 0;
    // Index of last element in the range to search
    int r = n - 1;

    while (l <= r)
    {
        // Index of the element in the middle of the range
        int m = (r + l) / 2;
        // Return true if value is found in the middle of the range
        if (values[m] == value)
        {
            return true;
        }
        // If it's higher than value, set r for a new range: only the elements to the left side of m
        else if (values[m] > value)
        {
            r = m - 1;
        }
        // If it's is lower than value, set l for a new range: only the elements to the right side of m
        else if (values[m] < value)
        {
            l = m +1;
        }
    }
    // If value is not in values, return false
    return false;
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108, 133 };
    printf("> ");
    int n = get_int();
    if (search(n, numbers, SIZE))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
