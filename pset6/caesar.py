import cs50
import sys

def main():

    # Check that user passed one command-line argument
    if len(sys.argv) != 2:
        print("Please pass the key as unique command-line argument")
        exit()
    else:
        # Get the key and convert it to an integer
        k = int(sys.argv[1])

        # Prompt for plain text to the user
        print("plaintext:", end=" ")
        p = cs50.get_string()
        # cipher text
        ciphertext = []

        # Cipher plaintext character by key
        for c in p:
            if c.isalpha():
                ciphertext.append(caesar(c, k))
            else:
                ciphertext.append(c)

        # print ciphertext
        print("ciphertext: " + "".join(ciphertext))

# caesar cipher preserving key function
def caesar (c, k):
    if c.isupper():
        return chr(((ord(c) - 65 + k) % 26) + 65)
    else:
        return chr(((ord(c) - 97 + k) % 26) + 97)

if __name__ == "__main__":
    main()