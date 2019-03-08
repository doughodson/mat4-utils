
#include <iostream>
#include <filesystem>
#include <string>
#include <cstdint>

#include <stdio.h>

namespace fs = std::filesystem;
//namespace fs = std::experimental::filesystem::v1;   // visual studio

typedef struct {
   int32_t type;     // type of data - how it's stored
   int32_t mrows;    // # of rows
   int32_t ncols;    // # of columns
   int32_t imagf;    // imaginary value
   int32_t namelen;  // length of variable name + 1
} MAT4Header;

int main(int argc, char** argv)
{
   std::cout << "Num of args : " << argc << std::endl;

   std::cout << "argv[0] : " << argv[0] << std::endl;
   if (argc > 1) {
      std::cout << "argv[1] : " << argv[1] << std::endl;
      fs::path filename{argv[1]};

      std::cout << "exists() = " << fs::exists(filename) << "\n"
           << "root_name() = " << filename.root_name() << "\n"
           << "root_path() = " << filename.root_path() << "\n"
           << "relative_path() = " << filename.relative_path() << "\n"
           << "parent_path() = " << filename.parent_path() << "\n"
           << "filename() = " << filename.filename() << "\n"
           << "stem() = " << filename.stem() << "\n"
           << "extension() = " << filename.extension() << "\n";
   }

   FILE* fp{fopen("test.mat", "wb")};
   if (fp) {

      // define and write matrix header information
      MAT4Header x{1000,1,1,1,2};
      fwrite(&x, sizeof(MAT4Header), 1, fp);

      // variable name
      const char* pname{"x"};
      fwrite(pname, sizeof(char), x.namelen, fp);

      // matrix data
      const double real_data{1.0};
      const double imag_data{2.0};
      const int mn{x.mrows * x.ncols};
      fwrite(&real_data, sizeof(double), mn, fp);          // write real value(s)
      if (x.imagf) {
         fwrite(&imag_data, sizeof(double), mn, fp);       // write imaginary value(s)
      }

   } else {
      std::cout << "File could not be opened.\n";
   }

   fclose(fp);
   return 0;
}
