#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    // Prompt user for his name and asign the string to a variable
    string name = get_string();

    // Print the user's initials
    for (int i = 0, length = strlen(name); i < length; i++)
    {
        // Look for the first char which is not a space and print it in uppercase
        if (!isspace(name[i]))
        {
            printf ("%c", toupper(name[i]));

            // Look for others chars after a space and print them in uppercase
            for (int j = i + 1, rem = strlen(name) - i; j < rem; j++)
            {
                if (isspace(name[j]) && !isspace(name[j + 1]))
                {
                    printf ("%c", toupper(name[j + 1]));
                }
            }
            printf ("\n");
            break;
        }
    }
}