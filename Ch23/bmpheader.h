// bmpheader.h
#ifndef _BMPHEADER_H_
#define _BMPHEADER_H_
#include <stdint.h>
// tell compiler not to add space between the attributes
#pragma pack(1)     
// A BMP file has a header (54 bytes) and data

typedef struct 
{
  uint16_t type;              // Magic identifier
  uint32_t size;              // File size in bytes
  uint16_t reserved1;         // Not used
  uint16_t reserved2;         // Not used
  uint32_t offset;            // 
  uint32_t header_size;       // Header size in bytes
  uint32_t width;             // Width of the image
  uint32_t height;            // Height of image
  uint16_t planes;            // Number of color planes
  uint16_t bits;              // Bits per pixel
  uint32_t compression;       // Compression type
  uint32_t imagesize;         // Image size in bytes
  uint32_t xresolution;       // Pixels per meter
  uint32_t yresolution;       // Pixels per meter
  uint32_t ncolours;          // Number of colors  
  uint32_t importantcolours;  // Important colors

} BMP_Header;
#endif 
