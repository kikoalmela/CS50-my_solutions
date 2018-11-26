/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

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

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Create an array to count numbers
    int tmp[65536] = {0};

    // For each number in values
    // Increment by one the value of the corresponding position (index == number) in tmp array
    for (int i = 0; i < n; i++)
    {
        tmp[values[i]]++;
    }

    int num = 0;
    // Iterate through the tmp array
    for (int i = 0; i < 65536; i++)
    {
        // If the counter of actual position is greather than 0
        if (tmp[i] > 0)
        {
            for (int j = 1; j <= tmp[i]; j++)
            {
                // Store in order each value in values
                values[num] = i;
                num++;
            }
        }
    }
    return;
}
