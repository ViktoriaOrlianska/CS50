#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


// Definition of byte size and file name size
#define BYTESIZE 512
#define FILESIZE 8

// Type definition of BYTE
typedef uint8_t BYTE;

// Declaration of functions
bool checkInput(int a, char *b[]);
void bufferRaw(char *c[]);

// Main function
int main(int argc, char *argv[])
{
    // Sends the users inputs to a function and returns an error if the inputs are not valid
    if (!checkInput(argc, &argv[1]))
    {
        return 1;
    }
    // Buffers the raw file and creates a new jpeg file for each jpeg file found in the memory card
    bufferRaw(&argv[1]);
    return 0;
}

// Checks if the input and the file type is correct in the command line, and if the fild could be read
bool checkInput(int a, char *b[])
{
    // If the user entered more than 2 inputs in the command line
    if (a != 2)
    {
        printf("Correct use : ./recover file.raw\n");
        return false;
    }

    // Opening the file to check if it's readable, if not returns an error
    char *infile = *b;
    FILE *inptr = fopen(infile, "r");
    if (!inptr)
    {
        printf("Couldn't read the file.\n");
        return false;
    }
    fclose(inptr);
    return true;
}

// Only function that buffers the raw memory file and recovers jpegs files
void bufferRaw(char *c[])
{
    int filecount = 0;
    int foundFirst = 0;
    BYTE buffer[BYTESIZE];
    char *infile = *c;
    FILE *inptr = fopen(infile, "r");
    FILE *outptr;

    // Reads the memory card until it's finished
    while (fread(buffer, BYTESIZE, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char outfile[FILESIZE];
            if (foundFirst == 0)
            {
                foundFirst = 1;
                sprintf(outfile, "%03i.jpg", filecount);
                outptr = fopen(outfile, "w");
                if (outptr == NULL)
                {
                    fclose(outptr);
                    printf("Error while creating jpeg.");
                    exit(1);
                }
                fwrite(buffer, BYTESIZE, 1, outptr);
            }
            else
            {
                fclose(outptr);
                filecount += 1;
                sprintf(outfile, "%03i.jpg", filecount);
                outptr = fopen(outfile, "w");
                fwrite(buffer, BYTESIZE, 1, outptr);
            }
        }
        else if (foundFirst == 1)
        {
            fwrite(buffer, BYTESIZE, 1, outptr);
        }
    }
    fclose(outptr);
    fclose(inptr);
}
