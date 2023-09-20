#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Collect arguments
    if (argc != 2){
        printf("usage: recover <>");
        exit(1);
    }

    char* memCard = argv[1];

    // Open card 
    FILE *inptr = fopen(memCard, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", memCard);
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *file_ptr = NULL;
    char filename[8];

    while (fread(&buffer, 512, 1, inptr) == 1)
        {
            // If start of a new JPEG (0xff 0xd8 0xff 0xe*):
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // If not first JPEG, close previous
                if (!(count == 0))
                {
                    fclose(file_ptr);
                }                // Initialise file
                sprintf(filename, "%03i.jpg", count);
                file_ptr = fopen(filename, "w");
                count++;
            }            // If JPEG has been found, write to file
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, file_ptr);
            }
        }        
    fclose(inptr);
    fclose(file_ptr);

    return 0;
}
