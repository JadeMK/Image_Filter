#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

// Prototypes
void red(int height, int width, RGB img[height][width]);
//void green(int height, int width, RGB img[height][width]);
//void blue(int height, int width, RGB img[height][width]);

int main(int argc, char *argv[]) {

    // Check command validity
    char *filters = "rgb";
    char *choice = argv[1];
    if (argc != 4 || strlen(choice) != 1 || strchr(filters, *choice) == NULL)
    {
        printf("Usage: ./filter [r/g/b] infile.bmp outfile.bmp\n");
        return 1;
    }

    // Received file names
    char *in_name = argv[2];
    char *out_name = argv[3];

    // Open input image & output file
    FILE *infile = fopen(in_name, "r");
    if (infile == NULL)
    {
        printf("Could not process. Check your infile.\n");
        return 2;
    }
    FILE *outfile = fopen(out_name, "w");
    if (outfile == NULL)
    {
        fclose(infile);
        printf("Could not process. Check your outfile.\n");
        return 3;
    }

    // Check BMP file header and info header
    FILEHEADER fh;
    fread(&fh, sizeof(FILEHEADER), 1, infile);
    INFOHEADER ih;
    fread(&ih, sizeof(INFOHEADER), 1, infile);
    // Check BMP format - implementation from Harvard's CS50 course - pset 4
    if (fh.bfType != 0x4d42 || fh.bfOffBits != 54 || ih.biSize != 40 || ih.biBitCount != 24 || ih.biCompression != 0)
    {
        fclose(infile);
        fclose(outfile);
        printf("Supported BMP format: 24-bit uncompressed BMP 4.0");
        return 4;
    }

    // Memory allocation for the image
    int height = abs(ih.biHeight);
    int width = ih.biWidth;
    RGB (*img)[width] = calloc(height, width * sizeof(RGB));
    if (img == NULL)
    {
        printf("Could not process. Not enough memory.\n");
        fclose(infile);
        fclose(outfile);
        return 5;
    }

    // Padding implementation from Harvard's CS50 course - pset 4
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;

    // Iterate through the input image - rows
    for (int i = 0; i < height; i++)
    {
        fread(img[i], sizeof(RGB), width, infile);
        fseek(infile, padding, SEEK_CUR);
    }

    // Choose filter WIP
    switch (*choice) {
        case 'r':
            red(height, width, img);
            break;

//        case 'g':
//            green(height, width, img);
//            break;
//
//        case 'b':
//            blue(height, width, img);
//            break;
    }

    // Write output values on outfile.bmp
    fwrite(&fh, sizeof(FILEHEADER), 1, outfile);
    fwrite(&ih, sizeof(INFOHEADER), 1, outfile);

    return 0;
}

// Functions (R, G, B)
void red(int height, int width, RGB img[height][width])
{
    // Iterate through the rows
    for (int i = 0; i < height; i++)
    {
        // Replace each pixel with a new value
        for (int j = 0; j < width; j++)
        {
            // Evaluate values
            float new_grey, check_gb;
            check_gb = (img[i][j].rgbBlue + img[i][j].rgbGreen) / 2.0;
            if (img[i][j].rgbRed - check_gb > 75)
            {
                // Replace
            }

        }
    }
    return;
}
