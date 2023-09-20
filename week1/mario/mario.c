#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height>8||height<1);

    for(int i=0;i<height;i++)
    {
       for(int d= height-1; d>i;d = d-1)
            {
                printf(" ");
            }
       for(int h=-1;h<i;h++)
        {

            printf("#");
        }
        printf("\n");   
    }
}
