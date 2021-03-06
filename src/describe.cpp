
//-------------------------------------------------------
// print contents of matlab version 4 header file
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdint>
#include <bitset>

#include "utils.hpp"
#include "swap_bytes.hpp"

int main(int argc, char* argv[])
{
   std::cout << "Num of args : " << argc << std::endl;

   std::cout << "argv[0] : " << argv[0] << std::endl;
   if (argc > 1) {
      std::cout << "argv[1] : " << argv[1] << std::endl;
   } else {
      std::cout << "describe <filename>\n";
      std::exit(0);
   }

   std::ifstream ifs;
   ifs.open(argv[1], std::ifstream::binary);
   if (ifs.fail()) {
      std::cout << "can't read <filename>\n";
   }

   MAT4Header header{};
   ifs.read(reinterpret_cast<char*>(&header.mopt), sizeof(header.mopt));
   ifs.read(reinterpret_cast<char*>(&header.nrows), sizeof(header.nrows));
   ifs.read(reinterpret_cast<char*>(&header.ncols), sizeof(header.ncols));
   ifs.read(reinterpret_cast<char*>(&header.imagf), sizeof(header.imagf));
   ifs.read(reinterpret_cast<char*>(&header.namelen), sizeof(header.namelen));

   bool swap{};
   if (header.mopt > 9999 || header.mopt < 0) {
      swap = true;
   }

   if (swap) {
      std::cout << "This data file was created on a big endian machine\n";
      swap_bytes<4>(&header.mopt);
      swap_bytes<4>(&header.nrows);
      swap_bytes<4>(&header.ncols);
      swap_bytes<4>(&header.imagf);
      swap_bytes<4>(&header.namelen);
   } else {
      std::cout << "This data file was created on a little endian machine\n";
   }

   std::cout << "mopt    (dec) : " << header.mopt    << std::endl;
   std::cout << "nrows   (dec) : " << header.nrows   << std::endl;
   std::cout << "ncols   (dec) : " << header.ncols   << std::endl;
   std::cout << "imagf   (dec) : " << header.imagf   << std::endl;
   std::cout << "namelen (dec) : " << header.namelen << std::endl;

   ifs.close();
   return 0;
}
