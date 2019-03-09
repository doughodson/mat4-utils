
#ifndef __utils_HPP__
#define __utils_HPP__

#include <iosfwd>
#include <cstdint>

typedef struct {
   int32_t mopt;     // how it's stored
   int32_t nrows;    // number of rows
   int32_t ncols;    // number of columns
   int32_t imagf;    // imaginary flag
   int32_t namelen;  // length of variable name + 1
} MAT4Header;

int read_mat_file_header(std::istream& is, bool& swap, MAT4Header& header);

#endif
