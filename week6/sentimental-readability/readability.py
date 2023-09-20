from cs50 import get_string

text = get_string("Enter text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1
    elif i.isspace():
        words += 1
    elif i == "." or i == "!" or i == "?":
        sentences += 1

l = letters/words * 100
s = sentences/words * 100
index = 0.0588 * l - 0.296 * s - 15.8
index = round(index)

if index >= 16:
    print("Grade 16+\n")
elif index <= 1:
    print("Before Grade 1\n")
elif True:
    print(f"Grade {index}")