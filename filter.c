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

    return 0;
}

// Functions (R, G, B)