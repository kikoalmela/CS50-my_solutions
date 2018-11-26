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
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        // find smallest element from i to n - 1
        for (int j = i + 1; j < n; j++){
            if (values[j] < values[min])
            {
                min = j;
            }
        }
        // if min != i exchange smallest element with element at i
        if (min != i)
        {
            int tmp = values[i];
            values[i] = values[min];
            values[min] = tmp;
        }
    }
}
