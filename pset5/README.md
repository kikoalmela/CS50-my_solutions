# Problem Set 5: Mispellings

1. Answer some questions about a spell checker.

2. Implement a spell checker.

## Questions
Open up questions.txt and answer each of the following questions in one or more sentences.

0. What is pneumonoultramicroscopicsilicovolcanoconiosis?

1. According to its man page, what does getrusage do?

2. Per that same man page, how many members are in a variable of type struct rusage?

3. Why do you think we pass before and after by reference (instead of by value) to calculate, even though we’re not changing their contents?

4. Explain as precisely as possible, in a paragraph or more, how main goes about reading words from a file. In other words, convince us that you indeed understand how that function’s for loop works.

5. Why do you think we used fgetc to read each word’s characters one at a time rather than use fscanf with a format string like "%s" to read whole words at a time? Put another way, what problems might arise by relying on fscanf alone?

6. Why do you think we declared the parameters for check and load as const (which means "constant")?

## Speller

Implement a program that spell-checks a file, per the below.

```
$ ./speller texts/austinpowers.txt
MISSPELLED WORDS

[...]
Bigglesworth
[...]
Virtucon
[...]
friggin'
[...]
trippy
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```

### Specification
Alright, the challenge now before you is to implement `load', `check', `size', and `unload' as efficiently as possible, in such a way that `TIME IN load', `TIME IN check', `TIME IN size', and `TIME IN unload' are all minimized. To be sure, it’s not obvious what it even means to be minimized, inasmuch as these benchmarks will certainly vary as you feed `speller` different values for `dictionary` and for `text`. But therein lies the challenge, if not the fun, of this problem. This problem is your chance to design. Although we invite you to minimize space, your ultimate enemy is time. But before you dive in, some specifications from us.

- You may not alter `speller.c`.

- You may alter `dictionary.c` (and, in fact, must in order to complete the implementations of `load`, `check`, `size`, and `unload`), but you may not alter the declarations of `load`, `check`, `size`, or `unload`.

- You may alter `dictionary.h`, but you may not alter the declarations of `load`, `check`, `size`, or `unload`.

- You may alter `Makefile`.

- You may add functions to `dictionary.c` or to files of your own creation so long as all of your code compiles via `make`.

- Your implementation of `check` must be case-insensitive. In other words, if `foo` is in dictionary, then `check` should return true given any capitalization thereof; none of `foo`, `foO`, `fOo`, `fOO`, `fOO`, `Foo`, `FoO`, `FOo`, and `FOO` should be considered misspelled.

- Capitalization aside, your implementation of `check' should only return `true' for words actually in `dictionary'. Beware hard-coding common words (e.g., `the'), lest we pass your implementation a `dictionary' without those same words. Moreover, the only possessives allowed are those actually in `dictionary'. In other words, even if `foo' is in `dictionary', `check' should return `false' given `foo’s' if `foo’s' is not also in `dictionary'.

- You may assume that `check `will only be passed strings with alphabetical characters and/or apostrophes.

- You may assume that any `dictionary `passed to your program will be structured exactly like ours, lexicographically sorted from top to bottom with one word per line, each of which ends with `\n`. You may also assume that `dictionary `will contain at least one word, that no word will be longer than `LENGTH `(a constant defined in `dictionary.h`) characters, that no word will appear more than once, and that each word will contain only lowercase alphabetical characters and possibly apostrophes.

- Your spell checker may only `take` text and, optionally, `dictionary` as input. Although you might be inclined (particularly if among those more comfortable) to "pre-process" our default dictionary in order to derive an "ideal hash function" for it, you may not save the output of any such pre-processing to disk in order to load it back into memory on subsequent runs of your spell checker in order to gain an advantage.

- Your spell checker may not leak any memory.

- You may search for (good) hash functions online, so long as you cite the origin of any hash function you integrate into your own code.

Alright, ready to go?

1. Implement `load'.

2. Implement `check'.

3. Implement `size'.

4. Implement `unload'.

