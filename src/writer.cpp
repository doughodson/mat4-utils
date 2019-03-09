
//-------------------------------------------------------
// writes a valid matlab version 4 file
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdint>

#include "utils.hpp"

int main(int argc, char** argv)
{
   std::cout << "Num of args : " << argc << std::endl;

   std::cout << "argv[0] : " << argv[0] << std::endl;
   if (argc > 1) {
      std::cout << "argv[1] : " << argv[1] << std::endl;
   } else {
      std::cout << "writer <filename>\n";
      std::exit(0);
   }

   std::ofstream ofs;
   ofs.open(argv[1], std::ofstream::binary);
   if (ofs.fail()) {
      std::cout << "can't open <filename>\n";
   }

   // define and write matrix header information
   MAT4Header header{0000, 1, 1, 1, 2};

   ofs.write(reinterpret_cast<const char*>(&header.mopt), sizeof(header.mopt));
   ofs.write(reinterpret_cast<const char*>(&header.nrows), sizeof(header.nrows));
   ofs.write(reinterpret_cast<const char*>(&header.ncols), sizeof(header.ncols));
   ofs.write(reinterpret_cast<const char*>(&header.imagf), sizeof(header.imagf));
   ofs.write(reinterpret_cast<const char*>(&header.namelen), sizeof(header.namelen));

   // variable name
   const char* pname{"x"};
   ofs.write(pname, sizeof(char)+1);
   // matrix data
   const double real_data{1.0};
   const double imag_data{2.0};
   const int mn{header.nrows * header.ncols};
   ofs.write(reinterpret_cast<const char*>(&real_data), sizeof(double));
   if (header.imagf) {
      ofs.write(reinterpret_cast<const char*>(&imag_data), sizeof(double));
   }

   ofs.close();
   return 0;
}
