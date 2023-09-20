#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while(start < 9);

    //TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while(end < start);

    //TODO: Calculate the number uf years until we reach threshold
    int years = 0;
    int current = start;
    while(current < end)
    {
        current += (current/3) - (current/4);
        years++;
    }

    //TODO: Print number of years
    printf("Years: %i\n", years);
}
