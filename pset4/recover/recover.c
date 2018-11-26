#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // open file
    FILE *rawFile = fopen(argv[1], "r");
    if (rawFile == NULL)
    {
        fprintf(stderr, "File can't be opened\n");
        return 2;
    }

    // initialize buffer
    unsigned char buffer[512];

    // keep track of found JPEGs
    int jpgCount = 0;

    // initialize filename
    char filename[8];

    // initialize output file
    FILE *img = NULL;

    // read 512 bytes into a buffer
    // repeat until end of card (while fread() returns the number of blocks asked for)
    while (fread(&buffer, 512, 1, rawFile))
    {
        // look for start of a new JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if it's a new JPEG header
            if (img == NULL)
            {
                // create new JPEG file
                // name file
                sprintf(filename, "%03i.jpg", jpgCount);

                // open file
                img = fopen(filename, "w");

                // write buffer to file
                fwrite(&buffer, 512, 1, img);
            }
            // if file is still open
            else
            {
                // close actual file
                fclose(img);

                // increment counter
                jpgCount++;

                // name new file
                sprintf(filename, "%03i.jpg", jpgCount);

                // open new file
                img = fopen(filename, "w");

                // write buffer to file
                fwrite(&buffer, 512, 1, img);
            }
        }
        else
        {
            // if there is a file already open
            if (img != NULL)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
    }
    // close any remaining files
    fclose(rawFile);
    fclose(img);

    // success
    return 0;

}