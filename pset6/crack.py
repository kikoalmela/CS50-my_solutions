import sys
import crypt

def main():

    # Check for 1 command-line argument
    if len(sys.argv) != 2:
        print("Usage: python crack.py hashedPass")
        exit()

    # hashed password
    hp = sys.argv[1]
    salt="50"
    # list of ascii codes for alpha characters, lower and uppercase
    alphaChars = list(range(65, 91)) + list(range(97, 123))


    for i in alphaChars:
        p = chr(i)
        checkPass(p, salt, hp)

        for j in alphaChars:
            pa = p + chr(j)
            checkPass(pa, salt, hp)

            for k in alphaChars:
                pas = pa + chr(k)
                checkPass(pas, salt, hp)

                for l in alphaChars:
                    passw = pas + chr(l)
                    checkPass(passw, salt, hp)

    print("error")
    return 0

def checkPass(word, salt, hp):
    hashedWord = crypt.crypt(word, salt)
    if hashedWord == hp:
        print(word)
        sys.exit()

if __name__ == "__main__":
    main()