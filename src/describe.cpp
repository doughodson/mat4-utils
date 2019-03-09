
//-------------------------------------------------------
// print contents of matlab version 4 header file
//-------------------------------------------------------

#include <iostream>
#include <cstdint>
#include <bitset>

#include <stdio.h>

#include "utils.hpp"

int main()
{
   MAT4Header header{};

   std::cout << "size of int     : " << sizeof(int)     << std::endl;
   std::cout << "size of int32_t : " << sizeof(int32_t) << std::endl;
   std::cout << "size of long    : " << sizeof(long)    << std::endl;

   FILE* fp = fopen("test.mat", "r");
   if (fp != NULL) {
      fread(&header, sizeof(MAT4Header), 1, fp);

      std::cout << "type    (hex) : 0x" << std::hex << header.type      << std::endl;
      std::cout << "type    (bin) : "   << std::bitset<32>(header.type) << std::endl;
      std::cout << "mrows   (dec) : "   << std::dec << header.mrows     << std::endl;
      std::cout << "ncols   (dec) : "   << std::dec << header.ncols     << std::endl;
      std::cout << "imagf   (dec) : "   << std::dec << header.imagf     << std::endl;
      std::cout << "namelen (dec) : "   << std::dec << header.namelen   << std::endl;

   } else {
      printf("File could not be opened.\n");
   }

   fclose(fp);
   return 0;
}
