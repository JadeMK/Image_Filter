#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
    FILE *outfile = fopen(out_name, "w");
    if (infile == NULL || outfile == NULL)
    {
        printf("Could not process.\n");
        return 2;
    }

    return 0;
}

// Functions (R, G, B)