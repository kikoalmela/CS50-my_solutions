import cs50

while True:
    # prompt user for height
    print("Height: ", end = "")
    height = cs50.get_int()
    if height > 0 and height <= 23:
        break

for row in range(1, height + 1):
    # print spaces
    print(" " * (height - row), end = "")
    # print hashes
    print("#" * row, end = "")
    # print gap (2 spaces)
    print("  ", end = "")
    #print hashes
    print("#" * row)