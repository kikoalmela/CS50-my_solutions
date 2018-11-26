# Problem Set 3: Game of Fifteen

1. Search and sort some numbers.
2. Implement the Game of Fifteen.

## Find

Implement a program that finds a number among numbers, per the below.

```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

### Specification
Complete the implementation of `find` by completing the implementation of `search` and `sort` in `helpers.c`.

### `search`
- Your implementation must return `false` immediately if `n` is non-positive.

- Your implementation must return `true` if `value` is in `values` and false if `value` is not in `values`.

- The running time of your implementation must be in O(log n).

- You may not alter the function’s declaration. Its prototype must remain:
```c
  bool search(int value, int values[], int n);
```

### `sort`
- Your implementation must sort, from smallest to largest, the array of numbers that it’s passed.

- Assume that each of the array’s numbers will be non-negative and less than 65,536. But the array might contain duplicates.

- The running time of your implementation must be in O(n), where n is the array’s size. Yes, linear! Keep in mind that 65,536 is a constant.

- You may not alter the function’s declaration. Its prototype must remain:
```c
void sort(int values[], int n);
```

## Game of Fifteen

Implement the Game of Fifteen, per the below.

```
$ ./fifteen 3
WELCOME TO GAME OF FIFTEEN

8  7  6

5  4  3

2  1  _

Tile to move:
```

The Game of Fifteen is a puzzle played on a square, two-dimensional board with numbered tiles that slide. The goal of this puzzle is to arrange the board’s tiles from smallest to largest, left to right, top to bottom, with an empty space in board’s bottom-right corner, as in the below.

Sliding any tile that borders the board’s empty space in that space constitutes a "move." Although the configuration above depicts a game already won, notice how the tile numbered 12 or the tile numbered 15 could be slid into the empty space. Tiles may not be moved diagonally, though, or forcibly removed from the board.

Although other configurations are possible, we shall assume that this game begins with the board’s tiles in reverse order, from largest to smallest, left to right, top to bottom, with an empty space in the board’s bottom-right corner. **If, however, and only if the board contains an odd number of tiles (i.e., the height and width of the board are even), the positions of tiles numbered 1 and 2 must be swapped, as in the below**. The puzzle is solvable from this configuration.

### Specification
Implement the Game of Fifteen, per the comments `in fifteen.c`.

- Implement `init`.

- Implement `draw`.

- Implement `move`.

- Implement `won`.

