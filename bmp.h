#include <stdint.h>

// bmp.h contains a BMP related implementation from Harvard's CS50 course - pset 4

typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} __attribute__((__packed__))
FILEHEADER;

typedef struct
{
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} __attribute__((__packed__))
INFOHEADER;

typedef struct
{
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
} __attribute__((__packed__))
RGB;
