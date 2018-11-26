import cs50


while True:
    # prompt user for cc number
    print("cc number: ", end="")
    cc_number = cs50.get_int()
    if cc_number > 0:
        break

checksum = 0
length = 0

# Starting with second-to-last digit, multiply every other digit by 2
i = 10
while i < cc_number:
    length += 1
    digit = (cc_number // i) % 10
    digit *= 2
    if digit < 10:
        checksum += digit;
    else:
        digit1 = digit // 10
        digit2 = digit % 10
        checksum += digit1 + digit2
    i *= 100

# Add to the sum the other digits that weren't multiplied by 2
i = 1
while i < cc_number:
    length += 1
    otherDigit = (cc_number // i) % 10
    checksum += otherDigit
    i *= 100

# Valitade checksum. If last digit is not 0, number is invalid
if checksum % 10 != 0:
    print("INVALID!")

#Validate number's length and company's identifier
else:
    firstDigit = cc_number // pow(10, length - 1)
    first2Digits = cc_number // pow(10, length - 2)

    if length == 15 and first2Digits in (34, 37):
        print("AMEX")

    elif length == 16 and first2Digits in range(51, 56):
        print("MASTERCARD")

    elif length in (13, 16) and firstDigit == 4:
        print("VISA")