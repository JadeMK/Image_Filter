#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "bmp.h"

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
    if (fh.bfType != 0x4d42 || fh.bfOffBits != 54 || ih.biSize != 40 || ih.biBitCount != 24 || ih.biCompression != 0)
    {
        fclose(infile);
        fclose(outfile);
        printf("Supported BMP format: 24-bit uncompressed BMP 4.0");
        return 4;
    }

    return 0;
}

// Functions (R, G, B)