# Problem Set 2: Crypto

1. Infer a user’s initials from their name with `initials.c`.

2. Choose two adventures:

   - Implement Caesar’s cipher.

   - Implement Vigenère’s cipher.

   - Crack passwords.

## Initials

Implement a program that, given a person’s name, prints a person’s initials, per the below.

```sh
$ ./initials
Regulus Arcturus Black
RAB
```
### Specification

Design and implement a program, `initials`, that, given a person’s name, prints a person’s initials.

- Implement your program in a file called `initials.c` in a directory called `initials`.

- Your program should prompt a user for their name using `get_string` to obtain their name as a `string`.

- You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus spaces. You don’t need to worry about names like `Joseph Gordon-Levitt`, `Conan O’Brien`, or `David J. Malan`!

- But the user’s input might be sloppy, in which case there might be one or more spaces at the start and/or end of the user’s input or even multiple spaces in a row.

- Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (`\n`).

## Caesar

Implement a program that encrypts messages using Caesar’s cipher, per the below.

```sh
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

### Specification

Design and implement a program, `caesar`, that encrypts messages using Caesar’s cipher.

- Implement your program in a file called `caesar.c` in a directory called `caesar`.

- Your program must accept a single command-line argument, a non-negative integer. Let’s call it k for the sake of discussion.

- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tends to signify an error) immediately.

- You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., `1`). No need to check that it’s indeed numeric.

- Do not assume that k will be less than or equal to 26. Your program should work for all non-negative integral values of *k* less than 2^31 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for *k* that’s too big or almost too big to fit in an `int`. (Recall that an `int` can overflow.) But, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if *k* is 27, `A` should not become `[` even though `[` is 27 positions away from `A` in ASCII, per asciichart.com; `A` should become `B`, since `B` is 27 positions away from `A`, provided you wrap around from `Z` to `A`.

- Your program must output `plaintext`: (without a newline) and then prompt the user for a `string` of plaintext (using `get_string`).

- Your program must output `ciphertext`: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by *k* positions; non-alphabetical characters should be outputted unchanged.

- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.

- After outputting ciphertext, you should print a newline. Your program should then exit by returning `0` from main.

## Crack

Implement a program that cracks passwords, per the below.

```sh
$ ./crack 50fkUxYHbnXGw
rofl
```

### Specification

Design and implement a program, `crack`, that cracks passwords.

- Implement your program in a file called `crack.c` in a directory called `crack`.

- Your program should accept a single command-line argument: a hashed password.

- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with `main` returning `1` (thereby signifying an error).

- Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by `\n`, nothing more, nothing less, with `main` returning `0`.

- Assume that each password has been hashed with C’s DES-based (not MD5-based) `crypt` function.

- Assume that each password is no longer than (gasp) four characters

- Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).