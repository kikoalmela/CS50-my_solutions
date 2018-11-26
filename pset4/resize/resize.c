/**
 * Resize a BMP
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        return 1;
    }

    // times to resize
    int n = atoi(argv[1]);

    if (n < 1 || n > 100)
    {
        fprintf(stderr, "Usage: n must be a positive integer less than or equal to 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // padding before resize
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // new width
    bi.biWidth *= n;

    // new height
    bi.biHeight *= n;

    // new padding
    int newPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // change image size (include padding)
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newPadding) * abs(bi.biHeight);

    // change file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) +sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight)/n; i < biHeight; i++)
    {
        // temporary storage
        RGBTRIPLE triple;

        // copy each row n-1 times
        for (int t = 1; t < n; t++)
        {
             // iterate over pixels in infile scanline
            for (int j = 0, width = (bi.biWidth/n); j < width; j++)
            {
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write n times RGB triple to outfile
                for (int p = 0; p < n; p++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // add padding
            for (int k = 0; k < newPadding; k++)
            {
                fputc(0x00, outptr);
            }

            // send infile cursor back
            fseek(inptr, -(sizeof(RGBTRIPLE) * bi.biWidth/n), SEEK_CUR);
        }
        // recopy the row once more
            for (int j = 0, width = (bi.biWidth/n); j < width; j++)
            {
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int p = 0; p < n; p++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

        // add padding
        for (int k = 0; k < newPadding; k++)
        {
            fputc(0x00, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
