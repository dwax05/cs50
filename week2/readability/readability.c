#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letter(string s);
int count_sentences(string s);
int count_words(string s);

int main(void)
{
    string s = get_string("Text: ");

    //count the letters, words, sentences
    int letters = count_letter(s);
    int sentences = count_sentences(s);
    int words = count_words(s);

    int index = round(0.0588 * (100.0 * letters/words) - 0.296 * (100.0 * sentences/words) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letter(string s)
{
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if(isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string s)
{
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if(s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int count_words(string s)
{
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if(s[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}
