#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// Prototype Functions
void caesarCode(char *, int);

int main(int argc, char *argv[])
{
    // If and for used to validate key prompted by the user
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Converts key from alpha to integer
    int key = atoi(argv[1]);
    
    char *plaintext = get_string("Enter text to encrypt: ");
    caesarCode(plaintext, key);
}

// what does this do
void caesarCode(char *t, int k)
{
    printf("ciphertext: ");
    // Iterates through each letter of the text
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (isalpha(t[i]) != 0)
        {
            if (isupper(t[i]) != 0)
            {
                // Applies formula to ASCII uppercase letters
                printf("%c", ((t[i] - 'A' + k) % 26) + 'A');
            }
            else
            {
                printf("%c", ((t[i] - 'a' + k) % 26) + 'a');
            }
        }
        // Keeps all non-alphabetical characters
        else
        {
            printf("%c", t[i]);
        }
    }
    printf("\n");
}
