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

    return 0;
}

// Functions (R, G, B)