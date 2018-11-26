#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Get the key from command-line argument
int main(int argc, string argv[])
{
    // Check that user passed one command-line argument
    if (argc != 2)
    {
        printf("Please pass one, and only one, command-line argument that should be a non-negative integer.\n");
        return 1;
    }

     // Get the key and convert it to an integer
    int k = atoi(argv[1]);

    // Prompt for plain text to the user
    printf ("plaintext: ");
    string p = get_string();
    string c = p;

    // for each character in the plaintext string
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // if alphabetic
        if (isalpha(p[i]))
        {
            // Preserve case
            // Cipher plaintext character by key
            if (isupper(p[i]))
            {
                c[i] = ((p[i] - 65 + k) % 26) + 65;
            }

            if (islower(p[i]))
            {
                c[i] = ((p[i] - 97 + k) % 26) + 97;
            }
        }
    }
    // Print ciphertext
    printf("ciphertext: %s\n", c);
}