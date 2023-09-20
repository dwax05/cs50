from cs50 import get_int

height = 0
while (height < 1 or height > 8):
    height = get_int("Height: ")

blankspaces = height
hashes = 0
for i in range(height):
    blankspaces -= 1
    hashes += 1
    print(" " * blankspaces, end="")
    print("#" * hashes, end="")
    print("")