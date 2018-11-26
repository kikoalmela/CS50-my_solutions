#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for user input
    long long cc_number;
    int checksum = 0;
    int length = 0;

    do
    {
        printf ("Number: ");
        cc_number = get_long_long();
    }
    while (cc_number < 0);

    // Starting with second-to-last digit, multiply every other digit by 2
    // Add those products' digit together
    for (long long i = 10; i < cc_number; i *= 100)
    {
        length++;
        int digit = (cc_number / i) % 10;
        digit *= 2;
        if (digit < 10)
        {
            checksum += digit;
        }
        else
        {
            int digit2 = digit % 10;
            int digit1 = (digit - digit2) / 10;
            checksum += digit1 + digit2;
        }
    }

    // Add the sum to the sum or the digits that weren't multiplied by 2
    for (long long i = 1; i < cc_number; i *= 100)
    {
        length++;
        int otherDigit = (cc_number / i) % 10;
        checksum += otherDigit;

    }

    // Valitade checksum. If last digit is 0, number is valid
    if (checksum % 10 !=  0)
    {
        printf ("INVALID\n");
    }
    else // Validate number's length
        // Validate company's identifier
    {
        int oneDigit = cc_number / pow(10, length - 1);
        int twoDigits = cc_number / pow(10, length - 2);

        if (length == 15 && (twoDigits == 34 || twoDigits == 37))
        {
            printf ("AMEX\n");
        }
        else if (length == 16 && (twoDigits == 51 || twoDigits == 52 || twoDigits == 53 || twoDigits == 54 || twoDigits == 55))
        {
            printf ("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && oneDigit == 4)
        {
            printf ("VISA\n");
        }
    }
}