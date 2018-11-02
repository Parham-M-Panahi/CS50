// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember n
    int factor = atoi(argv[1]);

    if (factor > 100 || factor < 1)
    {
	fprintf(stderr, "n must be a natural number less than 100\n");
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

    // TODO:
    LONG oldWidth = bi.biWidth;
    LONG oldHeight = bi.biHeight;

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biWidth = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;

    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + new_padding) * abs(bi.biHeight);

    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    int seekBack = -1 * (int)sizeof(RGBTRIPLE) * oldWidth;


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
	for (int z = 0; z < factor; z++)
	{
		// iterate over pixels in scanline
		for (int j = 0; j < oldWidth; j++)
		{
		    // temporary storage
		    RGBTRIPLE triple;

		    // read RGB triple from infile
		    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

		    // write RGB triple to outfile
		    for (int w = 0; w < factor; w++)
		        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
		}
		
		if (z == factor - 1)
		    fseek(inptr, padding, SEEK_CUR);
		else
		    fseek(inptr, seekBack, SEEK_CUR);

		// then add it back (to demonstrate how)
		for (int k = 0; k < new_padding; k++)
		{
		    fputc(0x00, outptr);
		}
	}
     }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
