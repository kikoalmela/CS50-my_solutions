#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Accept a single command-line argument
int main(int argc, string argv[])
{
    // Check for 1 command-line argument
    if (argc != 2)
    {
        printf ("A hashed password is required as single command-line argument\n");
        return 1;
    }

    // Get the hashed password
    string hp = argv[1];

    // Declare a string with maximum 4 chars for the searched password
    char p[5];
    string pass = p;

    // Iterate through chars of pass with all characters
    for (int i = 65; i < 123 ; i++)
    {
        // Only test alphabetical character (uppercase and lowercase)
        if (i < 91 || i > 96)
        {
            p[0] = i;
            // Check if the result of passing the actual pass to crypt() matches the give hashed password
            if (!strcmp(hp, crypt(pass, "50")))
            {
                // If it matches, print the password and quit
                printf ("%s\n", pass);
                return 0;
            }
            else
            {
                // Repeat the process whit each of the characters of the maximum total
                for (int j = 65; j < 123 ; j++)
                {
                    if (j < 91 || j > 96)
                    {
                        p[1] = j;
                        if (!strcmp(hp, crypt(pass, "50")))
                        {
                            printf ("%s\n", pass);
                            return 0;
                        }
                        else
                        {
                            for (int k = 65; k < 123 ; k++)
                            {
                                if (k < 91 || k > 96)
                                {
                                    p[2] = k;
                                    if (!strcmp(hp, crypt(pass, "50")))
                                    {
                                        printf ("%s\n", pass);
                                        return 0;
                                    }
                                    else
                                    {
                                        for (int l = 65; l < 123 ; l++)
                                        {
                                            if (l < 91 || l > 96)
                                            {
                                                p[3] = l;
                                                if (!strcmp(hp, crypt(pass, "50")))
                                                {
                                                    printf ("%s\n", pass);
                                                    return 0;
                                                }
                                            }
                                        }
                                        // Reset this char before the next iteration of the previous char (to prevent the case of less than four chars password)
                                        p[3] = 0;
                                    }
                                }
                            }
                            p[2] = 0;
                        }
                    }
                }
                p[1] = 0;
            }
        }
    }
    printf("\n");
}